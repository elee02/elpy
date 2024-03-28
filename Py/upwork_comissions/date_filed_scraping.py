"""
Algorithm:

1. Search the field replacing keywords in the URL

2. Get all the names and URLs from the page and 
the coming pages until the name does not match

3. From each URL, get the date filed and add 
the list of names and urls

4. Sort the list by date filed

5. Remove the entries more than 30 days old

6. Print the list of names and URLs
"""

import bs4
import requests

name = "google"
r = requests.get(f'https://search.sunbiz.org/Inquiry/CorporationSearch/SearchResults/EntityName/{name}/Page1?searchNameOrder={name.upper()}')
r.raise_for_status()

soup = bs4.BeautifulSoup(r.text, 'html.parser')

print(soup.prettify())