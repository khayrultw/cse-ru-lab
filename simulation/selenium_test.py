from selenium import webdriver
from selenium.webdriver.common.keys import Keys
import time

driver = webdriver.Chrome()
driver.get("http://103.79.117.242/ru_profile/public/teacher/227/profiles")

i = 1
try:
	while True:
		elem = driver.find_element_by_xpath("/html/body/div/div/div/div/div/table/tbody/tr["+str(i)+"]/td/div/div[2]/p[1]")
		print(elem.text)
		print("\n")
		i = i+1
except:
	pass
	
time.sleep(3)
driver.close()
