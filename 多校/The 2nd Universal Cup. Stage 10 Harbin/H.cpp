#include<bits/stdc++.h>
using namespace std;

#define N 10
const double eps=1e-3;
int n;
int mp[N][N];
double e[N];

double dfs(int id,double lim){
	lim=max(lim,(double)0);
	if(id==n){
		double res=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				res+=e[i]*e[j]*mp[i][j];
			}
		}
		return res;
	}
	if(id==n-1){
		e[id]=lim;
		return dfs(id+1,0);
	}
	double l=0,r=lim;
	while(r-l>eps){
		double ml=l+(r-l)/3.0;
		double mr=r-(r-l)/3.0;
		e[id]=ml;
		double ansl=dfs(id+1,lim-ml);
		e[id]=mr;
		double ansr=dfs(id+1,lim-mr);
		if(ansl<=ansr){
			l=ml;
		}
		else{
			r=mr;
		}
	}
	e[id]=r;
	return dfs(id+1,lim-r);
}

void solve(){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>mp[i][j];
		}
	}
	cout << fixed << setprecision(20) <<dfs(0,1)<<"\n";
}
/*
4
8 -4 2 -1
*/
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t=1;
	while(t--){
		solve();
	}

	return 0;
}