/*
    嵌套变量重复
    特殊样例 0 1 2 n
    数组越界
    开long long
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
ll p[maxn];
map<int,int>mp;
int n;
void solve()
{
	cin>>n;
	int ans=0;
	for(int i=1;i<=18;i++)
	{
		if(p[i]>n)break;
		ans=i;
	}
	cout<<ans<<" "<<p[ans]<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    p[1]=2;
    for(int i=2;i<=18;i++)
    	p[i]=p[i-1]*2;

    for(int i=1;i<=18;i++)
    	p[i]--;

    int __;cin>>__;
    while(__--)
        solve();
    return 0;
}