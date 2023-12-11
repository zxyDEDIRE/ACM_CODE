/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
using ll=long long;
using pii=pair<int,int>;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
int num[maxn];
int p[maxn];
int n,k,m;
void solve()
{
	cin>>n>>m;
	set<int>s;
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	int l=1,r=1,ans=0;
	for(int i=1;i<=n;i++)
	{
		while(s.size()!=m&&r<=n)
		{
			num[p[r]]++;
			s.insert(p[r]);
			r++;
		}
		if(s.size()==m)
		{
			ans+=n-(r-1)+1;
		}
		num[p[i]]--;
		if(num[p[i]]==0)s.erase(p[i]);
	}
	cout<<ans<<endl;
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
/*
4 3
1 2 2 3
*/