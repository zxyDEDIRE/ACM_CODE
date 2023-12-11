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
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=20;
int a[maxn][maxn];
int b[maxn][maxn];
int p[maxn][maxn];
int x[maxn],y[maxn];
int n,m,N,M;
void YES(){
	cout<<"Yes"<<endl;
}
void NO(){
	cout<<"No"<<endl;
}
bool check()
{
	//cout<<"Yes"<<endl;
	int X=1,Y=1;
	for(int i=1;i<=N;i++)
	{
		if(!x[i])continue;
		Y=0;
		for(int j=1;j<=M;j++)
		{
			if(!y[j])continue;
			p[X][++Y]=a[i][j];
		}
		X++;
	}
	// for(int i=1;i<=n;i++)
	// {
	// 	for(int j=1;j<=m;j++)
	// 		cout<<p[i][j]<<" ";
	// 	cout<<endl;
	// }
	// cout<<endl;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(b[i][j]!=p[i][j])
				return false;
	return true;
}
void solve()
{
	cin>>N>>M;
	for(int i=1;i<=N;i++)
		for(int j=1;j<=M;j++)
			cin>>a[i][j];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>b[i][j];
	for(int I=1;I<(1<<N);I++)
	{
		for(int J=1;J<(1<<M);J++)
		{
			int numa=0,numb=0;
			for(int i=1;i<=N;i++)
				if(I&(1<<(i-1)))x[i]=1,numa++;
				else x[i]=0;
			for(int i=1;i<=M;i++)
				if(J&(1<<(i-1)))y[i]=1,numb++;
				else y[i]=0;
			if(numa!=n||numb!=m)continue;
			if(check())return YES();
		}
	}
	return NO();

}
signed main(){
//  freopen("in1.txt","r",stdin);
//  freopen("out1.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
2 3
1 2 3
4 5 6
2 2
1 3
4 6

11
8421
101
*/