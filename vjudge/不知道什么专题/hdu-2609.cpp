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
const ull mod=212370440130137957ll;
const ull prime=233317;
const ull base=131;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
int Get_Min(string &p,int n)
{
	int i=0,j=1,k=0;
	while(i<n&&j<n&&k<n)
	{
		if(p[(i+k)%n]==p[(j+k)%n])k++;
		else
		{
			if(p[(i+k)%n]>p[(j+k)%n])i=i+k+1;
			else j=j+k+1;
			if(i==j)i++;
			k=0;
		}
	}
	return min(i,j);
}
ull get_hash(string &s,int tmp)
{
	ull ans=0;
	int n=s.size();
	for(int i=0;i<s.size();i++)
		ans=(ans*base+(ull)s[(i+tmp)%n])%mod+prime;
	return ans;
}
string str;
int n;
void solve()
{
	while(cin>>n)
	{
		set<ull>s;
		for(int i=1;i<=n;i++)
		{
			cin>>str;
			int len=str.size();
			int tmp = Get_Min(str,len);
			s.insert(get_hash(str,tmp));
		}
		cout<<s.size()<<endl;
	}
	
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}