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
vector<int>v[100];
bitset<100>vis;
int p[maxn];
int find(int r){
	return p[r]=p[r]==r?p[r]:find(p[r]);
}
void solve()
{
	v[0].push_back(1);
	v[1].push_back(0);
	v[1].push_back(4);
	v[4].push_back(1);
	v[4].push_back(6);
	v[6].push_back(4);
	v[6].push_back(5);
	v[5].push_back(6);
	v[5].push_back(2);
	v[2].push_back(5);
	v[2].push_back(0);
	v[0].push_back(2);
	v[1].push_back(3);
	v[3].push_back(1);
	v[3].push_back(4);
	v[4].push_back(3);
	v[3].push_back(2);
	v[2].push_back(3);
	v[3].push_back(5);
	v[5].push_back(3);
	int ans=0;
	for(int T=1;T<(1<<7);T++)
	{
		vis.reset();
		for(int i=0;i<=6;i++)
		{
			p[i]=i;
			if(T&(1<<i))vis[i]=1;
		}
		for(int i=0;i<=6;i++)
		{
			if(!vis[i])continue;
			for(auto j:v[i])
				if(vis[j])
				{
					int fa=find(i);
					int fb=find(j);
					if(fa!=fb)p[fa]=fb;
				}
		}
		int cnt=0;
		for(int i=0;i<=6;i++)
			if(vis[i]&&p[i]==i)cnt++;
		if(cnt==1)ans++;
	}
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}