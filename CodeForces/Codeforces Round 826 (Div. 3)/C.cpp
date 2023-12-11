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
int n;
int ok(int tmp)
{
	int len=0;
	int sum=0;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(sum+p[i]>tmp)return 0;
		if(sum+p[i]==tmp)
		{
			ans=max(ans,len+1);
			sum=len=0;
		}
		else sum+=p[i],len++;
	}
	if(sum!=0)return 0;
	return ans;
}
void solve()
{
	cin>>n;
	int ans=n;
	int sum=0;
	int tot=0;
	for(int i=1;i<=n;i++)
		cin>>p[i],tot+=p[i];
	for(int i=1;i<=n;i++)
	{
		sum+=p[i];
		if(tot%sum==0)
		{
			int t=ok(sum);
			if(t)ans=min(ans,t);
		}
	}
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