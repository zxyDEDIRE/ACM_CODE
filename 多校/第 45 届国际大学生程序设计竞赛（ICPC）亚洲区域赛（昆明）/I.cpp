#include<bits/stdc++.h>
using namespace std;
using db=long double;
const db eps=1e-12;
const db pi=acos(-1);
int cmpb(db x){
	if(fabs(x)<eps) return 0;
	if(x>0) return 1;
	return -1;
}
struct point{
	db x,y;
	point(){x=0;y=0;}
	point(db _x,db _y){x=_x;y=_y;}
	db operator |(const point &w)const{
		return x*w.x+y*w.y;
	}
	db operator ^(const point &w)const{
		return x*w.y-y*w.x;
	}
	point operator -(const point &w)const{
		return point(x-w.x,y-w.y);
	}
	point operator +(const point &w)const{
		return point(x+w.x,y+w.y);
	}
	point operator *(const db &w)const{
		return point(w*x,w*y);
	}
	point operator /(const db &w)const{
		return point(x/w,y/w);
	}
	db DB(db x){
		return x*x;
	}
	db dict(point &to){
		return sqrt(DB(x-to.x)+DB(y-to.y));
	}
	db dz(){
		return sqrt(x*x+y*y);
	}
	void rotate(double _o){
		db _x=x,_y=y;
		x=_x*cos(_o)-_y*sin(_o);
		y=_x*sin(_o)+_y*cos(_o);
	}
	db arg(){
		return atan2(y,x);
	}
};
struct Line{
	db a,b,c;
	Line(){a=0;b=0;c=0;}
	Line(db _a,db _b,db _c){
		a=_a;b=_b;c=_c;
	}
	Line(point &x,point &y){
		a=y.y-x.y;b=x.x-y.x;c=x.y*y.x-x.x*y.y;
	}
	point cross(Line &x){
		return point((x.c*b-c*x.b)/(a*x.b-x.a*b),
			(x.c*a-c*x.a)/(b*x.a-x.b*a));
	}
	bool check(point &x){
		return cmpb(x.x*a+x.y*b+c)==0;
	}
	Line getL(point &x){
		if(a==0){
			return Line(1.0,0,-x.x);
		}
		else if(b==0){
			return Line(0,1.0,-x.y);
		}
		return Line(b,-a,a*x.y-b*x.x);
	}
	bool Px(Line &w){
		return cmpb(a*w.b-b*w.a)==0;
	}
	bool Li(Line &w){
		return cmpb(a*w.b+b*w.a)==0;
	}
};
int n,q;
const int N=1e3+10;
point p[N];
void solve(){
	cin>>n>>q;
	point s,t;
	cin>>s.x>>s.y;
	cin>>t.x>>t.y;
	Line e=Line(s,t);
	for(int i=1;i<=n;i++){
		cin>>p[i].x>>p[i].y;
	}
	while(q--){
		int id,k;
		cin>>id>>k;
		vector<point>v;
		for(int j=1;j<=n;j++){
			if(id==j) continue;
			Line le=Line(p[j],p[id]);
			if(le.Px(e)) continue;
			point o=le.cross(e);
			if(cmpb((s-o)|(t-o))<=0){
				v.push_back(o);
			}
		}
		if((int)v.size()<k){
			cout<<-1<<'\n';
		}
		else{
			sort(v.begin(),v.end(),[&](point x,point y){
				return x.dict(s)<y.dict(s);
			});
			cout << fixed << setprecision(20) <<v[k-1].x<<" "<<v[k-1].y<<"\n";
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	solve();
	return 0;
}