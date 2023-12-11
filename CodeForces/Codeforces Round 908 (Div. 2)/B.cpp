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
int a[maxn];
int b[maxn];
int n;
void solve()
{
	cin>>n;
	map<int,int>mp;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		mp[a[i]]++;
	}
	if(mp.size()==1){
		cout<<"-1\n";
		return ;
	}
	map<int,int>s;
	int tot=0;
	for(auto [x,y]:mp)
	{
		if(y>=2)
		{
			if(s.size()<2)s[x]=tot++;
		}
	}
	if(s.size()!=2){
		cout<<"-1\n";
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(!s.count(a[i]))cout<<1<<" ";
		else if(s[a[i]]==0)cout<<1<<" ",s[a[i]]=4;
		else if(s[a[i]]==1)cout<<1<<" ",s[a[i]]=5;
		else if(s[a[i]]==4)cout<<2<<" ";
		else cout<<3<<" ";
	}
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
1 2 3 4 5 6
1 2 3 2 2 3
1 2 3 1 1 1 

a[2]==a[4]
b[2]=2,b[4]=1

a[2]=a[5]
b[2]=2,b[5]=1

a[3]=a[6]
b[3]=3,b[6]=1

*/