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
string s;
int n;
void NO(){cout<<"NO\n";}
void solve()
{
	cin>>s;
	n=s.size();
	int max_true=0;
	int min_wrong=INF;
	int r=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='+')r++;
		else if(s[i]=='-')
		{
			r--;
			if(max_true>r)max_true=r;
			if(r<min_wrong)min_wrong=INF;
			if(r<0)return NO();
		}
		else if(s[i]=='0')
		{
			if(r<=1)return NO();
			if(r==max_true)return NO();
			min_wrong=min(min_wrong,r);
		}
		else if(s[i]=='1')
		{

			if(r>=min_wrong)return NO();
			max_true=r;
		}
	}
	cout<<"YES\n";
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
++01
++++0++--1
*/