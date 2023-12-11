/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
map<int,pii>mp;
int p[maxn];
int n,len,sum;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		sum=0;
		cin>>len;
		for(int j=1;j<=len;j++)
			cin>>p[j],sum+=p[j];
		for(int j=1;j<=len;j++)
			if(mp.count(sum-p[j])){
				cout<<"YES"<<endl;
				cout<<mp[sum-p[j]].first<<" "<<mp[sum-p[j]].second<<"\n"<<i<<" "<<j<<endl;
				return ;
			}
		for(int j=1;j<=len;j++)
			mp[sum-p[j]]={i,j};
	}
	cout<<"NO"<<endl;
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