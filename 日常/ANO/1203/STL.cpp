#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
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
	//可以直接这样合并，保证左边的father一定是右边的点
}
inline void merge(int l,int r)
{
	//区间二进制拆分
	int L=n+(n-r+1);
	for(int i=21;i>=0;i--)
	{
		int t=(1<<i);
		if(l+t-1<=r)
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
	for(int i=1;i<=n*2;i++)  //初始化并查集
		for(int j=0;j<=21;j++)  //一共22层并查集
			f[i][j]=i;
	
	//复制反串 ，即T[i]=T[n*2-i]
	for(int i=1;i<=n;i++)
		un(i,n*2-i+1,0);

	while(q--)
	{
		int l,r;
		cin>>l>>r;
		merge(l,r);
	}
	//由上自下 由大区间合并至小区间
	for(int t=21;t>=1;t--)
	{
		int len=(1<<(t-1));
		for(int i=1;i<=n*2;i++)
		{
			if(f[i][t]==i)continue;
			int l=i;
			int r=find(i,t); //因为father一定是右边的点 所有此时的father就是对应的右边的点
			//拆分成两个小区间
			un(l,r,t-1);
			un(l+len,r+len,t-1);
		}
	}

	int cnt=0;
	for(int i=1;i<=n;i++)
		if(find(i,0)==find(i+n,0))cnt++;
	if(cnt==n)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	cout<<cnt<<endl;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

	solve();

	return 0;
}