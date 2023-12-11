/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define p(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
bitset<maxn>visa,visb;
int a[maxn],b[maxn];
int ans_a[maxn];
int ans_b[maxn];
int p[maxn];
int n;
void NO(){cout<<"No"<<endl;}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i],a[i]=b[i]=0;
	visa.reset();
	visb.reset();

	for(int i=1;i<=n;i++)
	{
		int x=p[i];
		if(!visa[x])
			a[i]=x,visa[x]=1;
		else if(!visb[x])
			b[i]=x,visb[x]=1;
		else return NO();
	}
	vector<int>v,u;
	for(int i=1;i<=n;i++)
	{
		if(!visa[i])
			u.push_back(i);
		if(visb[i])
			v.push_back(i);
	}
	for(int i=0;i<v.size();i++)
	{
		if(u[i]>v[i])return NO();
		ans_a[v[i]]=u[i];
	}
	u.clear();
	v.clear();
	for(int i=1;i<=n;i++)
	{
		if(visa[i])
			u.push_back(i);
		if(!visb[i])
			v.push_back(i);
	}
	for(int i=0;i<v.size();i++)
	{
		if(v[i]>u[i])return NO();
		ans_b[u[i]]=v[i];
	}
	cout<<"Yes"<<endl;
	for(int i=1;i<=n;i++)
	{
		if(a[i])cout<<a[i]<<" ";
		else cout<<ans_a[b[i]]<<" ";
	}cout<<endl;
	for(int i=1;i<=n;i++)
	{
		if(b[i])cout<<b[i]<<" ";
		else cout<<ans_b[a[i]]<<" ";
	}cout<<endl;
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
*/