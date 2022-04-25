import requests as rq
from bs4 import BeautifulSoup
import pandas as pd
import csv
import copy

def gethtml(kw):
    url='https://www.gushici.net/chaxun/ju/'
    url=url+kw
    response=rq.get(url)
    return response

def urlcc(i):
    a='body > div.main > div.left > div.ju > div:nth-child('
    b=') > a.jucc'
    c=a+str(i)+b
    return c

def urlzi(i):
    a='body > div.main > div.left > div.ju > div:nth-child('
    b=') > a.juzi'
    c=a+str(i)+b
    return c

class html():

    def __init__(self,res):
        self.a=res
    
    def get_title(self,i):
        soup=BeautifulSoup(self.a.text,'lxml')
        data=soup.select(urlcc(i))
        for item in data:
            result=item.get_text()
        return result
    
    def get_sentence(self,i):
        soup=BeautifulSoup(self.a.text,'lxml')
        data=soup.select(urlzi(i))
        for item in data:
            result=item.get_text()
        return result
    
    def get_link(self,i):
        soup=BeautifulSoup(self.a.text,'lxml')
        data=soup.select(urlzi(i))
        for item in data:
            result=item.get('href')
        return result

def files(a,k):
    html1=html(a)
    item={}
    item_list=[]
    m=1
    for i in range(1,k):
        item['title']=html1.get_title(m)
        item['sentence']=html1.get_sentence(m)
        item['link']=html1.get_link(m)
        print(m)
        item_list.append(copy.deepcopy(item))
        m=m+1
    #item['title']=html1.get_title(m+2)
    #item['sentence']=html1.get_sentence(m+2)
    #item['link']=html1.get_link(m+2)
    #item_list.append(copy.deepcopy(item))
    #print(item_list)
    #m=m+1
    #item['title']=html1.get_title(m+2)
    #item['sentence']=html1.get_sentence(m+2)
    #item['link']=html1.get_link(m+2)
    #item_list.append(copy.deepcopy(item))
    #print(item_list)

    df=pd.DataFrame(item_list)
    df.to_csv('result.csv',encoding='utf_8_sig')
    return 0


#body > div.main > div.left > div.ju > div:nth-child(2) > a.jucc




