#include<bits/stdc++.h>
using namespace std;

const int N=1e6+10;
struct pp{
	int f,val;
	bool operator <(const pp &w)const{
		return val<w.val||((val==w.val)&&f<w.f);
	}
}p[N];
int n;
void solve()
{
	cin>>n;
	double fm=0,fm1=0;
	for(int i=1;i<=n;i++){
		char c;
		cin>>c;cin>>p[i].val;
		if(c=='+') p[i].f=0,fm1++;
		else p[i].f=1,fm++;
	}
	sort(p+1,p+n+1);
	double ans=0;
	int res=0;
	for(int i=1;i<=n;i++){
		// cout<<p[i].val<<" "<<p[i].f<<" "<<res<<'\n';
		if(p[i].f){
			ans+=res;
		}
		else{
			res++;
		}
	}
	ans/=fm*fm1;
	cout << fixed << setprecision(10) <<max((double)0,1-ans)<<"\n";
}
int main(){

	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	solve();
	return 0;
}
