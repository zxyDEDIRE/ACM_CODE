#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
int p[maxn],a[maxn];
int n,m;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>p[i];
		a[i]=p[i]+a[i-1];
	}
	int ma=-1;
	for(int i=1;i<=n;i++)
	{
	//	cout<<a[i]<<" "<<ma<<endl;
		if(a[i]==0){
			ma=0;
			continue;
		}
		else ma=max(ma,p[i]);
		if(a[i]>ma&&p[i]>0){
			cout<<"NO"<<endl;
			return ;
		}
	}
	cout<<"YES"<<endl;
}
int main(){
	int __;cin>>__;
	while(__--)solve();
}
/*
-1 1 -1 2
-1 0 -1 1

-1 2 -3 2 -1
-1 1 -2 0 -1

8
3 -2 2 -2 0 -1 3 -2 
3  1 3  2 2  1 4 -2

8
4 -4 3 -2 2 -2 3 -2 
4  0 3  1 3  1 4  1
*/