import os
import pymysql
import pymysql.cursors
import requests
import xlrd
from xlutils.copy import copy
import bs4

def main(page):
    url="https://ac.nowcoder.com/acm/contest/profile/679950901/practice-coding?&pageSize=10&search=&statusTypeFilter=-1&languageCategoryFilter=-1&orderType=DESC&page="+str(page)
    html=getHtml(url)
    item=FillUnivList(html)
    write_item_to_excel(item,page-1)
    write_item_to_mysql(item, page - 1)
    write_item_to_file(item)
def getHtml(path):
    try:
        r=requests.get(path)
        r.raise_for_status()
        r.encoding='utf-8'
        return r.text
    except:
        return "错误"
def FillUnivList(html):
    soup=bs4.BeautifulSoup(html,"html.parser")
    for tr in soup.find('tbody').children:
        if isinstance(tr,bs4.element.Tag):
            tds=tr('td')
            yield {
                "运行ID":tds[0].a.string,
                "题目":tds[1].a.string,
                "运行结果":tds[2].a.string,
                "得分":tds[3].contents[0].string,
                "运行时间(ms)":tds[4].contents[0].string,
                "使用内存(KB)":tds[5].contents[0].string,
                "代码长度":tds[6].contents[0].string,
                "使用语言":tds[7].contents[0].string,
                "提交时间":tds[8].contents[0].string,
            }
def write_item_to_file(item):
    with open("C:\\Users\\tob\\Desktop\\提交记录.txt",'a',encoding='UTF-8') as file:
        for i in item:
            file.write(str(i)+'\n')
def write_item_to_excel(items,page):
    path="C:\\Users\\tob\\Desktop\\提交记录.xls"
    rb=xlrd.open_workbook(path)
    wb=copy(rb)
    worksheet=wb.get_sheet(0)
    col=("运行ID","题目","运行结果","得分", "运行时间(ms)","使用内存(KB)","代码长度", "使用语言","提交时间")
    for i in range(0,9):
        worksheet.write(0,i,col[i])
    j=1
    for item in items:
        worksheet.write(j + page * 10, 0, str(item["运行ID"]))
        worksheet.write(j + page * 10, 1, str(item["题目"]))
        worksheet.write(j + page * 10, 2, str(item["运行结果"]))
        worksheet.write(j + page * 10, 3, str(item["得分"]))
        worksheet.write(j + page * 10, 4, str(item["运行时间(ms)"]))
        worksheet.write(j + page * 10, 5, str(item["使用内存(KB)"]))
        worksheet.write(j + page * 10, 6, str(item["代码长度"]))
        worksheet.write(j + page * 10, 7, str(item["使用语言"]))
        worksheet.write(j + page * 10, 8, str(item["提交时间"]))
        j=j+1
    os.remove(path)
    wb.save(path)
def write_item_to_mysql(items,page):
    connection = pymysql.connect(host="localhost",user="root",password="ccsu",db="python",port=3306)
    print("数据库连接成功")
    cur=connection.cursor()
    # sql="insert into book values('zzz','aaa','bbb');"
    # cur.execute(sql)
    for item in items :
        sql="insert into Record_of_submission values('%s','%s','%s','%s','%s','%s','%s','%s','%s');"%(str(item["运行ID"]),str(item["题目"]),str(item["运行结果"]),
                str(item["得分"]),str(item[ "运行时间(ms)"]),str(item["使用内存(KB)"]),str(item["代码长度"]),str(item["使用语言"]),str(item["提交时间"]))
        cur.execute(sql)
    connection.commit()#提交
    connection.close()#断开
    print("数据库连接关闭")
if __name__ == "__main__":
    for i in range(1,8):
        main(i)