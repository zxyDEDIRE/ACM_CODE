#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+20;
int p[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		p[i]=i;
	for(int i=2;i<n;i++)
	{
		int x=i+i+1;
		int y=sqrt(x);
		if(y*y==x){
			swap(p[i],p[i-1]);
		}
	}
	// for(int i=1;i<n;i++)
	// {
	// 	int x=p[i]+p[i+1];
	// 	int y=sqrt(x);
	// 	if(y*y==x){
	// 		cout<<i<<" "<<x<<"  "<<endl;
	// 	}
	// }
	for(int i=1;i<=n;i++)
		cout<<p[i]<<" ";cout<<endl;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	solve();
	return 0;
}