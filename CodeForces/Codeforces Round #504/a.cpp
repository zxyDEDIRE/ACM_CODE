/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
int n,m;
string a,b;
void solve()
{
	cin>>n>>m;
	cin>>a>>b;
	if(n-1>m){
		cout<<"NO"<<endl;
		return ;
	}
	int flag=0;
	for(int i=0;i<n;i++)
		if(a[i]=='*')flag=1;
	if(flag==0)
	{
		if(a==b)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		return ;
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]=='*')break;
		if(a[i]!=b[i]){
			cout<<"NO"<<endl;
			return ;
		}
	}
	for(int i=n-1,j=m-1;i>=0;i--,j--)
	{
		if(a[i]=='*')break;
		if(a[i]!=b[j]){
			cout<<"NO"<<endl;
			return ;
		}
	}
	cout<<"YES"<<endl;
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

		solve();
	return 0;
}