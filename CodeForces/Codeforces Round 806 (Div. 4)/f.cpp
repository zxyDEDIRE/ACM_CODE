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
vector<int>v;
int n;
void solve()
{
	cin>>n;
	v.clear();
	for(int i=1;i<=n;i++){
		cin>>p[i];
		if(p[i]<i)v.push_back(p[i]);
	}
	sort(v.begin(),v.end());
	int ans=0;
	for(int i=n;i>=1;i--)
	{
		if(p[i]<i)
		{
			int fl=upper_bound(v.begin(),v.end(),i)-v.begin();
			ans+=max(0ll,(int)(v.size()-fl));
		}
	}
	cout<<ans<<endl;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}