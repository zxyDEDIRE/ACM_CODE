#include<bits/stdc++.h>
using namespace std;
int n,q,m;
const int N=1e6+10;
long long a[N];
long long sum[N][32];
vector<int>tr[32];
vector<int>v[32];
vector<int>st[32][20];
int find(int x){
	for(int i=0;;i++){
		if((1ll<<i)>x) return i-1;
	}
	return 0;
}
int lg[N];
long long qr(int id,int l,int r){
	int k=lg[r-l+1];
	return min(st[id][k][l],st[id][k][r-(1<<k)+1]);
}
void solve(){
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int t=find(a[i]);
		for(int j=0;j<32;j++){
			sum[i][j]=sum[i-1][j];
		}
		sum[i][t]+=a[i];
		tr[t].push_back(i);
		v[t].push_back(i);
	}
	for(int i=0;i<32;i++){
		int le=tr[i].size();
		if(le==0) continue;
		for(int k=0;k<20;k++){
			st[i][k].resize(le);
		}
		for(int j=0;j<le;j++){
			st[i][0][j]=a[tr[i][j]];
		}
		for(int k=1;k<20;k++){
			for(int j=0;j+(1<<k)-1<=le;j++){
				st[i][k][j]=min(st[i][k-1][j],st[i][k-1][j+(1<<k-1)]);
			}
		}
	}
	long long res=0;
	while(q--){
		int l,r;
		cin>>l>>r;
		l=(l+res)%n+1;r=(r+res)%n+1;
		if(l>r) swap(l,r);
		res=1;
		for(int j=0;j<32;j++){
			if((int)tr[j].size()==0) continue;
			int L=lower_bound(tr[j].begin(),tr[j].end(),l)-tr[j].begin();
			int R=lower_bound(tr[j].begin(),tr[j].end(),r)-tr[j].begin();
			if(R==tr[j].size()||tr[j][R]>r) R--;
			if(L>R) continue;
			long long mi=qr(j,L,R);
			if((res)>=mi)
				res+=sum[r][j]-sum[l-1][j];
			else {
				break;
			}
		
		}
		cout<<res<<'\n';
	}
}
/*
*/
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	lg[0]=-1;
	for(int i=1;i<=N-10;i++){
		lg[i]=lg[i>>1]+1;
	}
	int t=1;
	while(t--){
		solve();
	}
	return 0;
}