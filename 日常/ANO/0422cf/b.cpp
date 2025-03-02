#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
int n,m;
int a[200005],b[200005];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[n-i+1]=1e6-a[i];
	}
	if(n==1){
		cout<<"YES"<<endl;
		return;
	}
	for(int i=1;i<=n;i++){
		if(i!=1&&i!=n){
			if(a[i]-a[i-1]==1){
				continue;
			}
		}
		if(i!=1){
			if(a[i]-a[i-1]>1){
				a[i]--;
				continue;
			}
		}
		if(i!=n){
			if(a[i+1]-a[i]>1){
				a[i]++;
				continue;
			}
		}
	}
	int flag=0;
	// for(int i=1;i<=n;i++){
	// 	cout<<a[i]<<" ";
	// }
	// cout<<endl;
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]!=1){
			flag=1;
			break;
		}
	}
	
	for(int i=1;i<=n;i++){
		if(i!=1&&i!=n){
			if(b[i]-b[i-1]==1){
				continue;
			}
		}
		if(i!=1){
			if(b[i]-b[i-1]>1){
				b[i]--;
				continue;
			}
		}
		if(i!=n){
			if(b[i+1]-b[i]>1){
				b[i]++;
				continue;
			}
		}
	}
	int flag1=0;
	// for(int i=1;i<=n;i++){
	// 	cout<<a[i]<<" ";
	// }
	// cout<<endl;
	for(int i=2;i<=n;i++){
		if(b[i]-b[i-1]!=1){
			flag1=1;
			break;
		}
	}
	if(!flag||(!flag1))cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}
signed main()
{
	int __;
	cin>>__;
	//__=1;
	while(__--)solve();
}