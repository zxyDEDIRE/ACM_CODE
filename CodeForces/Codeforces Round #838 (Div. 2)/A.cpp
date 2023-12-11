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
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
int p[maxn];
int n,m,sum;
void solve()
{
	cin>>n;
	int a=0;
	vector<int>v,u;
	sum=0;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i],sum+=p[i];
		if(p[i]&1)v.push_back(p[i]);
		else u.push_back(p[i]);
	}
	if(sum%2==0){
		cout<<0<<endl;
		return ;
	}
	int mi=1e9;
	for(auto i:v)
	{
		int cnt=0;
		while(i&1)
			i/=2,cnt++;
		mi=min(mi,cnt);
	}
	for(auto i:u)
	{
		int cnt=0;
		while(i%2==0)
			i/=2,cnt++;
		mi=min(mi,cnt);
	}
	cout<<mi<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}