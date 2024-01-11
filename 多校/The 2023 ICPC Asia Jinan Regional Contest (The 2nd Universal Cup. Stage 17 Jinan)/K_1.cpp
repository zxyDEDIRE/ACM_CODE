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
multiset<int,greater<int>>sa;
multiset<int>sb;
ll lena,lenb,suma,sumb;
int p[maxn];
int n;
ll k;
void insert(int x)
{
	sa.insert(x);
	suma+=x;
	lena++;
}
void bal()
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
ll get()
{
	bal();
	ll mid=*sa.begin();
	return lena*mid-suma + sumb-lenb*mid;
}
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>p[i],p[i]-=i;
	sa.clear();
	sb.clear();
	lena=lenb=suma=sumb=0;
	int ans=1;
	for(int r=1,l=1;r<=n;r++)
	{
		// cout<<r<<endl;
		insert(p[r]);
		// cout<<"l:"<<l<<" \tr:"<<r<<" "<<sa.size()<<" "<<sb.size()<<endl;
		while(get()>k)
		{
			if(sa.size() && p[l]<=*sa.begin())
			{
				sa.erase(sa.find(p[l]));
				suma-=p[l];
				lena--;
			}
			else
			{
				sb.erase(sb.find(p[l]));
				sumb-=p[l];
				lenb--;
			}
			l++;
		}
		ans=max(ans,r-l+1);

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