常量 maxn = 1000001
常量 INF = 2 << 20
结构体 Point:
    变量 x, y

函数 cmp(a: Point, b: Point):
    如果 a.x == b.x:
        返回 a.y < b.y
    否则:
        返回 a.x < b.x

函数 cmps(a: 整数, b: 整数):
    返回 S[a].y < S[b].y

函数 min(a: 双精度浮点数, b: 双精度浮点数):
    如果 a < b:
        返回 a
    否则:
        返回 b

函数 dist(i: 整数, j: 整数):
    x = (S[i].x - S[j].x) * (S[i].x - S[j].x)
    y = (S[i].y - S[j].y) * (S[i].y - S[j].y)
    返回 sqrt(x + y)

函数 merge(left: 整数, right: 整数):
    d = INF
    如果 left == right:
        返回 d
    如果 left + 1 == right:
        返回 dist(left, right)
    
    mid = (left + right) / 2
    d1 = merge(left, mid)
    d2 = merge(mid + 1, right)
    
    d = min(d1, d2)
    
    k = 0
    
    for i from left to right inclusive:
        if abs(S[mid].x - S[i].x) < d:
            temp[k] = i
            k += 1
    
    sort(temp[0:k], cmps)
    
    for i from 0 to k-1 inclusive:
        for j from i+1 to k-1 inclusive and S[temp[j]].y - S[temp[i]].y < d:
            d3 = dist(temp[i], temp[j])
            if d > d3:
                d = d3
    
     return d

过程 solve():
   输入 n
   for i from 0 to n-1 inclusive:
       输入 S[i].x 和 S[i].y
   
   sort(S[0:n], cmp)

   输出 merge(0,n-1) 到小数点后4位

过程 main():
   solve()