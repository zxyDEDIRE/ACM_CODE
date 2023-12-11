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
int cnt[maxn];
int p[maxn],t;
int n,k;
void solve()
{
	cin>>n>>k;
	memset(cnt,0,sizeof(int)*100);
	p[0]=1;
	for(t=1;;t++)
	{
		p[t]=p[t-1]*k;
		if(p[t]>1e16)break;
	}
	for(int i=1;i<=n;i++)
	{
		int x;cin>>x;
		for(int j=t;j>=0;j--)
			while(x>=p[j]){
				x-=p[j],cnt[j]++;
			}
	}
	for(int i=0;i<=t;i++)
		if(cnt[i]>1){
			cout<<"NO"<<endl;
			return ;
		}
	cout<<"YES"<<endl;
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