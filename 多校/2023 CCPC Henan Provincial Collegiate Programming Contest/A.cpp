#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
int vis[111];
string str;
int n;
void solve()
{
	cin>>str;
	n=str.size();
	memset(vis,0,sizeof(vis));
	for(int i=0;i<n-1;i++)
	{
		int tmp=str[i]-'a';
		if(vis[tmp]){
			
			break;
		}
		vis[tmp]=1;
		int l=i+1;
		int r=n-1;
		int flag=1;
		while(l<=r)
		{
			if(str[l]!=str[r]){
				flag=0;
				break;
			}
			l++,r--;
		}
		if(flag){
			cout<<"HE\n";
			return ;
		}
	}
cout<<"NaN\n";
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}