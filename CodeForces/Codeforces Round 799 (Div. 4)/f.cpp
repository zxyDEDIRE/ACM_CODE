#include<bits/stdc++.h>
#define ios ios::sync_with_stdio(false);cout.tie(0);cout.tie(0);
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
int p[11];
int n,x;
void solve()
{
	cin>>n;
	memset(p,0,sizeof(p));
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		p[x%10]++;
	}
	for(int i=0;i<=9;i++)
	{
		if(!p[i])continue;
		p[i]--;
		for(int j=0;j<=9;j++)
		{
			if(!p[j])continue;
			p[j]--;
			for(int k=0;k<=9;k++)
			{
				if(!p[k])continue;
				int t=i+j+k;
				if(t%10==3){
					cout<<"Yes"<<endl;
					return ;
				}
			}

			p[j]++;
		}
		p[i]++;
	}
	cout<<"No"<<endl;
}
int main()
{	ios
	int __;cin>>__;
	while(__--)solve();
}