from bs4 import BeautifulSoup
from selenium import webdriver

driver = webdriver.Chrome('./chromedriver')

url = "https://search.naver.com/search.naver?where=news&sm=tab_jum&query=헝다"

driver.get(url)
req = driver.page_source
soup = BeautifulSoup(req, 'html.parser')
articles = soup.select('#main_pack > section > div > div.group_news > ul > li')

for article in articles:
    title = article.select_one('div.news_wrap.api_ani_send > div > a').text
    print(title)
    # title = article.select_one('div > div > a').text 이렇게 경로를 잘 못 찾으면 프린트가 안된다

driver.quit()

