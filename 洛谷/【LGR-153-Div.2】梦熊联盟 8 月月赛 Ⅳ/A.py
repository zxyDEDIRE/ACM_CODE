import math
a, b, n = map(int, input().split())
ans = 1
for i in range(1, n + 1):
    if i%math.lcm(a,b)==0:
        ans = ans
    elif i%a==0:
        ans *= 2
    elif i%b==0:
        ans = math.ceil(ans/2)

print(ans % 998244353)
