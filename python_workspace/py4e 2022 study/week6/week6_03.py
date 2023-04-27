def stock_profit(stocks, sells):
    co_list = stocks.split(",")
    ror_list = []
    ror_dic = {}
    num = 0
    for i in co_list:
        stock = i.split("/")
        ror = float(f"{(sells[num]-float(stock[2]))/float(stock[2])*100:.3}")
        ror_list.append(ror)
        ror_dic["%s의 수익률" %stock[0]]=ror
        num += 1

    ror_list.sort(reverse=True)
    convert_dic = {v:k for k,v in ror_dic.items()}

    for i in ror_list:
        print("%s의 수익률 %s" %(convert_dic[i],str(i)))

stocks = "삼성전자/10/85000,카카오/15/130000,LG화학/3/820000,NAVER/5/420000"
sells = [82000, 160000, 835000, 410000]

stock_profit(stocks,sells)
