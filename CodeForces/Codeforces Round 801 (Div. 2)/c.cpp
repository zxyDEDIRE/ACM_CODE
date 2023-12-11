#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e3+10;
int mp[maxn][maxn];
int dpa[maxn][maxn];
int dpb[maxn][maxn];
int x[maxn],y[maxn];
int n,m,fl;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		x[i]=0;
		for(int j=1;j<=m;j++)
		{
			cin>>mp[i][j];
			dpa[i][j]=0;
			dpb[i][j]=0;
		}
	}
	if((n+m)%2==0){
		cout<<"NO\n";
		return ;
	}



	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(i==1&&j==1)
			{
				dpa[i][j]=mp[i][j];
				dpb[i][j]=mp[i][j];
			}
			else if(i==1)
			{

				dpa[i][j]=dpa[i][j-1]+mp[i][j];
				dpb[i][j]=dpb[i][j-1]+mp[i][j];
			}
			else if(j==1)
			{
				dpa[i][j]=dpa[i-1][j]+mp[i][j];
				dpb[i][j]=dpb[i-1][j]+mp[i][j];
			}
			else
			{
				dpa[i][j]=max(dpa[i-1][j],dpa[i][j-1])+mp[i][j];
				dpb[i][j]=min(dpb[i-1][j],dpb[i][j-1])+mp[i][j];
			}
		}
	}
	int a=dpa[n][m];
	int b=dpb[n][m];
	if(a>=0&&b<=0)cout<<"yes"<<endl;
	else cout<<"No"<<endl;

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int __;cin>>__;
    while(__--)
    solve();
    return 0;
}
/*
1
1 10
1 1 1 1 1 1 -1 -1 -1 -1
*/