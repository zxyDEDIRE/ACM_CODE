#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<double,double>;
const int maxn=1e6;
bitset<maxn>vis;
pii mp[100];
double ma=0x3f3f3f3f;
int n;
double f(double xa,double ya,double xb,double yb)
{
	return (double)sqrt((xa-xb)*(xa-xb)+(ya-yb)*(ya-yb));
}
void dfs(double x,double y,int st,double num)
{
	if(st==n)
	{
		ma=min(ma,num);
		int t=clock();
		if(t>=940)
		{
			cout<<ma<<endl;
			exit(0);
		}
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			dfs(mp[i].first,mp[i].second,st+1,num+f(x,y,mp[i].first,mp[i].second));
			vis[i]=0;
		}
	}
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>mp[i].first;
		cin>>mp[i].second;
	}
	dfs(0,0,0,0.0);
	printf("%.2f",ma);
}
// #include<bits/stdc++.h>
// using namespace std;
// using ll=long long;
// using pii=pair<int,int>;
// const int maxn=50;
// int p[maxn][maxn][maxn];
// pii m[maxn];
// int n;
// int main()
// {
// 	cin>>n;
// 	for(int i=1;i<=n;i++){
// 		cin>>m[i].first;
// 		cin>>m[i].second;
// 	}
// }