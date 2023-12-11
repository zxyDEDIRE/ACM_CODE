import math


n = int(input())
k = int(input())

Len = len(str(n))
ans = 0
for a in range(1, Len+1):
    for b in range(1, Len+1):
        if a + b > Len:continue
        x = 10**a-k
        y = k*(10**b)-1
        gc = math.gcd(x,y)
        print(gc)
        x//=gc
        y//=gc
        _x = x
        _y = y
        while len(str(_x))<=a and len(str(_y))<=b:
            if len(str(_x))==a and len(str(_y))==b:
                now = _x*(10**b)+_y
                if now <= n:
                    ans = max(ans, _x*(10**b)+_y)

            _x += x
            _y += y
print(ans)
