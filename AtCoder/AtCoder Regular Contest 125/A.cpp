/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
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
int s[maxn];
int t[maxn];
int n,m;
void solve()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>s[i];
	for(int i=0;i<m;i++)
		cin>>t[i];
	int ans=0;
	int now=0;
	for(int i=0;i<m;i++)
	{
		int len=0;
		while(s[(now-len+n)%n]!=t[i]&&s[(now+len)%n]!=t[i]&&len<=n)
			len++;
		if(len>=n){cout<<-1<<endl;return ;}
		ans+=len+1;
		// cout<<i<<" "<<now<<" "<<s[now]<<" "<<len<<endl;;
		if(s[(now-len+n)%n]==t[i])now=(now-len+n)%n;
		else if(s[(now+len)%n]==t[i])now=(now+len)%n;
	}
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}