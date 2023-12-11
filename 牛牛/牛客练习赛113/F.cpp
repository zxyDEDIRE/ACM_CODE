/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
const int maxn=1e6+100;
const int M=1e5+100;
int ff[M+5];
map<int,int>mp;
vector<pii>v;
int p[maxn];
int n;
int ksm(int b,int p){int r=1;b%=mod;while(p){if(p&1)r=(r*b)%mod;p>>=1;b=(b*b)%mod;}return r;}

int x,y;
void Extended_gcd(int a,int b){
    if(b==0){x=1;y=0;}
    else{Extended_gcd(b,a%b);long t=x;x=y;y=t-(a/b)*y;}
}
//计算不大的C(n,m)
int C(int a,int b){
	if(b==0)return 1;
	if(a==0)return 1;
    if(b>a)return 0;b=(ff[a-b]%mod*ff[b])%mod;a=ff[a];
    int c=__gcd(a,b);a/=c;b/=c;Extended_gcd(b,M);x=(x+mod)%mod;
    x=(x*a)%mod;return x;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>p[i];
		mp[p[i]]++;
	}
	ll ans=0;
	for(auto [x,cnt]:mp)
	{
		v.push_back({x,cnt});
		for(int len=1;len<=cnt;len++)
		{
			for(int tot=len+1;tot<=len*2&&tot<=n;tot++)
			{
				// if(tot==len)continue;
				ans+=C(cnt,len)*C(n-cnt,tot-len)%mod;
				// cout<<x<<" "<<len<<" "<<tot</<" "<<C(cnt,len)*C(n-cnt,tot-len)<<endl;
				ans%=mod;
			}
		}
	}
	// cout<<ans<<endl;
	for(int i=0;i<v.size();i++)
	{
		for(int j=1;j<=v[i].second;j++){
			ans+=C(v[i].second,j),ans%=mod;
		}
		for(int j=i+1;j<v.size();j++)
			for(int len=1;len<=min(v[i].second,v[j].second);len++)
			{
				ans-=C(v[i].second,len)*C(v[j].second,len)%mod;
				ans=(ans%mod+mod)%mod;
				// cout<<v[i].first<<" "<<v[j].first<<" "<<len<<" "<<C(v[i].second,len)*C(v[j].second,len)<<endl;
			}
	}
	cout<<ans<<endl;


}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	ff[0]=1;
    for(int i=1; i<=M; i++) //预计算n!
        ff[i]=(ff[i-1]*i)%mod;

		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
5
1 2 2 3 3
1
2
2
3
3
1 2
1 2
1 3
1 3
2 2
2 3
2 3
2 3
2 3
3 3
2 2 1
2 2 3
2 2 3
3 3 1
3 3 2
3 3 2
2 2 3 3
2 2 3 1
2 2 3 1
3 3 2 1
3 3 2 1

10
*/