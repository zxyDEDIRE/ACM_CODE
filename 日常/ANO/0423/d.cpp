#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e6;
int a[maxn],b[maxn];
int p[maxn],q[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)q[i]=0;
	for(int i=1;i<=n;i++)
		cin>>a[i],p[a[i]]=0,q[a[i]]++;
	for(int i=1;i<=n;i++)
		cin>>b[i];
	int l=1;
	for(int i=1;i<=n;i++)
	{
		if(l>n+1){
			cout<<"NO"<<endl;
			return ;
		}
		if(b[i]!=a[l])
		{
			if(p[b[i]]&&b[i-1]==b[i]){
				p[b[i]]--;
				continue;
			}
			while(b[i]!=a[l]&&l<=n){
				p[a[l]]++;
				l++;
			}
			if(a[l]!=b[i]){
				cout<<"NO"<<endl;
				return ;
			}
			l++;
		}
		else if(b[i]==a[l])
		{
			l++;
		}
	}
	cout<<"YES"<<endl;
}
signed main(){
	int __;cin>>__;
	while(__--)solve();
}
/*
1
6
1 2 4 2 1 2
1 4 2 2 1 2
4 2 2 1 1 2
4 2 1 1 2 2
4 1 1 2 2 2

4 2 2 1 1 2
4 2 1 1 2 2 
4 1 1 2 2 2 


1
6
1 2 4 2 1 2
4 1 1 2 2 2 

1
8
2 2 3 4 2 4 3 2
2 3 4 2 4 3 2 2
3 4 2 2 4 3 2 2
4 2 2 4 3 3 2 2

4 2 2 4 3 3 2 2
*/