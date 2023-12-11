#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
int dfn[maxn],low[maxn],tot;
vector<int>v[maxn];
int n,x,y,s,t,ans;
void tarjan(int x)
{
	dfn[x]=low[x]=++tot;
	for(int y:v[x])
	{
		if(!dfn[y])
		{
			tarjan(y);
			low[x]=min(low[x],low[y]);
			if(dfn[x]<=low[y]&&x!=s&&dfn[t]>=dfn[y])
            {
                ans=min(ans,x);
            }
		}
		else
			low[x]=min(low[x],dfn[y]);
	}
}
void solve()
{
	cin>>n;
	while(cin>>x>>y)
	{
		if(x==0&&y==0)break;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	cin>>s>>t;
	ans=0x3f3f3f3f;
	tarjan(s);
	if(ans==0x3f3f3f3f)cout<<"No solution"<<endl;
	else cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    solve();
    return 0;
}