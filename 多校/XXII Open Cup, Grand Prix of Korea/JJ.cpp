/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
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
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
vector<int>v[111];
bitset<maxn>vis;
pii p[maxn];
set<int>s;
set<int>ss;
int n;
void solve()
{
	cin>>n;
	if(n==1){
		cout<<0<<" "<<0<<endl;
		return ;
	}
	int ma=0,mi=INF;
	for(int i=1;i<=n;i++)
	{
		auto &[x,y]=p[i];
		cin>>x>>y;
		v[y].push_back(x);
		ma=max(ma,x);
		mi=min(mi,x);
	}
	for(int i=1;i<=100;i++)
		for(int j=i+1;j<=100;j++)
			for(auto x:v[i])
				for(auto y:v[j]){
					int m=abs(x-y);
					for(int k=1;k*k<=m;k++)
						if(m%k==0)
							s.insert(k),s.insert(m/k);}
	int t=INF;
	ss.insert(ma-mi+1);
	for(int i=1;i<=100;i++)
	{
		for(int I=0;I<v[i].size();I++)
			for(int J=I+1;J<v[i].size();J++){
				int m=abs(v[i][I]-v[i][J]);
				for(int k=1;k*k<=m;k++)
					if(m%k==0){
						if(!s.count(k))t=min(t,k),ss.insert(k);
						if(!s.count(m/k))t=min(t,m/k),ss.insert(m/k);
			}
				
	}}
	for(auto m:ss)
	{
		if(m==t)continue;
		if(m>n)break;
		vis.reset();
		for(int i=1;i<=n;i++)
		{
			auto [x,y]=p[i];
			vis[(x%m+m)%m]=1;
		}
		int flag=1;
		for(int i=0;i<m;i++)
			if(!vis[i])
				flag=0;
		if(flag)s.insert(m);
	}
	int ans_1=0,ans_2=0;
	ans_1=s.size();
	for(auto i:s)
		ans_2+=i;
	cout<<ans_1<<" "<<ans_2<<endl;


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
/*
-1 1 2

*/