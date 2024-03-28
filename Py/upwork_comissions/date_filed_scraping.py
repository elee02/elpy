import pandas as pd
import bs4
import requests
import concurrent.futures

names_and_links = []
keyword = "paradise"
header_link = 'https://search.sunbiz.org/'
r = requests.get(f'{header_link}Inquiry/CorporationSearch/SearchResults/EntityName/{keyword}/Page1?searchNameOrder={keyword.upper()}')
r.raise_for_status()

soup = bs4.BeautifulSoup(r.text, 'html.parser')

print(soup.prettify())

###########################

while True:
    search_results = soup.find_all(attrs = {'id': 'search-results'})
    nali = search_results[0].find_all('tr')
    nali = [[nali[i].td.text, nali[i].a['href']] for i in range(1, len(nali))]

    print(nali, len(nali), sep = '\n')

    ###########################

    def check_name(keyword, namelink_list):
        length = len(namelink_list)
        status = []
        for idx in range(length):
            if keyword.lower() in namelink_list[idx][0].lower():
                status.append((namelink_list[idx][0], True))
            else:
                status.append((namelink_list[idx][0], False))
        return status
    checked_list = check_name(keyword, nali)

    ###########################

    checked_dt = pd.DataFrame(checked_list, columns = ['Name', 'Match'])
    print(checked_dt)

    ###########################

    t_num = checked_dt[checked_dt['Match'] == True].count()

    ###########################

    if (t_num[0]/len(checked_dt['Match'])) > 0.65:
        names_and_links.extend(nali)
        print('Next Page')
    else:
        # names_and_links.extend(nali)
        break
        print('Last Page')

    print(names_and_links, len(names_and_links), sep = '\n')

    ###########################

    next_button = soup.find_all('div', attrs = {'class': 'navigationBarPaging'})
    next_button_link = next_button[0].find_all('a')[-1]['href'].lstrip('/')
    print('The Next Link:',next_button_link)

    ###########################

    r = requests.get(header_link + next_button_link)
    r.raise_for_status()

    soup = bs4.BeautifulSoup(r.text, 'html.parser')


    print(soup.prettify())

###########################

print(pd.DataFrame(names_and_links, columns= ['Name', 'Link']))

###########################

def get_date_filed(name_and_link):
    r = requests.get(header_link + name_and_link[1])
    r.raise_for_status()
    comps = bs4.BeautifulSoup(r.text, 'html.parser')

    date_filed = comps.find_all('label', attrs = {'for': 'Detail_FileDate'})
    date_filed = date_filed[0].next_sibling.text
    name_and_link.append(date_filed)

with concurrent.futures.ThreadPoolExecutor() as executor:
    executor.map(get_date_filed, names_and_links)

###########################
    
namelink_dt = pd.DataFrame(names_and_links, columns = ['Name', 'Link', 'Date Filed'])

###########################

namelink_dt['Date Filed'] = pd.to_datetime(namelink_dt['Date Filed'])
print(namelink_dt['Date Filed'])
print(type(namelink_dt['Date Filed'][0]))

###########################

a_month_ago = pd.Timestamp.today() - pd.DateOffset(months = 1)
target_comps = namelink_dt[namelink_dt['Date Filed'] > a_month_ago].sort_values(by = 'Date Filed', ascending = False)
target_comps.to_csv(f'./{keyword}.csv', index = False)