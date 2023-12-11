#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
vector<int>G;
int a[N];
void slov()
{
	int n;
	cin>>n;
	int rm,lm;
	int len1=0;
	map<int,int>mp;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==1)
	{
		return void(cout<<1<<'\n');
	}
	sort(a+1,a+1+n);
	int cnt=1;
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=a[i-1])len1++;
		else 
		{
			mp[a[i]]++;
			if(mp[a[i]]==1)cnt++;
		}
	}
	int ans=len1-cnt;
	len1-=ans/2;
	cnt+=ans/2;
	cout<<min(len1,cnt)<<'\n';
}
int main()
{
	int t;
	cin>>t;
	while(t--)
		slov();
}
