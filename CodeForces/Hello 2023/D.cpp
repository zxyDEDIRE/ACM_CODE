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
struct node{
	int x,y,z;
};
pii p[maxn];
int cnt[maxn];
int a[maxn];
int b[maxn];
int n,m,tot;
struct ST{
	int f[maxn][30];
	void init()
	{
		for(int i=1;i<=n;i++)//距离为0初始化 
			f[i][0]=a[i];
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
	vector<node>v;
	map<int,int>mp;

	int ok=0;

	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
		if(b[i]>a[i])ok=1;
	}
	cin>>m;
	for(int i=1;i<=m;i++){
		int x;cin>>x;
		mp[x]++;
	}

	if(ok)return NO();

	st.init();

	p[0].first=INF;

	for(int i=1;i<=n;i++)
	{
		while(p[tot].first<b[i])
		{
			v.push_back({p[tot].first,p[tot].second,i-1});
			tot--;
		}
		if(b[i]<p[tot].first)p[++tot]={b[i],i};
	}
	while(tot)
	{
		v.push_back({p[tot].first,p[tot].second,n});
		tot--;
	}

	for(auto [fl,l,r]:v)
	{
		cout<<fl<<" "<<l<<" "<<r<<endl;
		int x=st.query(l,r);
		cout<<x<<endl;
		if(x>fl)
		{
			if(mp.count(fl))mp[fl]--,cout<<"ok"<<endl;
			// else return NO();
			else cout<<"No"<<endl;
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
1 2 3 4 5 6 7 8 9 

13
7 9 4 5 3 3 3 6 8 10 3 2 5
5 3 1 5 3 2 2 5 8 5 1 1 5
8
1 5 3 5 4 2 3 1


5 1 8
3 2 2
1 3 3 
3 5 5
2 6 7
	8 9 9
5 10 13
1 11 12


1 3 3 ok
3 2 3 ok
2 6 7 ok
3 5 7
5 1 8 ok
1 11 12 ok
5 10 13 ok
8 9 13
*/