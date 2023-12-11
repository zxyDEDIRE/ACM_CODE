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
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
int flag=0;
int fp(int b,int p,int mod)
{
	int r=1;
	b%=mod;
	while(p){
		if(p&1)r=(r*b)%mod;
		p>>=1;
		b=(b*b)%mod;
	}
	return r;
}
char mp[maxn];
vector<int>v;
vector<char>u;
string str;
void dfs(int x,int ans)
{
	if(u[x]=='='){
		if(ans==v[x+1]){
			mp[x]='=';
			for(int i=0;i<v.size();i++){
				cout<<v[i];
				if(i!=v.size()-1)cout<<mp[i];
			}
			exit(0);
		}
		return ;
	}
	else if(u[x]=='?')
	{
		mp[x]='+';
		dfs(x+1,ans+v[x+1]);

		mp[x]='-';
		dfs(x+1,ans-v[x+1]);

		mp[x]='#';
		if(ans>0&&v[x]>0)
			dfs(x+1,fp(ans,ans,v[x+1]));
	}
}
void solve()
{
	cin>>str;
	int t=0;
	for(auto i:str)
		if(i>='0'&&i<='9')t=t*10+(i-'0');
		else v.push_back(t),u.push_back(i),t=0;
	v.push_back(t);
	dfs(0,v[0]);
	cout<<-1<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*b
0?1?2?3?4?5?6?7?8?9?10?11?12?13?100=24
1=2

*/