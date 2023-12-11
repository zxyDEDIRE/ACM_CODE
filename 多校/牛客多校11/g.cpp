#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cout.tie(0);
#define int long long
typedef long long ll;
typedef pair<int,int> P;
const int N=2e5+7;
const int mod=998244353;
string s;
void solve()
{
	cin>>s;
	int fl=0;
	int len=s.size()/3;
	int a=0,b=0,c=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='r')a++;
		if(s[i]=='e')b++;
		if(s[i]=='d')c++;
	}
	for(int i=0;i<s.size();i++){
		if(a==len)break;
		if(s[i]=='?')s[i]='r',a++;
	}
	for(int i=s.size()-1;i>=0;i--){
		if(c==len)break;
		if(s[i]=='?')s[i]='d',c++;
	}
	for(int i=0;i<s.size();i++)if(s[i]=='?')s[i]='e';
	a=0,b=0,c=0;
	//cout<<s<<endl;
	for(int i=0;i<s.size();i++){
		if(s[i]=='r')a++;
		if(s[i]=='e')b++;
		if(s[i]=='d')c++;
		if(!(a>=b&&b>=c)){
			cout<<"No"<<endl;
			return;
		}
	}
	cout<<"Yes"<<endl;
}
signed main()
{
	//IOS
	int __=1;
	cin >> __;
	while (__--)
		solve();
}