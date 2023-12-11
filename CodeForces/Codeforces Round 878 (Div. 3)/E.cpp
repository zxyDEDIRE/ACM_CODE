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
vector<int>v[maxn];
bitset<maxn>vis;
string s[2];
int n,t,q;
void solve()
{
	cin>>s[0]>>s[1];
	n=s[0].size();
	int cnt=0;
	vis.reset();
	for(int i=0;i<n;i++)
	{
		if(s[0][i]!=s[1][i])vis[i]=1,cnt++;
		else vis[i]=0;
	}
	for(int i=0;i<=n+t+10;i++)
		v[i].clear();
		
	cin>>t>>q;
	for(int i=1;i<=q;i++)
	{
		for(auto j:v[i])
			vis[j]=1,cnt++;
		int op;
		cin>>op;
		if(op==1)
		{
			int pos;cin>>pos;pos--;
			if(s[0][pos]!=s[1][pos])
				cnt--,vis[pos]=0,v[i+t].push_back(pos);
		}
		else if(op==2)
		{
			int a,x,b,y;
			cin>>a>>x>>b>>y;
			x--;y--;
			a--,b--;
			int a_1=0,a_2=0;
			int b_1=0,b_2=0;
			if(s[a][x]!=s[a^1][x])a_1=1;
			if(s[b][y]!=s[b^1][y])b_1=1;

			swap(s[a][x],s[b][y]);

			if(s[a][x]!=s[a^1][x])a_2=1;
			if(s[b][y]!=s[b^1][y])b_2=1;
			cnt+=a_2+b_2-a_1-b_1;

		}
		else
		{
			if(cnt==0)cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}
	}
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}