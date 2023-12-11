/*
    嵌套变量重复
    特殊样例 0 1 2 n
    数组越界
    开long long
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
int p[maxn];
int n,m,k;
void solve()
{
	cin>>n>>m>>k;
	for(int i=1;i<=k;i++)
		cin>>p[i];
	if(n>m)swap(n,m);

	int a=0,b=0;
	int fa=0,fb=0;
	if(m%2==0)fa=1;
	if(n%2==0)fb=1;
	for(int i=1;i<=k;i++)
	{
		if((m&1)&&p[i]>=3*n)fa=1;
		if((n&1)&&p[i]>=3*m)fb=1;
		if(p[i]>=2*n)
		{
			a+=p[i]/n;
		}
		if(p[i]>=2*m)
		{
			b+=p[i]/m;
		}
	}
	//cout<<a<<" "<<b<<" "<<endl;
	if((a>=m&&fa)||(b>=n&&fb)){
		cout<<"Yes"<<endl;
		return ;
	}
	cout<<"No"<<endl;
		
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int __;cin>>__;
    while(__--)
        solve();
    return 0;
}