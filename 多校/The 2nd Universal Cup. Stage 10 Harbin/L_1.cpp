#include<bits/stdc++.h>
using namespace std;
#define endl "\n";
const int maxn=2e3;
int p[maxn];
int b[maxn];
int a[maxn];
int _a[maxn];
int _b[maxn];
int rk[maxn];
int n,cnt;
bool check(vector<int>&ans)
{
	for(auto i:ans)
	{
		if(i==1)
		{
			int x=_a[1];
			for(int i=1;i<n;i++)
				_a[i]=_a[i+1];
			_a[n]=x;
		}
		else
		{
			int x=_a[2];
			for(int i=2;i<n;i++)
				_a[i]=_a[i+1];
			_a[n]=x;
		}
	}
	// for(int i=1;i<=n;i++)
	// 	cout<<_a[i]<<" ";cout<<endl;
	// for(int i=1;i<=n;i++)
	// 	cout<<_b[i]<<" ";cout<<endl;
	for(int i=1;i<=n;i++)
		if(_a[i]!=_b[i])
			return 0;
	return 1;
}
void solve()
{
	// cin>>n;
	n=1000;
	cnt=0;
	for(int i=1;i<=n;i++)
	{
		// cin>>a[i];
		// a[i]=i;
		a[i]=b[i]=i;
	}
	srand(time(0));
	for(int i=1;i<=n;i++)
	{
		int x=rand()%n+1;
		int y=rand()%n+1;
		swap(b[x],b[y]);
	}
	for(int i=1;i<=n;i++)
	{
		// cin>>b[i];
		p[b[i]]=i;
	}
	for(int i=1;i<=n;i++)
	{
		_a[i]=a[i];
		_b[i]=b[i];
	}
	for(int i=1;i<=n;i++)
	{
		a[i]=p[a[i]];
		if(a[i]==i)cnt++;
	}

	// for(int i=1;i<=n;i++)
	// 	cout<<a[i]<<" ";
	// cout<<endl;
	// for(int i=1;i<=n;i++)
	// 	cout<<b[i]<<" ";
	// cout<<endl;
	// for(int i=1;i<=n;i++)
	// 	cout<<a[i]<<" \n"[i==n];
	// cout<<"cnt "<<cnt<<endl;
	// cout<<"S";
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
			if(a[i]==to){
				to=i;
				break;
			}
		// cout<<to<<endl;
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
	// for(auto i:ans)
	// 	cout<<i;
	// cout<<endl;
	cout<<ans.size()<<endl;
	// cout<<check(ans);
	if(!check(ans)){
		cout<<"No\n";
		exit(0);
	}
	if(ans.size()>n*n){
		cout<<"No\n";
		exit(0);
	}
}
signed main(){ 
	// ios::sync_with_stdio(false);
	// cin.tie(0);cout.tie(0);
	// int __;cin>>__;
	// while(__--)
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


22221222112211121111


10
6 4 3 2 1 9 7 8 5 10
*/