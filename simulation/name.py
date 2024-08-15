import requests as req
from bs4 import BeautifulSoup as soup

res = req.get('http://103.79.117.242/ru_profile/public/teacher/227/profiles')
ans = soup(res.content, 'html.parser')

for name in ans.find_all('p', {'class':'lead'}):
	print(name.strong.text)
