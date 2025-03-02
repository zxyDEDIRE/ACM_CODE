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
int p[maxn];
int n;
void NO(){
	cout<<-1<<endl;
}
void solve()
{
	cin>>n;
	map<int,int>mp;
	for(int i=1;i<=n;i++)
		cin>>p[i],mp[p[i]]++;
	int flag=0;
	while(mp.count(flag))flag++;
	if(mp[flag]==1)return NO();
	if((flag-1)*2>n)return NO();
	// cout<<"flag "<<flag<<endl;

	set<int>s;
	int fa=0;
	int now;
	for(int i=1;i<=n;i++)
	{
		s.insert(p[i]);
		while(s.count(fa))fa++;
		now=i;
		if(fa==flag)break;
	}
	if(fa!=flag)return NO();
	fa=0;
	s.clear();
	for(int i=now+1;i<=n;i++)
	{
		s.insert(p[i]);
	}
	while(s.count(fa))fa++;
	if(fa!=flag)return NO();
	cout<<2<<endl;
	cout<<1<<" "<<now<<"\n"<<now+1<<" "<<n<<endl;
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
8
0 1 7 1 0 1 0 3
*/