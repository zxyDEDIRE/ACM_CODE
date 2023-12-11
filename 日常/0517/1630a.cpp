#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=1e6;
ll n,k;
void solve()
{
	cin>>n>>k;
	if(k==n-1&&n==4)cout<<-1<<endl;
	else if(k<n-1)
	{
		int flag=k;
		for(int i=0;i<n;i+=2)
		{
			ll x=i;
			ll y=n-i-1;

			if(x==flag)cout<<0<<" ";
			else if(x==0)cout<<flag<<" ";
			else cout<<x<<" "; 

			if(y==flag)cout<<0<<endl;
			else if(y==0)cout<<flag<<endl;
			else cout<<y<<endl;
		}
	}
	else if(k==n-1)
	{
		for(int i=0;i<n/2;i++){
			int x=i;
			int y=n-1-i;
			if(x==0)cout<<n-2<<" ";
			else if(x==3)cout<<0<<" ";
			else cout<<x<<" ";

			if(y==n-2)cout<<3<<endl;
			else if(y==3)cout<<0<<endl;
			else cout<<y<<endl;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;
	cin>>__;
//    __=1;
	while(__--)solve();
	return 0;
}
/*
14 15
1 3
2 13
0 12
4 11
5 10
6 9
7 8

0 1
2 3
4 5
6 7
8 9
10 11
12 13
14 15
*/