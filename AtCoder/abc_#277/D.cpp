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
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
map<int,int>mp;
vector<int>v;
int p[maxn];
int n,m,mod;
void solve()
{
	cin>>n>>mod;
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		int x;cin>>x;sum+=x;
		if(!mp.count(x))
			v.push_back(x);
		mp[x]+=x;
		p[i]=0;
	}
	sort(v.begin(),v.end());
	int ans=0;
	for(int i=0;i<v.size();i++)
	{
		p[i]+=mp[v[i]];
		ans=max(ans,p[i]);
		if(i+1<v.size()&&v[i+1]==v[i]+1)
			p[i+1]+=p[i];
	}
	// cout<<ans<<endl;
	if(v.size()>1&&v[0]==0&&v.back()==mod-1)
	{
		int fl=p[v.size()-1];
		for(int i=0;i<v.size()-1;i++)
		{
			if(v[i+1]==v[i]+1)
				ans=max(ans,p[i+1]+fl);
			else break;
		}
	}
	// cout<<ans<<endl;
	cout<<max(0ll,sum-ans)<<endl;
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
/*
3 0 2 5 5 3 0 6 3
5 6 0 0
*/