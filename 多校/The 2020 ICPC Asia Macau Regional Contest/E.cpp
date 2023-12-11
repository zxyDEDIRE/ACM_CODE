#include<bits/stdc++.h>
using namespace std;
#define db long double
const db eps=1e-6;
struct point{
	db x,y;
	point(){x=0;y=0;}
	point(double _x,double _y){x=_x;y=_y;}
	db operator ^(const point &w)const{
		return x*w.y-y*w.x;
	}
	point operator -(const point &w)const{
		return point(x-w.x,y-w.y);
	}
	point operator +(const point &w)const{
		return point(x+w.x,y+w.y);
	}
	point operator *(const db w)const{
		return point(x*w,y*w);
	}
	db arg(){
		return atan2(y,x);
	}
};
struct Line{
	point s,e;
	Line(){}
	Line(point _s,point _e){s=_s;e=_e;}
	point cross(Line &W){
		point u=s-W.s,v=e-s,w=W.e-W.s;
		db t=(u^w)/(w^v);
		return s+v*t;
	}
	bool right(Line b,Line c){
		point p=b.cross(c);
		return ((e-s)^(p-s))<0;
	}
	db arg(){
		return atan2(e.y-s.y,e.x-s.x);
	}
};
int cmpb(db x){
	if(fabs(x)<eps) return 0;
	return x>0?1:-1;
}
const int N=220,M=64;
int n,w,h;
db dp[N][N][M];
int a[N];
int B;
typedef pair<int,int> pii;
vector<pii>tr[N];
vector<pii>merge(vector<pii>v){
	if((int)v.size()==0){
		return {};
	}
	sort(v.begin(),v.end());
	int l=v[0].first,r=v[0].second;
	vector<pii>res;
	for(int i=1;i<(int)v.size();i++){
		if(v[i].first<=r){
			r=max(r,v[i].second);
		}
		else{
			res.push_back({l,r});
			l=v[i].first,r=v[i].second;
		}
	}
	res.push_back({l,r});
	return res;
}
db S(int id,int ol){
	vector<int>v;
	for(int i=0;i<=w;i++){
		if(id-i<1) break;
		if((ol>>i)&1){
			v.push_back(id-i);
		}
	}
	int l=id-w+1,r=id+w;
	l=max(1,l);r=min(n+1,r);
	for(int i=0;i<(int)v.size();i++){
		for(int j=max(l,v[i]-w+1);j<=min(r,v[i]+w);j++){
			tr[j].push_back({a[v[i]]-h,a[v[i]]+h});
		}
	}
	db ans=0,res=0;
	for(int i=l;i<=r;i++){
		tr[i]=merge(tr[i]);
		for(auto [l,r]:tr[i]){
			if(l==r) continue;
			
		}
		tr[i].clear();
	}
	for(int i=l;i<=r;i++){
		int ll=a[id]-h;int rr=a[id]+h;
		ll=max(ll,0);
		if(rr==ll) continue;
		if(a[i]==a[i+1]){
			rr=min(rr,a[i]);
			if(ll<rr){
				res+=(rr-ll);
			}
		}
		else if(a[i]>a[i+1]){
			if(rr<=a[i+1]||ll>=a[i]) continue;
			if(ll<a[i+1]){
				ans+=a[i+1]-ll;
			}
			ll=max(ll,a[i+1]);
			rr=min(rr,a[i]);
			if(ll==a[i+1]){
				if(rr==a[i]){
					ans+=(rr-ll)/2.0;
				}
				else{
					ans+=((a[i]-rr)/(a[i]-ll)+1)*(rr-ll)/2.0;
				}
			}
			else{
			}
		}
		else{
			if(rr>=a[i+1]||ll<=a[i]) continue;
		}
	}
	return res;
}
void solve()
{
	cin>>n>>w>>h;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	B=(1<<(w+1));
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n;j++){
			for(int k=0;k<=n;k++){
				for(int p=0;p<B;p++){
					dp[j][k][p]=0;
				}
			}
		}
		for(int j=1;j<=n;j++){
			for(int k=0;k<=min(i-1,j-1);k++){
				for(int p=0;p<B;p++){
					int to=p<<1;
					to%=B;
					dp[j][k][to]=max(dp[j][k][to],dp[j-1][k][p]);
					to|=1;
					cout<<j<<" "<<to<<'\n';
					cout<<S(j,to)<<'\n';
					dp[j][k+1][to]=max(dp[j][k+1][to],
						dp[j-1][k][p]+S(j,to));
				}
			}
		}
		db mx=0;
		for(int j=0;j<B;j++){
			mx=max(mx,dp[n][i][j]);
		}
		cout<<fixed<<setprecision(20)<<mx<<'\n';
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	solve();
	return 0;
}
/*
3 1 2
2 1 3
*/