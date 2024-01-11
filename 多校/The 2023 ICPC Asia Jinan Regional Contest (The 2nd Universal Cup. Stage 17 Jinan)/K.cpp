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

struct node{
	multiset<int,greater<int>>sa;
	multiset<int>sb;
	int lena=0,lenb=0,len=0;
	ll suma=0,sumb=0;
	inline void clear()
	{
		sa.clear();
		sb.clear();
		lena=lenb=len=0;
		suma=sumb=0;
	}
	inline void insert(int& x)
	{
		sa.insert(x);
		len++;
		lena++;
		suma+=x;
	}
	inline ll get()
	{
		int x=mid();
		return 1ll*lena*x-suma + sumb-lenb*x;
	}
	inline int mid()
	{
		if(sa.size()==0)return 0;
		bal();
		int _mid=(len+1)/2;
		// cout<<"_mid "<<_mid<<" ";
		while(lena>_mid)
		{
			int x=*sa.begin();
			sb.insert(*sa.begin());
			sa.erase(sa.begin());
			lena--;
			lenb++;
			suma-=x;
			sumb+=x;
		}
		while(lena<_mid)
		{
			int x=*sa.begin();
			sa.insert(*sb.begin());
			sb.erase(sb.begin());
			lena++;
			lenb--;
			sumb-=x;
			suma+=x;
		}
		return *sa.begin();
	}
	inline void erase(int& x)
	{
		bal();
		// cout<<"erase\n";
		// cout<<sa.size()<<" "<<sb.size()<<endl;
		if(sa.size() && x<=*sa.begin())
		{
			sa.erase(sa.find(x));
			lena--;
			suma-=x;
		}
		else
		{
			sb.erase(sb.find(x));
			lenb--;
			sumb-=x;
		}
		len--;
	}
	inline void bal()
	{
		while(lena > lenb)
		{
			sb.insert(*sa.begin());
			suma-=*sa.begin();
			sumb+=*sa.begin();
			sa.erase(sa.find(*sa.begin()));
			lena--;
			lenb++;
		}
		while(lena < lenb)
		{
			sa.insert(*sb.begin());
			suma+=*sb.begin();
			sumb-=*sb.begin();
			sb.erase(sb.find(*sb.begin()));
			lena++;
			lenb--;
		}
	}
}sa;
int p[maxn];
ll n,k;
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i],p[i]-=i;
	}


	sa.clear();
	ll ans=0,sum=0;
	for(int i=1,r=1;i<=n;i++)
	{

		while(k>=sa.get()&& r<=n)
		{
			ans=max(ans,1ll*sa.len);
			sa.insert(p[r]);
			sum+=p[r];
			r++;
		}
		// cout<<i<<" "<<sa.len<<" "<<sa.get()<<endl;
		if(k>=sa.get())
			ans=max(ans,1ll*sa.len);
		// cout<<i<<" "<<r<<" "<<sa.len<<" "<<sa.mid()<<" ans:"<<ans<<endl;
		sa.erase(p[i]);
		sum-=p[i];
	}
	cout<<ans<<endl;
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
/*
6 0 2 1 -1 5 0
-1 0 1 2 
*/