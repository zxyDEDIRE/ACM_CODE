#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5;
int p[maxn],cnt;
int n,m,t,x,fl;
signed main(){
	cin>>n>>m;t=-m;
	for(int i=1;i<=n;i++)
	{
		fl=(i&1)?1:-1;
		t=(i&1)?t+m+1:t+m-1;
		for(int j=1;j<=m;j++){
			cin>>p[t];
		//	cout<<t<<" ";
			t+=fl;
		}
	//	cout<<endl;
	}
	for(int i=1;i<=n*m;i++)
		cout<<p[i]<<" ";
}