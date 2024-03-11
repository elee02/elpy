import bs4
import requests

r = requests.get('https://beautiful-soup-4.readthedocs.io/en/latest/')
r.raise_for_status()

soup = bs4.BeautifulSoup(r.text, 'html.parser')

print(soup.prettify())