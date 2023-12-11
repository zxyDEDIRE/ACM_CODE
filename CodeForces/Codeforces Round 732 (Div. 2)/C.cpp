/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
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
int a[maxn];
int p[maxn];
int t[maxn];
int n;
void solve()
{
	cin>>n;
	map<int,vector<int>>mpa,mpb;
	set<int>s;
	for(int i=1;i<=n;i++)
		cin>>p[i],a[i]=p[i],t[i]=0;
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		s.insert(p[i]);
		mpa[p[i]].push_back(i);
		mpb[a[i]].push_back(i);
	}
	for(auto x:s)
	{
		auto &va=mpa[x];
		auto &vb=mpb[x];
		pii a={0,0};
		pii b={0,0};
		for(auto i:va)
			if(i&1)a.first++;
			else a.second++;
		for(auto i:vb)
			if(i&1)b.first++;
			else b.second++;
		if(a.first==b.first&&a.second==b.second);
		else{
			cout<<"No"<<endl;
			return ;
		}
	}
	cout<<"Yes"<<endl;
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
/*
1
5
4 4 2 1 1
*/