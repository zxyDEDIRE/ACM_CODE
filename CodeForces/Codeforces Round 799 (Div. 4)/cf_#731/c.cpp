#include<bits/stdc++.h>
#define pb push_back
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
ll x[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>x[i];
	vector<int>v;
	v.pb(0);
	for(int i=2;i<=n;i++)
	{
		ll t=x[i-1]|x[i];
		t=t^x[i];
		v.push_back(t);
		x[i]=x[i-1]|x[i];
	}
	for(int i=0;i<v.size();i++)
		cout<<v[i]<<" ";
	cout<<"\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int __;
    cin>>__;
//    __=1;
    while(__--)solve();
    return 0;
}
/*
1 2 3 4 5
0 1 0 3 2 

 1
10
11
100
101
*/