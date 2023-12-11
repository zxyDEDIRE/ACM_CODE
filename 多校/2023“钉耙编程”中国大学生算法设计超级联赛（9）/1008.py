#!/usr/bin/env python

from cyaron import *  # 引入CYaRon的库

#
# _n = ati([0, 7, 50, 1E4]) # ati函数将数组中的每一个元素转换为整形，方便您可以使用1E4一类的数来表示数据大小
# _m = ati([0, 11, 100, 1E4])
#
# # 这是一个图论题的数据生成器，该题目在洛谷的题号为P1339
# for i in range(1, 4): # 即在[1, 4)范围内循环，也就是从1到3
#     test_data = IO(file_prefix="heat", data_id=i) # 生成 heat[1|2|3].in/out 三组测试数据
#
#     n = _n[i] # 点数
#     m = _m[i] # 边数
#     s = randint(1, n) # 源点，随机选取一个
#     t = randint(1, n) # 汇点，随机选取一个
#     test_data.input_writeln(n, m, s, t) # 写入到输入文件里，自动以空格分割并换行
#
#     graph = Graph.graph(n, m, weight_limit=5) # 生成一个n点，m边的随机图，边权限制为5
#     test_data.input_writeln(graph) # 自动写入到输入文件里，默认以一行一组u v w的形式输出
#
#     test_data.output_gen("D:\\std_binary.exe") # 标程编译后的可执行文件，不需要freopen等，CYaRon自动给该程序输入并获得输出作为.out


n = int(input())
p = list(map(int, input().split()))


def ok():
    cnt = 0;
    for i in p:
        if i != 0:
            cnt += 1
    if cnt > 1:
        return 1
    return 0


olf = list()
for i in p:
    olf.append(i)

mp = dict()
tot = 1000
for i in range(0, tot):
    num = 0

    p = list()
    for i in olf:
        p.append(i)


    while ok():
        num += 1
        x = randint(0, n - 1)
        y = randint(0, n - 1)
        while x == y or p[x] == 0 or p[y] == 0:
            x = randint(0, n - 1)
            y = randint(0, n - 1)
        # print(p)
        p[x]-=1
        p[y]+=1

    if num not in mp.keys():
        mp[num] = 1
    else:
        mp[num] += 1
    # print(num)
    # print("")

ex = 0.0

for i in mp:
    print(i, mp[i], mp[i]/tot)
    ex += i * mp[i]/tot

print(ex)
print(ceil(ex))
"""
1 1 1 1 1  10
1 1 1 1    6
1 1 1      3
1 1        1

1 1    1
1 2    2
1 3    3
1 4    4

2 2    4
2 3    6
2 4    8
2 5    10


3 3   9
3 4  12



1 1 1   3
1 1 2   5
1 1 3   7
1 1 4   9
1 1 5   11

1 2 2   8
1 2 3   11
1 2 4   14

1 3 1   7
1 3 2   11
1 3 3   15
1 3 4   19

2 2 2   12
2 2 3   16
2 2 4   20
2 3 3   21

3 3 3  27
2 3 4  26
1 3 5  23


1 3  3
1 3 1 3+4=7 4
1 3 5 7+16= 23



a1 a2 a3 a4
a1*a2
(a1 a2 1) = a1*a2 + (a1+a2)
(a1 a2 2) = a1*a2 + (a1+a2)*2
(a1 a2 a3) = a1*a2 + (a1+a2)*a3


(a1 a2 a3 a4) =  (a1 a2 a3) + (a1+a2+a3)*a4
"""