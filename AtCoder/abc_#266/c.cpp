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
const int maxn=1e6;
int p[10][2];
double f(int x,int y)
{
	if(p[x][1]-p[y][1]==0)return INF;
	if(p[x][0]-p[y][0]==0)return 0;
	double ans=1.0*(p[y][1]-p[x][1])/(p[y][0]-p[x][0]);
	return abs(ans);
}
int A()
{
	double a=f(2,1);
	double b=f(3,1);
	double c=f(4,1);
	//cout<<a<<" "<<b<<" "<<c<<endl;
	if(a>b&&b>c)return 0;
	if(c>b&&b>a)return 0;
	return 1;
}
int B()
{
	double a=f(1,2);
	double b=f(4,2);
	double c=f(3,2);
	//cout<<a<<" "<<b<<" "<<c<<endl;
	if(a>b&&b>c)return 0;
	if(c>b&&b>a)return 0;
	return 1;
}
void solve()
{
	for(int i=1;i<=4;i++)
		cin>>p[i][0]>>p[i][1];
	if(A())cout<<"No"<<endl;
	else if(B())cout<<"No"<<endl;
	else cout<<"Yes"<<endl;
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