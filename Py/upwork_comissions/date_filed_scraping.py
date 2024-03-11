"""
This script is used to scrape the date filed from the upwork comissions link.
"""
import bs4
import requests

r = requests.get('https://search.sunbiz.org/Inquiry/CorporationSearch/ByName')
r.raise_for_status()

soup = bs4.BeautifulSoup(r.text, 'html.parser')

print(soup.prettify())