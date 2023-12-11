/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define p(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
string str;
int n;
void solve()
{
	cin>>str;
	char a=str[0];
	char b=str.back();
	if(a==b)
	{
		cout<<a<<" ";
		for(int i=1;i<str.size()-1;i++)
			cout<<str[i];
		cout<<" "<<b<<endl;
	}
	else if(a=='b')
	{
		if(str[1]=='b')
		{
			cout<<"b ";
			for(int i=1;i<str.size()-1;i++)
				cout<<str[i];
			cout<<" "<<b<<endl;
		}
		else
		{
			cout<<"b a ";
			for(int i=2;i<str.size();i++)
				cout<<str[i];
			cout<<endl;
		}
	}
	else if(a=='a')
	{
		if(str[1]=='b')
		{
			cout<<"a ";
			for(int i=1;i<str.size()-1;i++)
				cout<<str[i];
			cout<<" b"<<endl;
		}
		else if(str[1]=='a')
		{
			int i=0;
			for(;i<str.size()-2;i++)
			{
				if(str[i]=='a')
					cout<<'a';
				else break;
			}
			cout<<" ";
			for(;i<str.size()-1;i++)
				cout<<str[i];
			cout<<" b"<<endl;
		}
	}
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
3
abababab
abbbb
aabbb
aaa a b
*/