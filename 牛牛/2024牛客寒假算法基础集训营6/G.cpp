#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
int p[maxn];
int n,m,k;
void NO(){cout<<-1<<endl;}
void solve()
{
	cin>>n>>m>>k;
	int ned_len = 1+k*2;
	if(ned_len>n)return NO();
	if(ned_len==n)
	{
		if(n==1)
		{
			p[1]=m;
			if(k)return NO();
		}
		else
		{
			int avg=m/n;
			while(avg*n - n/2 < m)avg++;
			ll now_sum = avg*n - m;
			ll avg_x = now_sum/(n/2);
			for(int i=1;i<=n;i++)
			{
				if(i&1)p[i]=avg;
				else p[i]=avg-avg_x;
			}
			p[n-1]-=now_sum - avg_x*(n/2);
		}
	}
	else
	{
		int ned_sum = n+(n/2+1);
		if(ned_sum > m)return NO();
		for(int i=1;i<=n;i++)
		{
			p[i]=1;m--;
			if(i%2==1 && i<=ned_len)
				p[i]++,m--;
		}
		p[ned_len+1]+=m;
	}
	for(int i=1;i<=n;i++)
		cout<<p[i]<<" ";
	cout<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}
/*
7 18 2
2 1 2 1 2 9 1


7 17 3
3 2 3 2 3 1 3
*/