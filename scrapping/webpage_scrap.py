from bs4 import BeautifulSoup
from selenium import webdriver
import openpyxl

wb = openpyxl.Workbook()
ws1 = wb.active
ws1.append(["Name"])


driver = webdriver.Chrome('./chromedriver')

url = "https://seomal.com/map/1"

driver.get(url)
req = driver.page_source
soup = BeautifulSoup(req, 'html.parser')
for i in range(1, 164):
    articles = soup.select_one(f'#root > div > div > div > div > div > div > div > ul > div:nth-child({i})> div > span').get_text()
    # need = articles.text
    ws1.append([articles])



wb.save(filename='seomal.xlsx')

driver.quit()
