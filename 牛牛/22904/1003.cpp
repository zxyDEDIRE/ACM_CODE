/*
    嵌套变量重复
    特殊样例 0 1 2 n
    数组越界
    开long long
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
priority_queue<ll>q;
int p[maxn];
int n,m,k;
void solve()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	sort(p+1,p+1+n);
	for(int i=1;i<=min(n,k);i++)
		q.push(p[i]);
	while(m--)
	{
		int fl,x;
		cin>>fl;
		if(fl==1)
		{
			cin>>x;
			q.push(x);
			if(q.size()>k)q.pop();
		}
		else
		{
			if(q.size()<k)cout<<-1<<"\n";
			else cout<<q.top()<<"\n";
		}
	}

}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

        solve();
    return 0;
}