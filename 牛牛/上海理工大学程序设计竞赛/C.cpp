#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
using pdd=pair<double,double>;
using puu=pair<ull,pii>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
ull Seed_1=19260817;
ull Seed_2=91815541;
ull Mod_1=4294967291ull;
ull Mod_2=212370440130137957ll;
ull prime_1=233317ull;
ull prime_2=1998585857ul;
map<puu,vector<int>>mp;
string T="lenovo";
int in[maxn];
int sum=0;
void insert(string&str,int id)
{
	int len=str.size();
	ull now_1=prime_1;
	ull now_2=prime_2;
	int flag=0;
	for(int i=0;i<len;i++)
	{
		now_1=(now_1*Seed_1%Mod_1+str[i])%Mod_1;
		now_2=(now_2*Seed_2%Mod_2+str[i])%Mod_2;
		mp[{now_1,{now_2,i}}].push_back(id);
		if(str.substr(i,6)==T){
			in[id]=i,flag=1;
		}
	}
	sum+=flag;
}
void query(string&str)
{
	int len=str.size(),ans=sum;
	ull now_1=prime_1;
	ull now_2=prime_2;
	for(int i=0;i<len;i++)
	{
		now_1=(now_1*Seed_1%Mod_1+str[i])%Mod_1;
		now_2=(now_2*Seed_2%Mod_2+str[i])%Mod_2;
	}
	for(auto x:mp[{now_1,{now_2,len-1}}])
		if(in[x]<len)ans--;
	cout<<ans<<endl;
}
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int op;string str;
		cin>>op>>str;
		if(op==1)insert(str,i);
		else query(str);
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}
/*
5
1 illvelenovo
1 ilovlenovo
1 ilolenovo
1 ilenovo
2 f


3
1 lenovolenovo
1 lenovo
2 l

*/