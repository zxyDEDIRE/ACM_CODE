#include<bits/stdc++.h>
#define ll long long
#define int long long
#define x first
#define y second
using namespace std;
const int maxN = 2e5 + 10;
const int maxM = 2e5 + 10;
const int INF = 1e18;
const int mod = 998244353;
inline int read()
{
    int ans=0,f=0;
    char ch=getchar();
    while(ch<'0'||ch>'9')f^=(ch=='-'),ch=getchar();
    while(ch>='0'&&ch<='9')ans=(ans<<3)+(ans<<1)+(ch^48),ch=getchar();
    return f?-ans:ans;
}
int n,k;
int cnt;
bool st[maxN];
int prime[maxN];
void get_primes(int n)
{
    st[1] = true;
    for(int i = 2 ; i <= n ; i++)
    {
        if(!st[i]) prime[++cnt] = i;
        for(int j=1 ; prime[j] <= n / i ; j++)
        {
            //printf("prime[j]*i:%d\n",prime[j]*i);
            st[prime[j]*i] = true;
            if(i % prime[j] == 0) break;
        }
    }
}
int vis[maxN];
signed main()
{
    get_primes(2e5 + 5);
    vector<int>vet;
    n = read(), k = read();
    int ans = 0;
    int mx = 0;
    for(int i = 1 ; i <= n ; i++) 
        if(prime[i] > n)
        { 
            mx = prime[i - 1];
            break;
        }
    if(mx - 1 > k) ans += 1, vis[mx] = 1;
    for(int i = 2 ; i <= n ; i++)
        if(i - 1 > k && vis[i] == 0) ans += 1, vis[i] = 1;
    for(int i = 2 ; i <= n ; i++)
    {    
        if(mx - i > k && vis[i] == 0)
        {
            ans += 1;
            vis[i] = 1;
        }
        else if(mx - i <= k && vis[i] == 0)
        {
            int res = INF;
            for(int j = k + i + 1 ; j <= n ; j++)
                res = min(__gcd(j, i), res);
            if(res != INF)
            {
                ans += res;
                vis[i] = 1;
            }
        }
    }
    for(int i = 2 ; i <= n ; i++)
        if(vis[i] == 0) ans += i;
    printf("%lld\n",ans);
    system("pause");
    return 0;
}