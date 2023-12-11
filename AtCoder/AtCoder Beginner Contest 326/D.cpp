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
void solve()
{
	int n;
	string s,t;
	cin>>n>>s>>t;
	map<int,int>mpa[11],mpb[11];
	char mp[11][11];
	memset(mp, '.',sizeof mp);


	for(int i=0;i<n;i++)
	{
		int j=0;
		while(mpa[j].count(s[i]))j++;
		mp[i][j]=s[i];
		mpa[j][s[i]]=mpb[i][s[i]]=1;
	}


	for(int j=0;j<n;j++)
	{
		cout<<"J "<<j<<endl;
		for(int i=0;i<n;i++)
		{
			int flag=0;
			if(mp[i][j])
			{
				if(mp[i][j]!=t[j]){
					cout<<"No\n";
					return ;
				}
				flag=1;
			}
			else
			{
				if(!mpa[j].count(t[j])&&!mpb[i].count(t[j]))
				{
					flag=1;
					mp[i][j]=t[j];
				}
			}
			if(flag)break;
		}
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			cout<<mp[i][j];
		cout<<endl;
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
/*
AC B
B A C
C
 B
  C
*/