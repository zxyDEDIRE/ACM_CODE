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
int f[maxn];
int n,m;
int find(int r){
	return f[r]=f[r]==r?f[r]:find(f[r]);
}
void merge(int l,int r)
{
	while(l<r)
	{
		int x=find(l);
		int y=find(r);
		if(x!=y)f[x]=y;
		l++;
		r--;
	}
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		f[i]=i;
	for(int i=1;i<=m;i++)
	{
		int l,r;
		cin>>l>>r;
		merge(l,r);
	}
	int cnt=0;
	for(int i=1;i<=(n+1)/2;i++)
	{
		int fa=find(n-i+1);
		int fb=find(i);
		if(fa==fb&&i!=n-i+1)cnt+=2;
		else if(fa==fb&&i==n-i+1)cnt++;
	}
	
	// for(int i=1;i<=n;i++)
	// 	cout<<find(i)<<" ";cout<<endl;


	if(cnt==n)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	cout<<cnt<<endl;
}
signed main(){
 freopen("C:\\Users\\tob\\Desktop\\0.in","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		clock_t start, finish;
	start = clock();
	/*******代码*******/
	solve();
	/****************/
	finish = clock();
	cout << "the time cost is" <<\
	double(finish - start) / CLOCKS_PER_SEC;
 fclose(stdin);
//  fclose(stdout);
	return 0;
}