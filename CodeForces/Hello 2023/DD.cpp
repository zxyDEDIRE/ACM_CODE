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
vector<int>v[N];
map<int,int>tip;
map<int,int>mp;
int id[N];
int a[N];
int b[N];
int n,m,tot;
struct ST2{
	int f[maxn][30];
	void init()
	{
		for(int i=1;i<=n;i++)//距离为0初始化 
			f[i][0]=b[i];
		int t=log(n)/log(2)+1;//j定位 
		for(int j=1;j<t;j++)
		{
			for(int i=1;i<=n-(1<<j)+1;i++)
			{
				f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
				//f[i][j-1]为f[i][j]的长为2^j-1的前半段，另一段为f[i+(1<<(j-1))][j-1] 
			}
		} 
	}
	int query(int l,int r)
	{
		int k=log2(r-l+1);
		return max(f[l][k],f[r-(1<<k)+1][k]);
	}
}st;
void NO(){cout<<"No"<<endl;}
void solve()
{
	int ok=0;
	mp.clear();
	tip.clear();
	for(int i=1;i<=tot;i++)
		v[i].clear();
	tot=0;


	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
		if(b[i]>a[i])ok=1;

		if(!tip.count(b[i]))
		{
			tip[b[i]]=++tot;
			id[tot]=b[i];
		}
		v[tip[b[i]]].push_back(i);
	}
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		int x;
		cin>>x;
		mp[x]++;
	}

	if(ok)return NO();

	st.init();

	for(int i=1;i<=tot;i++)
	{
		int r=0;
		// cout<<"id: "<<id[i]<<endl;
		for(int l=0;l<v[i].size();l++)
		{
			r=l;
			int flag=0;
			if(a[v[i][r]]>id[i])flag=1;
			while(1)
			{
				if(r+1>=v[i].size())break;
				int x=st.query(v[i][l],v[i][r+1]);
				if(x>id[i])break;
				if(a[v[i][r]]>id[i])flag=1;
				r++;
			}
			if(flag)
			{
				// cout<<"ok"<<endl;
				// if(!mp.count(id[i])||mp[id[i]]<=0)return NO();
				if(mp[id[i]]<=0)return NO();
				mp[id[i]]--;
			}
			
			l=r;
		}
	}
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
/*
1
13
1 2 3 4 5 6 7 8 9
7 9 4 5 3 3 3 6 8 10 3 2 5
5 3 1 5 3 2 2 5 8 5 1 1 5
8
1 5 3 5 4 2 3 1


1
5
4 3 3 3 3
3 1 1 1 3
1
1
*/