import cyaron
from cyaron import *





n = int(input())
num = 1000000
mp = dict()
for i in range(num):
    l = 1
    r = n
    cnt = 0
    t = randint(1, n)
    while l!=r:
        x = randint(l,r)
        cnt += 1
        if x==t:
            l=r
        elif x<t:
            l = x+1
        elif x>t:
            r = x-1
    if cnt not in mp.keys():
        mp[cnt]=1
    else:
        mp[cnt]+=1

ex = 0.0
for i in mp.keys():
    print(i, mp[i], mp[i]/num)
    ex += i*mp[i]/num
print(ex)
print(9/5)




"""
1.3332587
1.33134
1.33041
1.3324699999999998
1.33282
1.33561
"""