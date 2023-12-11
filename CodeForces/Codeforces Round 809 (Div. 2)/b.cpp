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
int cnt[maxn],fa[maxn];
int p[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cnt[i]=fa[i]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		cnt[p[i]]++;
		if(fa[p[i]]==0)fa[p[i]]=i;
		else
		{
			int len=i-fa[p[i]]-1;
			if(len%2==1)cnt[p[i]]--;
			fa[p[i]]=i;
		}
	}
	for(int i=1;i<=n;i++)
		cout<<cnt[i]<<" ";
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