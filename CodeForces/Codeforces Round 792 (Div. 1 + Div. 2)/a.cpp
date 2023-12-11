#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
int p[maxn];
int n,m;
void solve()
{
	cin>>n>>m;
	vector<pii>v(m+1);
	for(int i=1;i<=m;i++)p[i]=i;

	int flag=0;
	for(int i=1;i<=n;i++)
	{
		v.clear();
		for(int j=1;j<=m;j++)
		{
			int x;cin>>x;
			v[j].second=j;
			v[p[j]].first=i;
		}
		if(flag==0)
		{
		}
	}
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
321
*/