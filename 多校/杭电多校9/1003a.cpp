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
int p[maxn];
int a[maxn];
int n,q;
void solve()
{
	cin>>n>>q;
	vector<int>a,b;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	int s=1;
	p[n+1]=n+1;
	for(int i=2;i<=n+1;i++)
	{
		if(p[i]<p[s])continue;
		else
		{
			if(s!=i-1)
			{
				a.push_back(s);
				b.push_back(i-1);
			}
			s=i;
		}
	}
	while(q--)
	{
		int l,r;
		cin>>l>>r;
		int fl=lower_bound(a.begin(),a.end(),l)-a.begin();


		int fr=lower_bound(b.begin(),b.end(),r)-b.begin();
	}
}
signed main(){
//  freopen("in1.txt","r",stdin);
//  freopen("out1.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
1 2 3 4 5 6 7 8 9 10

3 7 9 2 6 4 5 8 10 1
3 7 2 6 4 5 8 9 1 10
2 6 1
4 9 2


7 9 2 6 4
7 2 6 4 9



1
10 2 1
1 2 3 4 5 1 2 3 4 5
*/