#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=2e6;
int p[maxn];
int n,m;
void solve()
{
	cin>>m>>n;
	for(int i=1;i<=m;i++)
		cin>>p[i];
	sort(p+1,p+1+m);
	ll ans=0;
	p[0]=p[m+1]=-maxn;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		int fl=lower_bound(p+1,p+1+m,x)-p;
		int t=min({abs(p[fl]-x),abs(p[fl-1]-x),abs(p[fl+1]-x)});
		ans+=t;
	}
	cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int __;
//    cin>>__;
    __=1;
    while(__--)solve();
    return 0;
}