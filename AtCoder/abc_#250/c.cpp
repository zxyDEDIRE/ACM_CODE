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
const int maxn=1e6;
map<int,int>mp;
int p[maxn];
int t[maxn];
int n,m;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		p[i]=i,t[i]=i;
	while(m--)
	{
		int x;cin>>x;
		if(p[x]!=n)
		{
			int a=p[x],b=a+1;//xia biao
			swap(t[a],t[b]);
			p[t[a]]=a;
			p[t[b]]=b;
		}
		else
		{
			int a=p[x],b=a-1;
			swap(t[a],t[b]);
			p[t[a]]=a;
			p[t[b]]=b;
		}
	}
	for(int i=1;i<=n;i++)
		cout<<t[i]<<" ";cout<<endl;
}
signed main(){
//  freopen("in1.txt","r",stdin);
//  freopen("out1.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}