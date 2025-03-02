#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
const int maxn=1e6;
void solve()
{
	int n,m,k;
	cin>>n>>m>>k;
	priority_queue<pii>q;
	for(int i=1;i<=n;i++)
		q.push({i*m,i});
	int cnt=0;
	while(!q.empty()){
		auto [x,y]=q.top();q.pop();
		cnt++;
		if(cnt==k){
			cout<<x<<endl;
			return ;
		}
		q.push({x-y,y});
	}
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    solve();
    return 0;
}