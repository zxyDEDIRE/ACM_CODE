/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define p(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
int p[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	vector<int>v;
	for(int i=1;i<=n;i++)
	{
		if(p[i+1]>p[i]||p[i-1]>p[i]);
		else v.push_back(p[i]);
	}
	int ans=1;
	while(v.size()>1)
	{
		vector<int>u;
		for(int i=0;i<v.size();i++)
		{
			if(i==0&&v[i+1]>v[i]);
			else if(i==v.size()-1&&v[i-1]>v[i]);
			else if(v[i+1]>v[i]||v[i-1]>v[i]);
			else u.push_back(v[i]);
		}
		v=u;
		ans++;
	}
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}