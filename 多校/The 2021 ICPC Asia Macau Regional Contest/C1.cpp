#include<bits/stdc++.h>
using namespace std;
using db=double;
struct point{
	db x,y;
	db ag;
	point(){x=0;y=0;}
	point(db _x,db _y){x=_x;y=_y;}
	db operator ^(const point &w)const{
		return x*w.y-y*w.x;
	}
	point operator -(const point &w)const{
		return point(x-w.x,y-w.y);
	}
	void arg(){
		ag=atan2(y,x);
	}
	bool operator <(const point &w)const{
		return ag<w.ag;
	}
};
const int N=2e6+10;
point p[N];
int n;
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>p[i].x>>p[i].y;
		p[i].arg();
	}
	if(n<=2){
		cout<<0<<'\n';return;
	}
	sort(p+1,p+n+1);
	for(int i=1;i<=n;i++){
		p[i+n]=p[i];
	}
	int ans=n;
	for(int l=1,r=1;l<=n;l++){
		while(r-l+1<=n&&(p[r]^p[l])<=0) r++;
		if((r-l+1<=n)&&(p[r]^p[l])>0){
			ans=min(ans,(l-r+n)%n);
		}
	}
	cout<<ans<<'\n';
}
/*
1
4
-1 2
-1 -2
3 2
3 2
*/
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}