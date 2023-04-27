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
for i in range(1, 190):
    articles = soup.select_one(f'#root > div > div > div > div > div > div > div > ul > div:nth-child({i})> div > span').get_text()
    # need >> articles.text
    ws1.append([articles])

# for i in range(1, 164):
#     selector = f'#root > div > div > div > div > div > div > div > ul > div:nth-child({i}) > div > span'
#     articles = soup.select_one(selector)
#     if articles:
#         articles_text = articles.get_text()
#         ws1.append([articles_text])
#     else:
#         print(f"No element found for selector: {selector}")


wb.save(filename='seomal_list.xlsx')

driver.quit()
