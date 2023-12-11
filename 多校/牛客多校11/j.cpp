/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+10;
int num[maxn];
int p[maxn];
int a[maxn];
int n;
int find(int r){
	return p[r]=p[r]==r?p[r]:find(p[r]);
}
void YES(){
	cout<<"Yes"<<endl;
}
void NO(){
	cout<<"No"<<endl;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],p[i]=i,num[i]=1;
	a[n+1]=a[1];
	p[n+1]=1;
	for(int i=1;i<=n;i++)
	{
		if(a[i+1]>=a[i])
		{
			int fa=find(i);
			int fb=find(i+1);
			p[fa]=fb;
			num[fb]+=num[fa];
		}
	}
	for(int i=1;i<=n;i++)
		if(num[i]==n)
		return YES();
	return NO();
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}
/*
1
3
0 2 0
*/