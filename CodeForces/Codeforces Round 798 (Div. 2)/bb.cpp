#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1111;
int p[maxn],a[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],p[i]=a[i];
	if(n==1){cout<<-1<<endl;return ;}
	sort(p+1,p+1+n);
	for(int i=1;i<n;i++)
	{
		if(p[i]==a[i])swap(p[i],p[i+1]);
	}
	if(p[n]==a[n])swap(p[n],p[n-1]);
	for(int i=1;i<=n;i++)
		cout<<p[i]<<" ";
	cout<<endl;
}
int main(){
	int __;cin>>__;
	while(__--)solve();
}
/*
1 2 3 4 5
2 1 4 3 5
*/