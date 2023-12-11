
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
ll p[10];
ll a[10];
void NO(){cout<<"NO"<<endl;}
void solve()
{
	ll mi;
	for(int i=1;i<=3;i++){
		cin>>p[i];
		if(i==1)mi=p[1];
		else mi=min(mi,p[i]);
	}
	if(mi==1)return NO();
	ll sum=p[1]+p[2]+p[3];
	if(sum%2==1)return NO();
	sum/=2;
	ll x=sum-p[1];
	ll y=sum-p[2];
	ll z=sum-p[3];
	if(x+y>z&&x+z>y&&z+y>x)
	{
		cout<<"YES"<<endl;
		cout<<x<<" "<<y<<" "<<z<<endl;
	}
	else return NO();
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
va = lb + lc
vb = la + lc
vc = la + lb

7 1+6
8 1+7
9 
x+y=7
y+z=8
x+z=9
2x+2y+2z=24
x+y+z=12

*/