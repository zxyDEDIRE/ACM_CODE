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
int p[maxn],a[maxn];
int n,k,ans,sum;
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		a[i]=p[i];
		sum+=a[i];
	}
	sort(a+1,a+1+n);
	ans=k/sum*n;
	k=k%sum;
	int fl=n;
	while(1)
	{
		int flag=0;
		while(a[fl]>k&&fl>=1)sum-=a[fl],fl--;
		if(sum==0)break;
		if(k>=sum)
		{
			flag=1;
			ans+=k/sum*fl;
			k=k%sum;
		}
		else
		{
			for(int i=1;i<=n;i++)
				if(k>=p[i])ans++,k-=p[i],flag=1;
		}
		if(!flag)break;
	}
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}