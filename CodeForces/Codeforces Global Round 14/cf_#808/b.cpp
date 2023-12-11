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
int p[maxn];
int n,l,r;
void solve()
{
	map<int,int>mp;
	cin>>n>>l>>r;
	for(int i=1;i<=n;i++)
	{
		if((r-(r%i))<l){
			cout<<"No"<<endl;
			return ;
		}
		p[i]=(r-(r%i));
	}
	cout<<"Yes"<<endl;
	for(int i=1;i<=n;i++)
		cout<<p[i]<<" ";
	cout<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int __;cin>>__;
    while(__--)
        solve();
    return 0;
}