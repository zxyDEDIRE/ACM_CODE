#include<bits/stdc++.h>
using namespace std;
#define endl "\n";
const int maxn=2e3;
int p[maxn];
int b[maxn];
int a[maxn];
int rk[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
		p[b[i]]=i;
	}
	for(int i=1;i<=n;i++)
		a[i]=p[a[i]];

	vector<int>ans;
	int x=1;
	while(1)
	{
		int to,flag=0;
		for(int i=n;i>=1;i--)
			if(a[i]!=i){
				to=i;
				flag=1;
				break;
			}
		for(int i=1;i<=n;i++)
		{
			if(a[i]==to){
				to=i;
				break;
			}
		}

		if(!flag)break;
		while(x!=to)
		{
			x=x%n+1;
			ans.push_back(1);
		}

		while(a[x]!=x)
		{
			int y=x%n+1;
			swap(a[x],a[y]);
			swap(x,y);
			ans.push_back(2);
		}
	}
	while(x!=1){
		ans.push_back(1);
		x=x%n+1;
	}
	for(auto i:ans)
		cout<<i;
	cout<<endl;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}
/*
2
3
1 2 3
2 3 1
4
1 2 3 4
2 1 3 4

1 3 4 2

*/