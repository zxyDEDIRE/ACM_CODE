#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
vector<int>v[maxn],ans;
bitset<maxn>vis;
int in[maxn];
int n,m;
void topsort()
{
	priority_queue<int,vector<int>,less<int> >q;
	for(int i=1;i<=n;i++)
		if(!in[i])q.push(i);
	while(!q.empty()){
		int x=q.top();q.pop();
		ans.push_back(x);
		for(int i=0;i<v[x].size();i++){
			int y=v[x][i];
			in[y]--;
			if(!in[y])q.push(y);
		}
	}
	if(ans.size()!=n)cout<<"Impossible!"<<endl;
	else{
		for(int i=n-1;i>=0;i--)
			cout<<ans[i]<<" ";
		cout<<endl;
	}
}
void solve()
{
	cin>>n>>m;
	ans.clear();
	for(int i=1;i<=n;i++)
		v[i].clear(),in[i]=0;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		v[y].push_back(x);
		in[x]++;
	}
	topsort();
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