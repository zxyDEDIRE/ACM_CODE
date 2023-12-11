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
char ch[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>ch[i];
	int cnta=0,cntb=0;
	for(int x=1;x<=n;x++)
	{
		for(int y=1;y<=n;y++)
		{
			int a=0,b=0;
			int _a=0,_b=0;
			int fl;
			for(int i=1;i<=n;i++)
			{
				fl=i;
				if(ch[i]=='A')a++;
				else b++;
				if(a==x)_a++,a=b=0;
				if(b==x)_b++,a=b=0;
				if(_a==y)break;
				if(_b==y)break;
			}
			if(fl!=n)continue;
			if(_a==y)cnta++;
			if(_b==y)cntb++;
			// cout<<x<<" "<<y<<" "<<_a<<" "<<_b<<" "<<cnta<<" "<<cntb<<endl;
		}
	}
	if(cnta&&cntb)cout<<"?\n";
	else if(cnta)cout<<"A\n";
	else cout<<"B\n";
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
AAA AAA AABBB AABBB BBAB
*/