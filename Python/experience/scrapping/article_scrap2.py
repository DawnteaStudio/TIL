
from bs4 import BeautifulSoup
from selenium import webdriver
import openpyxl
import time

driver = webdriver.Chrome('./chromedriver')
driver.implicitly_wait(10)
url = "https://www.google.com/search?q=intitle:government+and+intitle:company&rlz=1C5CHFA_enKR917KR917&sxsrf=AOaemvI6LHYfxY5hya945sglRkYUl6rSug:1632374238047&source=lnms&tbm=nws&sa=X&ved=2ahUKEwikh-X0q5TzAhVwyIsBHUq9B74Q_AUoA3oECAEQBQ&biw=1925&bih=1014&dpr=2"
# 뉴스 1페이지에서 링크는 직접 입력

driver.get(url)
req = driver.page_source
soup = BeautifulSoup(req, 'html.parser')
wb = openpyxl.Workbook()
ws1 = wb.active
ws1.append(["Name", "publisher"])

articles = soup.select('#rso > div')

links = soup.select('#xjs > table > tbody > tr > td.d6cvqb')
rlinks = links[1]
reallinks = rlinks.find('a')["href"]
onlynext = rlinks.find('a')["id"]

for article in articles:
    title = article.select_one('g-card > div > div > a > div > div.iRPxbe > div.mCBkyc.JQe2Ld.nDgy9d').text
    publisher = article.select_one('g-card > div > div > a > div > div.iRPxbe > div.CEMjEf > span').text
    ws1.append([title,publisher])


while onlynext == "pnnext":
    try:
        time.sleep(4)
        url = "https://www.google.com" + reallinks
        driver.get(url)
        req = driver.page_source
        soup = BeautifulSoup(req, 'html.parser')

        articles = soup.select('#rso > div')
        links = soup.select('#xjs > table > tbody > tr > td.d6cvqb')
        rlinks = links[1]
        for article in articles:
            title = article.select_one('g-card > div > div > a > div > div.iRPxbe > div.mCBkyc.JQe2Ld.nDgy9d').text
            publisher = article.select_one('g-card > div > div > a > div > div.iRPxbe > div.CEMjEf > span').text
            ws1.append([title,publisher])
        if rlinks.find('a'):
            reallinks = rlinks.find('a')["href"]
            onlynext = rlinks.find('a')["id"]
        else:
            break
    except  IndexError:
        time.sleep(15)
        continue
ws1.column_dimensions['A'].width = 100 # A열
ws1.column_dimensions['B'].width = 20 # B열
wb.save(filename='company_government.xlsx')
driver.quit()
    # print("https://www.google.com" + reallinks)
    # print(onlynext)

# /Applications/Google\ Chrome.app/Contents/MacOS/Google\ Chrome --remote-debugging-port=9222 --user-data-dir="~/ChromeProfile"
# 맥에서 터미널로 크롬열기.
#rso > div:nth-child(1) > g-card > div > div > a > div > div.iRPxbe > div.CEMjEf > g-img