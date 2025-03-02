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
const int maxn=2e6+100;
int f[maxn][23];
int n,q;
inline int find(int r,int t){
	return f[r][t]=(f[r][t]==r)?f[r][t]:find(f[r][t],t);
}
inline void un(int a,int b,int t)
{
	int fa=find(a,t);
	int fb=find(b,t);
	f[fa][t]=fb;
}
inline void merge(int l,int r)
{
	int L=n+(n-r+1);
	for(int i=21;i>=0;i--)
	{
		int t=(1<<i);
		if(r-l+1>=t*2&&l<r)
		{
			un(l,L,i);
			l+=t;
			L+=t;
		}
	}
}
void solve()
{
	cin>>n>>q;
	for(int i=1;i<=n*2;i++)
		for(int j=0;j<=21;j++)
			f[i][j]=i;
	while(q--)
	{
		int l,r;
		cin>>l>>r;
		merge(l,r);
	}
	for(int t=21;t>=1;t--)
	{
		int len=(1<<t-1);
		for(int i=1;i<=n;i++)
		{
			if(f[i][t]==i)continue;
			int l=i;
			int r=find(i,t);
			un(l,r,t-1);
			un(l+len,r+len,t-1);
		}
	}
	for(int i=1;i<=n;i++)
		un(i,n*2-i+1,0);
	// for(int i=1;i<=n*2;i++)
	// 	cout<<find(i,0)<<" ";cout<<endl;

	int cnt=0;
	for(int i=1;i<=n;i++)
		if(find(i,0)==find(n-i+1,0))cnt++;
	if(cnt==n)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	cout<<cnt<<endl;
}
signed main(){
 freopen("C:\\Users\\tob\\Desktop\\0.in","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	clock_t start, finish;
	start = clock();
	/*******代码*******/
	solve();
	/****************/
	finish = clock();
	cout << "the time cost is" <<\
	double(finish - start) / CLOCKS_PER_SEC;
//  fclose(stdout);
	return 0;
}
/*
4 1
2 3

*/