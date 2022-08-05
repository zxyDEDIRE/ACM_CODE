#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
map<string,int>mp;
const int maxn=1e4;
string s;
int n;
int main()
{
	cin>>s;
	int len=s.size();
	bitset<maxn>vis;
	mp[s]=1;
	cin>>n;
	while(n--)
	{
		string str;
		cin>>str;
		vis.reset();
		for(int i=0;i<str.size();i++)
		{
			if(vis[i])continue;
			string x;
			
			if(i+len-1<str.size())
			{
				for(int j=0;j<len;j++)
					x+=str[i+j];
			//	cout<<x<<endl;
				if(mp[x])
				{
					for(int j=0;j<len;j++)
					vis[i+j]=1;
					cout<<"Bruce12138";
				}
				else cout<<str[i];
			}
			else cout<<str[i];
		} 
		cout<<endl;
	}
}