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
const int maxn=1e6;
map<int,int>mp[20];
int p[maxn];
int t[maxn];
int n,k;
int len(int x){
	int cnt=0;
	while(x)cnt++,x/=10;
	return cnt;
}
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		t[i]=len(p[i]);
		mp[t[i]][p[i]%k]++;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int x=p[i]%k;
		for(int j=1;j<=10;j++)
		{
			x=x*10%k;
			if(!mp[j].count((k-x)%k))continue;
			ans+=mp[j][(k-x)%k];
			if(t[i]==j&&(p[i]%k)==(k-x)%k)ans--;
		}
	}
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
//922337204 1000000000 994305000