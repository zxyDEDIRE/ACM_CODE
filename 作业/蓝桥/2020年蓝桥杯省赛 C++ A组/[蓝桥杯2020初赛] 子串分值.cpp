/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
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
vector<int>v[111];
char ch[maxn];
int n;
void solve()
{
	cin>>ch+1;
	n=strlen(ch+1);
	for(int i=0;i<26;i++)
		v[i].push_back(0);
	for(int i=1;i<=n;i++)
		v[ch[i]-'a'].push_back(i);
	for(int i=0;i<26;i++)
		v[i].push_back(n+1);
	ll ans=0;
	for(int x=0;x<26;x++)
	{
		if(v[x].size()==2)continue;
		for(int i=1;i<v[x].size()-1;i++)
		{
			ll a=v[x][i]-v[x][i-1];
			ll b=v[x][i+1]-v[x][i];
			ans+=a*b;
		}
	}
	cout<<ans<<endl;

}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}