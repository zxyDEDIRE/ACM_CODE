#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF=0x3f3f3f3f;
const int maxn=1e6;
int p[maxn];
int n,d;
void solve()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>p[i];
	p[0]=1;
	p[n+1]=d;
	//µÚÒ»ÖÖ 
	int mia=INF,mib=INF;
	for(int i=2;i<n;i++)
	{
		mib=min(mib,max(mia,(p[i+1]-p[i-1]-1)/2));
		mia=min(mia,min(p[i]-p[i-1]-1,p[i+1]-p[i]-1));
	}
	//i=1
	
//	if(p[1]==1){
//		mia=min(mia,(p[2]-p[1]-1));
//		mib=min(mib,max(mia,mia));
//	}
//	else {
		mia=min(mia,min(p[1]-1,p[2]-p[1]-1));
		mib=min(mib,max(mia,(p[2]-1)/2));
//	}
	//i=n
	if(p[n]==d){
		mia=min(mia,p[n]-p[n-1]-1);
		mib=min(mib,max(mia,mia));
	}
	else{
		mia=min(mia,min(d-p[n]-1,p[n]-p[n-1]-1));
		mib=min(mib,max(mia,(d-p[n-1]-1)/2));
	}
	
	
	cout<<mia<<" "<<mib<<endl;
	int ans=max(mia,mib);
	
	
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int __;cin>>__;
	while(__--)solve();
}
/*
3 2 5 6 1 4
*/

