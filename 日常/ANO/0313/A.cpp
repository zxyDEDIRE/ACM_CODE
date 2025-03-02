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
const int maxn=4111;
string p[maxn];
int n;
void solve()
{
	while(cin>>n&&n)
	{
		for(int i=1;i<=n;i++)
			cin>>p[i];
		int length=p[1].size();
		int ok=0;
		for(int len=length;len>=1;len--)
		{
			set<string>s;
			for(int i=0;i+len<=length;i++)
			{
				int flag=1;
				string now=p[1].substr(i,len);
				for(int j=2;j<=n;j++)
					if(p[j].find(now)==string::npos){
						flag=0;
						break;
					}
				if(flag)s.insert(now);
			}
			if(s.size()){
				cout<<*s.begin()<<endl;
				ok=1;
				break;
			}
		}
		if(!ok)cout<<"IDENTITY LOST"<<endl;
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