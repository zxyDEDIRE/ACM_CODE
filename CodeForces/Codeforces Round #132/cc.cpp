/*
    嵌套变量重复
    特殊样例 0 1 2 n
    数组越界
    开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
string str;
void solve()
{
	cin>>str;
	str[0]='(';
	str.back()=')';
	int cnt=0,s=0;
	for(int i=0;i<str.size();i++)
	{
		if(str[i]=='?')
		{
			if(s==0)s++;
			else cnt++;
		}
		else if(str[i]=='(')s++;
		else if(str[i]==')')
		{

			if(s)s--;
			else
			{
				cnt--;
			}
		}
	}
	int cnta=0,sa=0;
	for(int i=str.size()-1;i>=0;i--)
	{
		if(str[i]=='?')
		{
			if(sa==0)sa++;
			else cnta++;
		}
		else if(str[i]==')')sa++;
		else if(str[i]=='(')
		{
			if(sa)sa--;
			else
			{
				cnta--;
			}
		}
	}


	// cout<<cnt<<" "<<s<<endl;
	// cout<<cnta<<" "<<sa<<endl;
	if(cnt==s&&cnta==sa)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int __;cin>>__;
    while(__--)
        solve();
    return 0;
}
/*
5
??()()
()()??
?(?)
??((??))
?((?))
???(((???)))
yes
yes
yes
no
yes
*/