#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1111;
int p[maxn],a[maxn];
int n;
bool check()
{
	for(int i=1;i<=n;i++)
		if(a[i]==p[i])return 1;
	return 0;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i],a[i]=p[i];
	if(n==1){cout<<-1<<endl;return ;}
	sort(a+1,a+1+n);
	while(check()){
		next_permutation(a+1,a+1+n);
	}
	for(int i=1;i<=n;i++)
		cout<<a[i]<<" ";
	cout<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int __;cin>>__;
	while(__--)solve();
}
/*
2 3 4 1 5
1 2 3 4 5
*/