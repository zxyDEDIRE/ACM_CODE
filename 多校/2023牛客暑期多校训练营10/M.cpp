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
int a,b,c;
char ch;
vector<int> f(int x)
{
	vector<int>v;
	// v.push_back(x);
	string now = to_string(x);
	string s =  "";
    for(int j=1;j<=9;j++)
    {
        string t = (char)('0'+j)+now;
        v.push_back(stoll(t));
    }
	for(int i=0;i<now.size();i++)
	{
		s+=now[i];
		for(int j=0;j<=9;j++)
		{
			string t=s+(char)('0'+j);
			for(int k=i+1;k<now.size();k++)
				t+=now[k];
			v.push_back(stoll(t));
		}
	}
	return v;
}
void out(int a,int b,int c)
{
	cout<<"Yes"<<endl;
	cout<<a<<" + "<<b<<" = "<<c;
}
void solve()
{
	cin>>a>>ch>>b>>ch>>c;
	if(a+b==c){
		cout<<"Yes"<<endl;
		cout<<a<<" + "<<b<<" = "<<c;
		return ;
	}
	vector<int>_a = f(a);
	vector<int>_b = f(b);
	vector<int>_c = f(c);
	for(auto i:_a)
		if(i+b==c)
			return out(i,b,c);
	for(auto i:_b)
		if(a+i==c)
			return out(a,i,c);
	for(auto i:_c)
		if(a+b==i)
			return out(a,b,i);
	cout<<"No";
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
1 + 2 = 23
*/