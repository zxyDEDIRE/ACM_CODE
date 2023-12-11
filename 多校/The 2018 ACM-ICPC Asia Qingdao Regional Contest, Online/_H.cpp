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
string s,t;
int n;
void solve()
{
	cin>>s>>t;
	n=s.size();
	string str=string(n,'a');
	deque<int>a,b,li;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='a'&&t[i]!='a')a.push_back(i);
		if(t[i]=='a'&&s[i]!='a')b.push_back(i);
		if(s[i]!='a'&&t[i]!='a')li.push_back(i);
	}

	while(a.size()&&b.size())
		a.pop_front(),b.pop_front();

	auto nt=[&](char a,char b)->char{
		char x='a';
		while(x==a||x==b)
			x++;
		return x;
	};

	while(!a.empty())
	{
		if(!li.size())
		{
			if(a.size()>=2)
			{
				int x=a.back();a.pop_back();
				
			}
		}
	}
	while(!b.empty())
	{

	}
}
signed main(){
 // freopen("data.in","r",stdin);                                   
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	for(int i=1;i<=__;i++){
		cout<<"Case "<<i<<": ";
		// cout<<endl;
		solve();
	}
	return 0;
}
/*
1
acccac
cccccb
a    b

aaaaa
blob:https://github.com/7e734113-9503-4331-b719-3819568f3494
*/