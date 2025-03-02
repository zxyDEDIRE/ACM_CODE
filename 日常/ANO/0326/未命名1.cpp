#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e6;
int a[maxn],b[maxn];
int p[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>b[i];
	int l=1;
	for(int i=1;i<=n;i++)
	{
		cout<<i<<" ";
		if(b[i]!=a[l])
		{
			while(b[i]!=a[l]&&l<=n){
				p[a[l]]++;
				l++;
			}
			if(a[l]!=b[i]){
				cout<<i<<endl;
				cout<<"NO"<<endl;
				
			}
			l++;
		}
		else if(b[i]==a[l])
		{
			if(p[a[l]])i++,p[a[l]]--;
		}
		cout<<l<<endl;
	}
	cout<<"YES"<<endl;
}
signed main(){
	int __;cin>>__;
	while(__--)solve();
}
/*
1
5
1 2 4 2 1
4 2 2 1 1

*/
