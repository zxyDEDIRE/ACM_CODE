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
using pii=pair<int,int>;
unordered_map<int,int>MAP[600];
bitset<10000>vis;
pii p[3011];
int n;
int dis(int a,int b){
	auto x=p[a],y=p[b];
	return (x.first-y.first)*(x.first-y.first)+(x.second-y.second)*(x.second-y.second);
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i].first>>p[i].second;
	int cnt=0;
	for(int x=1;x<=n;x++)
	{
		unordered_map<int,vector<int>>mp;
		
		for(int j=1;j<=n;j++)
			if(j!=x)
				mp[dis(x,j)].push_back(j);
		for(auto &[a,v]:mp)
		{
			if(v.size()<2)continue;
			int num=v.size();
			int now=0;
			// for(int i=0;i<=500;i++)
				// MAP[i].clear();
			vis.reset();
			int MA=0,MB=0;
			for(auto &y:v)
			{
				if(p[x].second-p[y].second==0)MA++;
				else if(p[x].first-p[y].first==0)MB++;
				else{
					int k1=(p[x].first-p[y].first);
					int k2=(p[x].second-p[y].second);
					int g=__gcd(k1,k2);
					k1/=g;k2/=g;
					if(k1<0)k1=-k1,k2=-k2;
					if(!vis[k1])MAP[k1].clear(),vis[k1]=1;
					MAP[k1][k2]++;
				}
			}
			for(auto &y:v)
			{
				if(p[x].second-p[y].second==0)now+=(num-MA);
				else if(p[x].first-p[y].first==0)now+=(num-MB);
				else{
					int k1=(p[x].first-p[y].first);
					int k2=(p[x].second-p[y].second);
					int g=__gcd(k1,k2);
					k1/=g;k2/=g;
					if(k1<0)k1=-k1,k2=-k2;
					now+=num-MAP[k1][k2];
				}
			}
			cnt+=now/2;
		}
	}
	cout<<cnt<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
	// cout<<__gcd(2,4)<<endl;
	// cout<<__gcd(-2,-4)<<endl;
 // fclose(stdin);
 // fclose(stdout);
	return 0;
}