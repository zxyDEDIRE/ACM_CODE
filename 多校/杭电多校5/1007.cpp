/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int INF=0x3f3f3f3f;
const int maxn=1e6;
int num[maxn];
int p[maxn];
int a[maxn];
int n,k;
int find(int r){
	return p[r]=p[r]==r?p[r]:find(p[r]);
}
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		p[i]=i,num[i]=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		int fa=find(a[i]);
		int fb=find(i);
		if(fa!=fb)
		{
			p[fa]=fb;
			num[fb]+=num[fa];
		}
	}
	vector<int>v;
	for(int i=1;i<=n;i++)
		if(i==p[i]){
			if(num[i]>1)
			v.push_back(num[i]);
		}
	cout<<endl;
}
signed main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}
/*
2 5 1 3 4
T 2
5=p[2] x<T


T 1 4 5 
P 2 3

T 1 5 3
P 2 4

T 2 3 4
P 5 1

T 1 2 4
P 3 5

T 2 3 5
P 1 4
*/