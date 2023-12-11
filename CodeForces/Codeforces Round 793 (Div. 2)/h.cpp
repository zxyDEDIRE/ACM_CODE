#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<ll,int>;
const int maxn=1e6;
int n;
ll x;
queue<pii> q;
map<ll,bool> mp;
bitset<100>vis;
int f(ll x)
{
	vis.reset();
	for(int i=0;i<10;i++)
		vis[i]=0;
	if(x==0)return 1;
	int res=0;
	while(x){
		res++;
		vis[x%10]=1;
		x/=10;
	}
	return res;
}
void solve()
{
	cin>>n>>x;
	q.push({x,0});
	mp[x]=1;
	while(q.size())
	{
		
		pii S=q.front();
		ll now=S.first;
		ll step=S.second;
		q.pop();
		int k=f(now);
		if(k==n){
			cout<<step<<endl;
			return;
		}
		else if(k>n)break;
		for(int i=9;i>1;i--)
			if(vis[i]){
				if(mp[now*i])continue;
				mp[now*i]=1;
				q.push({now*i,step+1});
			}
	}
	cout<<-1<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int __;
    __=1;
    while(__--)solve();
    return 0;
}