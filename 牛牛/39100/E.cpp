#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6;
#define int long long
vector<int>v;
string str;
int n,k;
int f(int x)
{
	char ch=str[x];
	if(ch>='a'&&ch<='z')return 0;
	else return 1;
}
signed main()
{
	cin>>n>>k;
	cin>>str;
	str=' '+str;
	int ans=0;
	int fl=0,len=0;
	int flag=0;
	for(int i=1;i<=n;i++)
	{
		if(f(i))
		{
			if(fl==0)
			{
				if(len&&flag)v.push_back(len);
				fl=1;
				len=1;
			}
			else
				len++;
			flag=1;
		}
		else
		{
			if(fl==0)
				len++;
			else
			{
				if(len)ans+=4*(len-1);
				fl=0;
				len=1;
			}
		}
	}
	if(fl==1&&len)ans+=4*(len-1);
	// if(fl==0&&len)v.push_back(len);
	sort(v.begin(),v.end());
	for(auto x:v)
	{
		if(x<=k)
		{
			ans+=4;
			k-=x;
		}
	}
	cout<<ans<<endl;
}