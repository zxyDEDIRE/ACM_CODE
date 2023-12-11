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
int nxt[maxn];
char s[maxn];
string str;
int len,n,k;
ll ans=0;
void init(int l)
{
	nxt[1]=0;
	for(int i=1;i<=n-l+1;i++)
		s[i]=str[l+i-1];
	s[n-l+2]='\0';
	len=strlen(s+1);
	for(int i=2;i<=len;i++)
	{
		nxt[i]=nxt[i-1];
		while(s[nxt[i]+1]!=s[i]&&nxt[i])
			nxt[i]=nxt[nxt[i]];
		if(s[nxt[i]+1]==s[i])nxt[i]++;
	}
	// for(int i=1;i<=len;i++)
	// {
	// 	if(nxt[nxt[i]])nxt[i]=nxt[nxt[i]];
	// 	else if(nxt[i]>=k);
	// 	else nxt[i]=0;
	// 	if(nxt[i]&&nxt[i]*2<i)ans++;
	// }
	for (int i = 1; i <= len; i++) {
            int y = nxt[i];

            if (nxt[y] >= k)
                nxt[i] = nxt[y];

            if (nxt[i] >= k && i > nxt[i] * 2)
                ans++;
        }
}
void solve()
{
	cin>>str>>k;
	str=" "+str;
	n=str.size()-1;
	for(int i=0;i<n-k*2;i++)
		init(1+i);
	cout<<ans<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}