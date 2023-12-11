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
const int maxn=1e6;
ll p[maxn];
int n;
ll doit(ll &x)
{
		x=x+x%10;
	return x;
}
void solve()
{
	cin>>n;
	vector<ll>v;
	v.clear();
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		int t=p[i]%10;
		if(t==0)v.push_back(p[i]);
		else if(t==5)v.push_back(p[i]+5);
		else
		{
			while(p[i]%10!=2)doit(p[i]);
		}
	}
	if(v.size()!=0&&v.size()!=n){
		cout<<"No"<<endl;
		return ;
	}
	else if(v.size()==n)
	{
		for(int i=0;i<v.size()-1;i++)
			if(v[i]!=v[i+1]){
				cout<<"No"<<endl;
				return ;
			}
		cout<<"Yes"<<endl;
		return ;
	}

	for(int i=1;i<=n;i++)
		p[i]=p[i]%20;

	// for(int i=1;i<=n;i++)
	// 	cout<<p[i]<<" ";
	// cout<<endl;


	for(int i=1;i<n;i++)
		if(p[i]!=p[i+1]){
			cout<<"No"<<endl;
			return ;
		}
	cout<<"Yes"<<endl;




}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int __;cin>>__;
    while(__--)
        solve();
    return 0;
}
/*
3
102 102 102

*/
/*
0 0 0 0 0 0 0 0 0
1 2 4 8 6 2 4 8 6
2 4 8 6 2 4 8 6 2
3 6 2 4 8 6 2 4 8
4 8 6 2 4 8 6 2 4
5 0 0 0 0 0 0 0 0
6 2 4 8 6 2 4 8 6
7 4 8 6 2 4 8 6 2
8 6 2 4 8 6 2 4 8
9 8 6 2 4 8 6 2 4
*/