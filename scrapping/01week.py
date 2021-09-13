from bs4 import BeautifulSoup
import bs4
from selenium import webdriver
import time
import dload

driver = webdriver.Chrome('./chromedriver') # 웹드라이버 파일의 경로
driver.get("https://pixabay.com/ko/images/search/%ED%99%8D%EC%B0%A8/")
time.sleep(3) # 3초 동안 페이지 로딩 기다리기

req = driver.page_source
# HTML을 BeautifulSoup이라는 라이브러리를 활용해 검색하기 용이한 상태로 만듦
# soup이라는 변수에 "파싱 용이해진 html"이 담긴 상태가 됨

soup = BeautifulSoup(req, 'html.parser')

image = soup.select('#app > div > div:nth-child(4) > div > div > div.results--efirA > div > div > div > div > div > a > img')

i =1
for images in image :
    saveimg = images['src']
#     # 21번째 줄에서 ['src'] 오류 발생 >> 스크래핑할때 html에서 img태그까지 끝까지 추적해야 src 주소만 뽑아올 수 있었음 <div>에 같혀있거나 <a>에 같혀있는 img 태그 속의 src는 추출시도는 오류가 남!
    dload.save(saveimg,f'freeimage/{i}.jpg')
    i += 1

driver.quit()

