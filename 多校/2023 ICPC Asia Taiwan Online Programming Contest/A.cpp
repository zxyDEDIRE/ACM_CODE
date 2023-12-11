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
void NO(){	cout<<"TOO LATE";}
void YES(){cout<<"GOOD";}
void solve()
{
	int a,b,c;
	scanf("%d-%d-%d",&a,&b,&c);

	if(a>2023)return NO();
	else if(a<2023)return YES();
	else
	{
		if(b>9)return NO();
		else if(b<9)return YES();
		else
		{
			if(c>16)return NO();
			else return YES();
		}
	}
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
	return 0;
}
/*
2023-10-21 35
2023-10-1  15
2023-09-30 14
2023-09-16 0


*/