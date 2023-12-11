#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
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

int n,q;
void solve()
{
	cin>>n>>q;
	int cnt_1=0,cnt_2=0,sum=0;
	set<int>s;
	int fl=0;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		if(p[i]==1)cnt_1++,fl=i;
		if(p[i]==2)cnt_2++;
		sum+=p[i];
	}
	while(q--)
	{
		int op,x,w;
		cin>>op;
		if(op==1)
		{
			cin>>x;
			int flag=1;

			if(x>sum)flag=0;
			if(cnt_1==0 && (x%2)==1 )flag=0;
			if(cnt_1==1 && x%2==0 && x > max(2*(fl-1) ,2*(n-fl)) )flag=0;


			if(flag)cout<<"YES\n";
			else cout<<"NO\n";
		}
		else
		{
			cin>>x>>w;

			sum-=p[x];
			if(p[x]==1)cnt_1--;
			else cnt_2--;

			p[x]=w;

			sum+=p[x];
			if(p[x]==1)cnt_1++,fl=x;
			else cnt_2++;
		}
	}
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
5 5
2 1 2 1 2
1 5
1 6
1 7
2 4 2
1 7


2 1 2 1 2

2 2 1 2


3 1
2 2 2
1 3

7 6
2 1 2 1 2 1 2 

2 2 2 1 2 2 2 1 2 2 2 



2 2 2 2 1 1 2 2 2 2
11 13 15 


17  

18
*/