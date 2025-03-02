ans = int()
mi = 1e18
def dfs(step:int,x:int):
    global mi,ans
    if step>6 :
        return 
    if step > mi :
        return 
    if x%495==0 :
        mi=min(mi,step);
#         print(mi,x)
        ans=x;
        return
    for i in range(0,10):
        dfs(step+1,x*10+i)

        
        
n = int(input())
if n %495 ==0:
    print(-1)
    exit(0)

dfs(0,n)
ans=str(ans)
a = len(str(n))
b = len(str(ans))
for i in range(a,b):
    print(ans[i],end="")

