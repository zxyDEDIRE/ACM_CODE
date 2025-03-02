#include<bits/stdc++.h>
using namespace std;
using int64 =long long;
const int mod=998244353;
const int maxn=2e6;
int p[maxn],cnt;
int64 n,ans;
int check(int x)
{
	int t=0;
	for(int i=0;i<=n;i++)
		t+=(i^x);
//	cout<<"t: "<<t<<endl;
	return t;
}
void solve()
{
	cin>>n>>n;
	ans=0;
	for(int i=0;i<=n;i++)cin>>p[i],ans+=p[i];
	int l=0,r=n;
	while(l<=r)
	{
		int mid=(l+r)/2;
		int ok=check(mid);
		if(ok==ans){
			cout<<mid<<endl;
			return ;
		}
		if(ok<ans)l=mid+1;
		else r=mid-1;
	}
	if(check(l)==ans)cout<<l<<endl;
	else if(check(r)==ans)cout<<r<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int __;//cin>>__;
	__=1;
	while(__--)solve();
}
/*
*/