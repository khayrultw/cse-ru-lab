
import requests as req
from bs4 import BeautifulSoup as soup

res = req.get('http://www.ru.ac.bd/?page_id=843')
ans = soup(res.content, 'html.parser')

ans = ans.find('div', {'class':'box_feat_home'})


ans = ans.find('table')

for v in ans.find_all('tr'):
	i = 0
	
	for u in v.find_all('td'):
		i = i+1
		if i == 2 or i == 3:
			print(u.text)
		

