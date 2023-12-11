#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;

const int N=222;
int dis[N][N];
int n;
int st(string &str)
{
	int ans=0;
	for(int i=0;i<str.size();i++)
		ans=ans*10+str[i]-'0';
	return ans;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j)dis[i][j]=1e9+7;
	for(int i=2;i<=n;i++)
		for(int j=1;j<i;j++){
			string str;int x;
			cin>>str;
			if(str=="x")continue;
			x=st(str);
			dis[j][i]=dis[i][j]=x;
		}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	int ma=0;
	for(int i=2;i<=n;i++)
		ma=max(ma,dis[1][i]);
	cout<<ma<<endl;
}
int main(){
	// ios::sync_with_stdio(0);
	// cin.tie(0);cout.tie(0);
	solve();
	return 0;
}