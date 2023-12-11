/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
using ll=long long;
using pii=pair<int,int>;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
int p[maxn];
int cnt;
void h(int x,int y)
{
	cnt=0;
	map<int,int>mp;
	for(int i=2;i<=x;i++)
	{
		if(x%i==0&&!mp[i])
		{
			mp[i]=1;
			p[cnt++]=i;
		}
		while(x%i==0)x/=i;
	}
	if(x>1&&!mp[x])
		p[cnt++]=x,mp[y]=1;
	for(int i=2;i<=y;i++)
	{
		if(y%i==0&&!mp[i])
		{
			mp[i]=1;
			p[cnt++]=i;
		}
		while(y%i==0)y/=i;
	}
	if(y>1&&!mp[y])
		p[cnt++]=y,mp[y]=1;
}
int f(int n)
{
    ll ans = 0;
    for (int i = 1; i < (1 << cnt); i++){   // 二进制枚举质因子所有组合
        ll tmp = 1, t = 0;
        for(int j = 0; j < cnt; j++){   
            if((1<<j)&i){       // 如果第 j 位为一
                tmp *= p[j];
                t++;
            } 
        }
        ans += (t & 1 ? n / tmp : -n / tmp);        // 奇加偶减
    }

    return n - ans;
}
void solve()
{
	int n,q;
	cin>>n>>q;
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		if(__gcd(x,y)==1)cout<<"1 1"<<endl;
		else
		{
			int fl=0;
			if(__gcd(x,y)==2)fl++;
			h(x,y);
			cout<<2<<" ";
			cout<<f(n)+fl<<endl;
		}
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}
/*
10000000 1
9699690 969969
*/