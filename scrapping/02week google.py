from bs4 import BeautifulSoup
from selenium import webdriver
import openpyxl

driver = webdriver.Chrome('./chromedriver')
driver.implicitly_wait(10)
url = "https://www.google.co.kr/search?q=%22company%22+and+%22environment%22&biw=1432&bih=1015&tbs=cdr%3A1%2Ccd_min%3A1%2F1%2F2020%2Ccd_max%3A12%2F31%2F2020&tbm=nws&sxsrf=AOaemvK9V3qaNB9weLBGXYMu1Y3-ZshcgA%3A1632219798197&ei=lrJJYZm5C8Sc-AafvYzAAQ&oq=%22company%22+and+%22environment%22&gs_l=psy-ab.3..0i7i30k1l3j0i30k1j0i8i7i30k1j0i8i30k1l5.5157.7046.0.7212.10.10.0.0.0.0.147.1249.0j9.9.0....0...1c.1.64.psy-ab..1.9.1249...0i7i10i30k1j0i7i10i30i19k1j0i7i30i19k1.0.a0gZOeuxYas"

driver.get(url)
req = driver.page_source
soup = BeautifulSoup(req, 'html.parser')

articles = soup.select('#rso > div')
wb = openpyxl.Workbook()
ws1 = wb.active
ws1.append(["Name",])

for article in articles:
    title = article.select_one('g-card > div > div > a > div > div.iRPxbe > div.mCBkyc.JQe2Ld.nDgy9d').text
    ws1.append([title],)
# title = article.select_one('div > div > a').text 이렇게 경로를 잘 못 찾으면 프린트가 안된다

ws1.column_dimensions['A'].width = 50 # A열
ws1.column_dimensions['B'].width = 20 # B열
wb.save(filename='colaa test.xlsx')

driver.quit()

#rso > div:nth-child(1) > g-card > div > div > a > div > div.iRPxbe > div.mCBkyc.JQe2Ld.nDgy9d
#rso > div:nth-child(2) > g-card > div > div > a > div > div.iRPxbe > div.mCBkyc.JQe2Ld.nDgy9d
#rso