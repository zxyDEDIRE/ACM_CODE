#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=1e6;
ll n,k;
void solve()
{
	cin>>n>>k;
	ll ans=((0+n-1)*n/2-(n/2))/2;
	if(k>ans)cout<<-1<<"\n";
	else if(k>=ans/2)
	{
		ll flag=ans-k+1;
		for(int i=0;i<n;i++){
			if(i==flag)cout<<1<<" ";
			else if(i==1)cout<<flag<<" ";
			else cout<<i<<" ";
			if(i&1)cout<<"\n";
		}
	}
	else
	{
		ll flag=k;
		for(int i=0;i<n/2;i++)
		{
			ll x=i,y=n-1-i;
			if(x==flag&&flag)cout<<0<<" ";
			else if(x==0&&flag)cout<<flag<<" ";
			else cout<<x<<" ";

			if(y==flag&&flag)cout<<0<<"\n";
			else if(y==0&&flag)cout<<flag<<"\n";
			else cout<<y<<"\n";
		}
	}
//	cout<<endl;
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
0 7
1 6
2 5
3 4
*/
/*
0 3
1 2
0 2 
1 3 
0 1 
2 3 
-1
0 7
1 6
2 5
3 4
1 7
0 6
2 5
3 4
2 7
1 6
0 5
3 4
3 7
1 6
2 5
0 4
4 7
1 6
2 5
3 0
5 7
1 6
2 0
3 4
0 7 
2 3 
4 5 
6 1 
0 6 
2 3 
4 5 
1 7 
0 15
1 14
2 13
3 12
4 11
5 10
6 9
7 8
1 15
0 14
2 13
3 12
4 11
5 10
6 9
7 8
2 15
1 14
0 13
3 12
4 11
5 10
6 9
7 8
3 15
1 14
2 13
0 12
4 11
5 10
6 9
7 8
4 15
1 14
2 13
3 12
0 11
5 10
6 9
7 8
5 15
1 14
2 13
3 12
4 11
0 10
6 9
7 8
6 15
1 14
2 13
3 12
4 11
...*/