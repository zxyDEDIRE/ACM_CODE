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
vector<int>a[10],b[10];
int p[100];
int n,m;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		b[x].push_back(y);
		b[y].push_back(x);
	}
	set<pii>s,t;
	for(int x=1;x<=n;x++)
	{
		for(auto y:b[x])
			s.insert({x,y});
	}
	for(int i=1;i<=n;i++)p[i]=i;
	do{
		t.clear();
		for(int x=1;x<=n;x++)
		{
			for(auto y:a[x])
				t.insert({p[x],p[y]});
		}
		if(s==t){
			cout<<"Yes"<<endl;
			return ;
		}
	}while(next_permutation(p+1,p+9));
	cout<<"No"<<endl;
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