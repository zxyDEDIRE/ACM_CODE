#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
ll p[maxn];
ll n,ma=0;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i],ma=max(ma,p[i]);
	vector<ll>v;
	for(int i=1;i<=n;i++)
	{
		int l=i-1,r=i+1;
		ll x=p[i],fl=1;
		while(1)
		{
			int t=0;
			if(l>0&&p[l]<=x)x*=2,l--,t++;
			if(r<=n&&p[r]<=x)x*=2,r++,t++;
			if(x>=ma)break;
			if((l<1&&r>n)||t==0){
				fl=0;
				break;
			}
		}
		if(fl)v.push_back(i);
	}
	cout<<v.size()<<endl;
	for(auto i:v)
		cout<<i<<" ";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    solve();
    return 0;
}
/*
1 2 3
*/