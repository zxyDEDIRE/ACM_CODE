#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF=1e9;
const int maxn=1e6;
map<int,int>mp;
int p[maxn];
int n,cnt;
void solve()
{
	cin>>n;
	if(n>cnt)cout<<"No"<<endl;
	else
	{
		cout<<"Yes"<<endl;
		for(int i=1;i<=n;i++)
		cout<<p[i]<<" ";
		cout<<endl;
	}
}
signed main()
{
	p[1]=1;cnt=0;
	for(int i=2;;i++){
		p[i]=p[i-1]*3;
		if(p[i]>INF){
			break;
		}
		cnt++;
	}
	int __;
	cin>>__;
	while(__--)solve();
}
/*
1 3 9  27 81 243
2 6 18 54
*/
