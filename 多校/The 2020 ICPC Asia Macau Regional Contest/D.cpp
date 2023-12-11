#include<bits/stdc++.h>
using namespace std;
#define double long double
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
double atk=0;
double atk_rate=0;
double crit_rate=5;
double crit_dmg_rate=50;
string str;
void solve()
{
	string fl_a_r = "ATK Rate";
	string fl_a = "ATK";
	string fl_c_d_r = "Crit DMG Rate";
	string fl_c_r = "Crit Rate";
	for(int i=1;i<=25;i++)
	{
		getline(cin,str);
		if(str.find(fl_a_r)!=string::npos)
		{
			string now;
			int fl=0;
			for(auto i:str)
			{
				if(i=='+')fl=1;
				else if(fl)now=now+i;
			}
			now.pop_back();
			atk_rate+=stold(now);

		}
		else if(str.find(fl_a)!=string::npos)
		{
			string now;
			int fl=0;
			for(auto i:str)
			{
				if(i=='+')fl=1;
				else if(fl)
					now=now+i;
			}
			atk+=stold(now);
		}
		else if(str.find(fl_c_d_r)!=string::npos)
		{
			string now;int fl=0;
			for(auto i:str)
			{
				if(i=='+')fl=1;
				else if(fl)now=now+i;
			}
			now.pop_back();
			crit_dmg_rate+=stold(now);
		}
		else if(str.find(fl_c_r)!=string::npos)
		{
			string now;int fl=0;
			for(auto i:str)
			{
				if(i=='+')fl=1;
				else if(fl)now=now+i;
			}
			now.pop_back();
			crit_rate+=stold(now);
		}
		// if(i%5==0)
		// {
		// 	atk = 1500 * (1 + atk_rate*0.01);
		// }
	}
	atk = 1500 * (1 + atk_rate*0.01) + (atk);
	crit_rate=min((double)1.0,crit_rate*0.01);
	double ans= atk*(1- crit_rate ) + atk * (1 + crit_dmg_rate*0.01 ) * crit_rate;
	cout<<fixed<<setprecision(40)<<ans<<'\n';
	// string str="1.111";
	// double ans=stold(str);
	// cout<<ans<<endl;
	
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}