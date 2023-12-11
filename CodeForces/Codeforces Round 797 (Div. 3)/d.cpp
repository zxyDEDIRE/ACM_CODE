#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
int p[maxn];
string str;
int n,k;
void solve()
{
	cin>>n>>k>>str;
	for(int i=0;i<n;i++)
	{
		if(str[i]=='B')p[i+1]=1;
		else p[i+1]=0;
		p[i+1]+=p[i];
	}
	int mi=n;
	// for(int i=1;i<=n;i++)
	// 	cout<<p[i]<<" ";
	// cout<<endl;
	for(int i=1;i+k-1<=n;i++)
	{
		int t=p[i+k-1]-p[i-1];
		//cout<<p[i+k-1]<<" "<<p[i-1]<<endl;
		mi=min(mi,k-t);
	}
	cout<<mi<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int __;cin>>__;
    while(__--)
    solve();
    return 0;
}
/*
1
5 3
BBWBW
*/