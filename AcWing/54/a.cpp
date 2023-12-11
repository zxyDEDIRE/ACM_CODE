#include<bits/stdc++.h>
#define ios ios::sync_with_stdio(false);cout.tie(0);cout.tie(0);
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
string str;
int n;
int a[30],b[30];
int main()
{	ios
	
	cin>>n>>str;

	for(int i=0;i<n;i++)
	{
		if(str[i]>='a')
		{
			a[str[i]-'a']++;
		}
		else
		{
			b[str[i]-'A']++;
		}
	}

	int flag=1;
	for(int i=0;i<26;i++)
	{
		if(!a[i]&&!b[i])flag=0;
	}

	if(!flag)cout<<"NO"<<endl;
	else cout<<"YES"<<endl;

}