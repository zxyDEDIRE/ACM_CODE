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
int cnt[maxn];
int f(char s){
	if(s>='a'&&s<='z')return s-'a';
	else return s-'A'+26;
}
string s,t;
bitset<maxn>vis;
void solve()
{
	cin>>s>>t;
	for(auto i:s)
		cnt[f(i)]++;
	int ans1=0,ans2=0;
	for(int i=0;i<t.size();i++)
	{
		int x=f(t[i]);
		if(cnt[x])ans1++,cnt[x]--,vis[i]=1;
	}
	for(int i=0;i<t.size();i++)
	{
		if(vis[i])continue;
		int x=f(t[i]);
		if(x<26)x+=26;
		else x-=26;
		if(cnt[x])ans2++,cnt[x]--;
	}
	cout<<ans1<<" "<<ans2<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
	return 0;
}