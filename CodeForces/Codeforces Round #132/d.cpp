/*
    嵌套变量重复
    特殊样例 0 1 2 n
    数组越界
    开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int maxn=3e5;
int f[maxn][30];//f[i][j]从i开始2^j长度的最大值 
int p[maxn];
int n,m,q;
void st()
{
	for(int i=1;i<=m;i++)//距离为0初始化 
		f[i][0]=p[i];
	int t=log(m)/log(2)+1;//j定位 
	for(int j=1;j<t;j++)
	{
		for(int i=1;i<=m-(1<<j)+1;i++)
		{
			f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);//f[i][j-1]为f[i][j]的长为2^j-1的前半段，另一段为f[i+(1<<(j-1))][j-1] 
		}
	}
}
int query(int l,int r)
{
	int k=log2(r-l+1);
	return max(f[l][k],f[r-(1<<k)+1][k]);
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
		cin>>p[i];
	st();
	cin>>q;
	while(q--)
	{
		int sx,sy,tx,ty,k;
		cin>>sx>>sy>>tx>>ty>>k;
		if((abs(sx-tx)%k!=0)||(abs(sy-ty)%k!=0)){
			cout<<"No"<<endl;
			continue;
		}
		if(sx<=p[sy]||tx<=p[ty]){
			cout<<"No"<<endl;
			continue;
		}
		if(sy>ty)swap(sy,ty);
		int hi=query(sy,ty);
		if(sx>tx)swap(sx,tx);
		//cout<<hi<<endl;
		if(hi<tx)cout<<"Yes"<<endl;
		else
		{
			int a=(hi-sx)/k;
			a++;
			int H=a*k+sx;
			if(H<=n)cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}
	}
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
        solve();
    return 0;
}
/*
9 0 0 10 3 4 8 11 10 8
0 10 3

4
4 3 4 5 2
*/