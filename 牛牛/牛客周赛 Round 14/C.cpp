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
int n,l,r;
void solve()
{
	cin>>n>>l>>r;
	set<char>sa,sb;
	map<char,int>mpa,mpb;
	for(int i=1;i<=n;i++)
		cin>>ch[i];

	int _l=1,_r=1;
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		while(_l<=n)
		{
			if(!sa.count(ch[_l])&&sa.size()==l)break;
			if(sa.size()==l)break;
			mpa[ch[_l]]++;
			sa.insert(ch[_l]);
			_l++;
		}
		while(_r<=n)
		{
			if(!sb.count(ch[_r])&&sb.size()==r)break;
			mpb[ch[_r]]++;
			sb.insert(ch[_r]);
			_r++;
		}
		if(sa.size()<l)break;
		ans+=_r-_l+1;
		// cout<<i<<" "<<_l<<" "<<_r<<" "<<_r-_l+1<<" "<<ans<<endl;

		mpa[ch[i]]--;
		if(mpa[ch[i]]==0)sa.erase(ch[i]);
		mpb[ch[i]]--;
		if(mpb[ch[i]]==0)sb.erase(ch[i]);
	}
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
/*
abab
*/