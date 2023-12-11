/*！*/
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
char ch[maxn];
int p[maxn];
int n;
void solve()
{
	cin>>ch+1;
	n=strlen(ch+1);
	for(int i=1;i<=n+100;i++)p[i]=0;
	for(int i=n;i>=1;i--){
		p[i]=ch[n-i+1]-'0';
	}
	int flag=0;
	for(int i=1;i<=n+20;i++)
	{
		p[i+1]+=p[i]/10;
		p[i]%=10;

		if(p[i]>=5)
		{
			p[i+1]++;
			flag=i;
		}
	}
	for(int i=1;i<=flag;i++)
		p[i]=0;
	int t=n;
	while(p[t+1]!=0)t++;
	for(int i=t;i>=1;i--)
		cout<<p[i];
	cout<<endl;
}
signed main(){
 // freopen("in.txt","r",stdin);
 // freopen("out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}