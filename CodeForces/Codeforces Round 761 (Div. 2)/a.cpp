/*
    嵌套变量重复
    特殊样例 0 1 2 n
    数组越界
    开long long
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
string s,t;
void solve()
{
	cin>>s>>t;
	int a=0,b=0,c=0;
	vector<char>v;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='a')a++;
		else if(s[i]=='b')b++;
		else if(s[i]=='c')c++;
		else v.push_back(s[i]);
	}
	sort(v.begin(),v.end());

	if(t!="abc"||(t=="abc"&&(!a||!b||!c)))
	{
		sort(s.begin(),s.end());
		cout<<s<<endl;
	}
	else
	{
		
		
		for(int i=1;i<=a;i++)cout<<'a';
			for(int i=1;i<=c;i++)cout<<"c";
				for(int i=1;i<=b;i++)cout<<"b";
					for(auto i:v)cout<<i;
						cout<<endl;
				}
			}
			signed main(){
				ios::sync_with_stdio(false);
				cin.tie(nullptr);cout.tie(nullptr);
				int __;cin>>__;
				while(__--)
					solve();
				return 0;
			}