#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
queue<int>q;
bitset<maxn>vis;
int n,m,fl,ans,len;
void solve()
{
	cin>>m>>n;
	len=0;
	for(int i=1;i<=n;i++)
	{
		int x;cin>>x;
		if(vis[x]==0)
		{
			if(len==m)
			{
				int y=q.front();q.pop();
				vis[y]=0;
				len--;
			}
			len++;
			q.push(x);
			vis[x]=1;
			ans++;	
		}
	}
	cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    solve();
    return 0;
}