#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
vector<pii>v[maxn];
int p[maxn];
int n,cnt;
void dfs(int x,int fa)
{
	for(int i=0;i<v[x].size();i++)
	{
		pii now=v[x][i];
		int y=now.first;
		if(y==fa)continue;
		++cnt;
		if(cnt&1)p[now.second]=2;
		else p[now.second]=3;
		dfs(y,x);
	}
}
void solve()
{
	cin>>n;
	vector<int>in(n+1);
	for(int i=1;i<=n;i++)v[i].clear();
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		v[x].push_back(pii(y,i));
		v[y].push_back(pii(x,i));
		in[x]++;
		in[y]++;
	}
	int s;cnt=0;
	for(int i=1;i<=n;i++){
		if(in[i]==1)s=i;
		else if(in[i]>2){
			cout<<-1<<endl;
			return ;
		}
	}
	dfs(s,0);
	for(int i=1;i<n;i++)
		cout<<p[i]<<" ";
	cout<<endl;
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