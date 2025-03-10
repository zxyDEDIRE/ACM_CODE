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
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
void solve()
{
	int n,len=0;
	cin>>n;
	map<int,int>mp;
	for(int i=2;i*i<=n;i++){
		if(n%i==0){
			while(n%i==0){
				mp[i]++;
				len=max(len,mp[i]);
				n/=i;
			}
		}
	}
	if(n>1)mp[n]++,len=max(len,mp[n]);
	vector<int>v(len,1);
	for(auto [x,y]:mp)
	{
		for(int i=0;i<y;i++)
			v[i]*=x;
	}
	int ans=0;
	for(auto i:v)
		ans+=i;
	cout<<ans<<endl;
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
/*
100=10*10=5 5 2 2
5 2 2 2
*/