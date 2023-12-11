#include<bits/stdc++.h>
using namespace std;


const int N=5e3+10;
const int M=1e4+10;
vector<int>tr[M];
int n,m,k1;
long long dp[N][M];
void solve()
{
	cin>>n>>m>>k1;
	vector<int>b;
	for(int i=1;i<=n;i++){
		int w,v;
		cin>>w>>v;
		tr[w].push_back(v);
		b.push_back(w);
	}
	sort(b.begin(),b.end());
	b.erase(unique(b.begin(),b.end()),b.end());
	int sk=0;
	int len=(int)b.size();
	for(int i=0;i<len;i++){
		int le=(int)tr[b[i]].size();
		int id=b[i];
		sort(tr[id].begin(),tr[id].end());
		for(int j=le-2;j>=0;j--){
			tr[id][j]+=tr[id][j+1];
		}
		long long nu=0;
		for(int j=0;j<=min(k1,le);j++){
			for(int k=0;k<=min(sk,k1);k++){
				for(int ui=m;ui>=1;ui--){
					dp[k+1][ui]=max(dp[k+1][ui],dp[k][ui]+tr[id][le-j]);
				}
				for(int p=id;p<=le*id-j*id;p+=p){
					for(int ui=m;ui>=p;ui--){
						dp[j+k][ui]=max(dp[j+k][ui],dp[k][ui-p]+tr[id][le-p/id-j]);
					}
				}
			}	
		}
		sk+=le;
	}
	cout<<dp[k1][m]<<'\n';
}
/*
0 1 1 0

*/
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int __=1;
	// cin>>__;
	while(__--)
		solve();
	return 0;
}