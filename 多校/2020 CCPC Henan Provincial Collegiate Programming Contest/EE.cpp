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
vector<p(3)>v;
p(2) p[maxn];
int n,k;
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		y++;
		v.push_back({x,1,w});
		v.push_back({y,0,w});
	}
	sort(v.begin(),v.end(),[&](p(3)a,p(3)b){
		if(a[0]!=b[0])return a[0]<b[0];
		return a[1]>b[1];
	});
	int len=0;
	int ans=0;
	int ma=-1;
	for(int j=0;j<v.size();j++)
	{
		auto [x,fl,w]=v[j];
		if(fl==1)
		{
			len++;
			ans^=w;
		}
		else
		{
			len--;
			ans^=w;
		}
		if(j==v.size()-1||(v[j+1][0]!=v[j][0]))
			if(len>=k)
				ma=max(ma,ans);
	}
	cout<<ma<<endl;
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