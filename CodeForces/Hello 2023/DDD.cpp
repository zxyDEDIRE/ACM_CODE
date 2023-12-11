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
const int N=2e5+10;
struct ST{
	int f[N][30],n;
	void init(int x,vector<int>p){
		n=x;
		for(int i=1;i<=n;i++)//距离为0初始化 
			f[i][0]=p[i];
		int t=log(n)/log(2)+1;//j定位 
		for(int j=1;j<t;j++)
			for(int i=1;i<=n-(1<<j)+1;i++)
				f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
	}
	int query(int l,int r){
		int k=log2(r-l+1);
		return max(f[l][k],f[r-(1<<k)+1][k]);
	}
}st;
void NO(){cout<<"No"<<endl;}
void solve()
{
	int n,m;
	cin>>n;
	vector<int>a(n+1,0);
	vector<int>b(n+1,0);
	map<int,int>mp;
	map<int,int>l;

	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>b[i];
	cin>>m;
	for(int i=1,x;i<=m;i++)
		cin>>x,mp[x]++;

	st.init(n,b);

	for(int i=1;i<=n;i++)
	{
		if(a[i]==b[i])continue;
		else if(b[i]>a[i])return NO();

		int x=b[i];
		if(l.count(x)&&l[x]&&st.query(l[x],i)>x)
		{
			if(!mp.count(x)||mp[x]<=0)return NO();
			mp[x]--;
			l[x]=i;
		}
		else l[x]=i;
	}
	for(auto [x,y]:l)
		if(!mp.count(x)||mp[x]<=0)return NO();
	cout<<"Yes"<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}