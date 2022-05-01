import requests
from bs4 import BeautifulSoup

data = requests.get('https://seomal.com/map/1/176')
soup = BeautifulSoup(data.text, 'html.parser')

# 하나 가져오기
# select 경로는? 크롬 검사에서 오른쪽 마우스 copy selector
title = soup.select_one('#root > div > div > div:nth-child(1) > div.MuiDrawer-root.MuiDrawer-docked.MapSubDrawer > div > div:nth-child(3) > div:nth-child(2) > ul > div:nth-child(1) > div > span')

# 태그의 텍스트 가져오기
print(title.text)

# 태그의 속성 가져오기
# print(title['href'])

# 여러 개 가져오기
# trs = soup.select_one('#root > div > div > div:nth-child(1) > div.MuiDrawer-root.MuiDrawer-docked.MapSubDrawer > div > div:nth-child(3) > div:nth-child(2) > ul > div:nth-child(1) > div > span')

# print(trs)
# for tr in trs:
#     a_tag = tr.select_one('td.title > div > a')
#     if a_tag is not None:
#         rank = tr.select_one('img')['alt']
#         title = a_tag.text
#         point = tr.select_one('td.point').text
#         print(rank, title, point)