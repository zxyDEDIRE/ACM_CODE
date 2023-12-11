#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e3+100;
using PLL=pair<ull,ull>;
class StringHash{
public:
	ull Mod_Pool[5]={29123,998244353,1000000009,4294967291ull,212370440130137957ll};
	ull Prime_Pool[3] = {233317ull,1998585857ul,23333333333ul};
	ull seed[4]={911,146527,19260817,91815541};
	ull mod=212370440130137957ll;
	ull prime=233317;
	ull base=131;
	vector<ull>h;
	vector<ull>bas;
	StringHash():h(1),bas(1,1),base(131){}
	StringHash(int x,int y):h(1),bas(1,1){base=seed[x];mod=Mod_Pool[y];}
	void push_back(char ch){
		h.push_back((h.back()*base+ch)%mod + prime);
		bas.push_back(bas.back()*base%mod);
	}
	ull get(int l,int r){
		return (h[r]-h[l-1]*bas[r-l+1]%mod+mod)%mod;
	}
};	
int a[maxn];
ll n,k,p;
void solve()
{
	cin>>n>>k>>p;
	map<PLL,bool>mp;

	k=min(k,n);
	ll ans=0;
	ll F=1;
	for(int i=2;i<=k;i++)
		F=(F*i)%p;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j)continue;
			if(i<j)
			{
				for(int t=1;t<=n;t++)
					if(t<i)a[t]=t;
					else if(t>j)a[t]=t;
					else if(t==j)a[t]=i;
					else a[t]=t+1;
			}
			else
			{
				for(int t=1;t<=n;t++)
					if(t<j)a[t]=t;
					else if(t>i)a[t]=t;
					else if(t==j)a[t]=i;
					else a[t]=t-1;
			}

			StringHash H(3,2);
			StringHash h(2,3);
			for(int t=k+1;t<=n;t++)
				H.push_back(a[t]),h.push_back(a[t]);
			ull now1=H.get(1,n-k);
			ull now2=h.get(1,n-k);
			PLL now={now1,now2};
			if(!mp.count(now))(ans+=F)%=p,mp[now]=1;
		}
	}
	StringHash H(3,2);
	StringHash h(2,3);
	for(int t=k+1;t<=n;t++)
		H.push_back(t),h.push_back(t);
	ull now1=H.get(1,n-k);
	ull now2=h.get(1,n-k);
	PLL now={now1,now2};
	if(!mp.count(now))(ans+=F)%=p,mp[now]=1;
	cout<<ans<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	for(int i=1;i<=__;i++){
		cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}
/*
3 1 4 ok
3 4 1 ok
3 4 2 ok
3 4 3 ok
1 2 3 ok
3 2 4 ok
3 2 3 ok
4 2 3 ok
2 4 3 ok
*/