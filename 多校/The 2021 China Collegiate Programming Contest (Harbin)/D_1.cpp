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
ll num_s, num_t, gs,gt,g;
string s,t;
pii ans;
int lens,lent;
int flag;
void check(string str)
{
	ll now_s=stoll(str);
	if(now_s==0)return ;
	if(now_s%gs!=0)return ;

	ll now_t=gt*now_s/gs;
	string _s=to_string(now_s);
	string _t=to_string(now_t);

	map<int,int>S,T;
	int l;


	l=0;
	for(int i=0;i<s.size();i++)
	{
		if(l<_s.size()&&s[i]==_s[l])l++;
		else S[s[i]]++;
	}
	if(l!=_s.size())return ;
	l=0;
	for(int i=0;i<t.size();i++)
	{
		if(l<_t.size()&&t[i]==_t[l])l++;
		else T[t[i]]++;
	}
	if(l!=_t.size())return ;
	if(S!=T)return ;

	if(ans.first==-1)ans={now_s,now_t};
	else ans=min(ans,{now_s,now_t});
}
void dfs(int step,string num)
{
	if(step==lent)
	{
		check(num);
		return ;
	}
	for(char i='0';i<='9';i++)
		dfs(step+1,num+i);
} 
void solve()
{
	cin>>s>>t;
	num_s=stoll(s);
	num_t=stoll(t);
	g=__gcd(num_s,num_t);
	gs=num_s/g;
	gt=num_t/g;
	lens=s.size();
	lent=t.size();
	ans={-1,-1};
	dfs(0,"");
	cout<<ans.first<<" "<<ans.second<<endl;
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