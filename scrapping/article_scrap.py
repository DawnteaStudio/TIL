
from bs4 import BeautifulSoup
from selenium import webdriver
from selenium.webdriver.chrome.options import Options
import openpyxl
import time

co = Options()
co.add_experimental_option('debuggerAddress','127.0.0.1:9222')
co_driver = "./chromedriver"
driver = webdriver.Chrome(co_driver, options = co)
driver.implicitly_wait(10)

count_year = 1
years = 2002
month = 1
last_date = [31,28,31,30,31,30,31,31,30,31,30,31]
count_month = 0
how_many = 0
esg = "E"
count_esg = 0
# keyword = [("climate","change"),("natural","capital"),("pollution","waste"),("environmental","opportunities"),("human","capital"),("product","liability"),("stakeholder","opposition"),("social","opportunities"),("corporate","goveranance"),("corporate","behavior")]
keyword = [("climate","change")]

wb = openpyxl.Workbook()
wb2 = openpyxl.Workbook()
ws1 = wb.active
ws2 = wb2.active
ws1.append(["Name", "ESG","year","month","keyword"])
ws2.append(["year","month","total","ESG","keyword"])
ws1.column_dimensions['A'].width = 100 # A열
ws1.column_dimensions['B'].width = 20 # B열

for (first,last) in keyword:
    count_esg += 1
    while count_year < 21:

        how_many = 0
        url = f"https://www.google.com/search?q=intitle:{first}+and+intitle:{last}&tbs=cdr:1,cd_min:{month}/1/{years},cd_max:{month}/{last_date[count_month]}/{years}&tbm=nws"
        driver.get(url)
        try:
            req = driver.page_source
            soup = BeautifulSoup(req, 'html.parser')
            articles = soup.select('#rso > div')
            links = soup.select('#xjs > table > tbody > tr > td.d6cvqb')
            rlinks = links[1]
            reallinks = rlinks.find('a')["href"]
            onlynext = rlinks.find('a')["id"]
        except IndexError:
            no_news = soup.select_one('head > title').text
            if no_news == f'intitle:{first} and intitle:{last} - Google 검색':
                if month < 12:
                    ws2.append([years,month,how_many,esg,first+' '+last])
                    month += 1
                    count_month += 1
                    continue
                else:
                    ws2.append([years,month,how_many,esg,first+' '+last])
                    month = 1
                    count_month = 0
                    count_year += 1
                    years += 1
                    continue    
            else:
                time.sleep(30)
                continue

        for article in articles:
            title = article.select_one('g-card > div > div > a > div > div.iRPxbe > div.mCBkyc.JQe2Ld.nDgy9d').text
            # publisher = article.select_one('g-card > div > div > a > div > div.iRPxbe > div.CEMjEf > span').text
            ws1.append([title,esg,years,month,first+' '+last])
            how_many += 1
        # 첫 페이지는 while 밖의 for문

        while onlynext == "pnnext":
            try:
                time.sleep(0.5)
                url = "https://www.google.com" + reallinks
                driver.get(url)
                req = driver.page_source
                soup = BeautifulSoup(req, 'html.parser')

                articles = soup.select('#rso > div')
                links = soup.select('#xjs > table > tbody > tr > td.d6cvqb')
                rlinks = links[1]
                for article in articles:
                    title = article.select_one('g-card > div > div > a > div > div.iRPxbe > div.mCBkyc.JQe2Ld.nDgy9d').text
                    # publisher = article.select_one('g-card > div > div > a > div > div.iRPxbe > div.CEMjEf > span').text
                    ws1.append([title,esg,years,month,first+' '+last])
                    how_many += 1
                if rlinks.find('a'):
                    reallinks = rlinks.find('a')["href"]
                    onlynext = rlinks.find('a')["id"]
                else:
                    break
            except  IndexError:
                time.sleep(30)
                continue

        if count_esg < 5:
            esg = "E"
        elif count_esg < 9:
            esg = "S"
        else:
            esg = "G"

        ws2.append([years,month,how_many,esg,first+' '+last])

        if month < 12:
            month += 1
            count_month += 1
        else:
            month = 1
            count_month = 0
            count_year += 1
            years += 1

wb.save(filename='name_scrapping.xlsx')
wb2.save(filename='count_monthly.xlsx')    
driver.quit()
# /Applications/Google\ Chrome.app/Contents/MacOS/Google\ Chrome --remote-debugging-port=9222 --user-data-dir="~/ChromeProfile"
# 맥에서 터미널로 크롬열기.
# C:\Program Files (x86)\Google\Chrome\Application\chrome.exe --remote-debugging-port=9222 --user-data-dir="C:/ChromeTEMP"
# 윈도우에서 cmd로 크롬열기.
