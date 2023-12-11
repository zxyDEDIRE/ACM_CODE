#include<bits/stdc++.h>
using namespace std;

const int N=3e5+10;
int n,m,k;
struct pp{
	int x1,x2,y;
}p[N];
using pii=pair<int,int>;
vector<pii>tr[N];
void solve(){
	cin>>n>>m>>k;
	vector<int>yy;
	yy.push_back(m+1);
	for(int i=1;i<=n;i++){
		cin>>p[i].x1>>p[i].x2>>p[i].y;
		yy.push_back(p[i].y);
	}
	sort(yy.begin(),yy.end());
	yy.erase(unique(yy.begin(),yy.end()),yy.end());
	int len=(int)yy.size();
	for(int i=1;i<=n;i++){

	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t=1;
	while(t--){
		solve();
	}

	return 0;
}