/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
map<int,int>mp;
int s;
int n,mi=1e9;
int len(int x){
	int cnt=0;
	while(x)cnt++,x/=10;
	return cnt;
}
int f(int x){
	x=x+(x%10)*pow(10,len(x));
	x/=10;
	return x;
}
void dfs(int t,int cnt)
{
	if(t>=maxn)return ;
	if(mp.count(t)&&cnt>=mp[t])return ;
	mp[t]=cnt;
	// cout<<t<<" "<<vis[t]<<endl;
	if(len(t)>len(s))return ;
	else if(t==s){
		mi=min(mi,cnt);
		return ;
	}
	dfs(t*n,cnt+1);
	if((t%10)!=0)
		dfs(f(t),cnt+1);
}
void solve()
{
	cin>>n>>s;
	dfs(1,0);
	if(mi==1e9)cout<<-1<<endl;
	else cout<<mi<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}