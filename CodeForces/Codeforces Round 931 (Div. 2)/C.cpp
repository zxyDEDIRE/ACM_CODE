#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
int q(int x,int y){
	cout<<"? "<<x<<" "<<y<<endl;
	cin>>x;
	return x;
}
void solve()
{
	int n,m;
	cin>>n>>m;
	int a=q(1,1); //3 y=-x+a+2 y=-x+998244353
	int b=q(1,m); //1 y=x+m-b-1 y=x+2
	int c=q(n,1); //4 y=x-m+c y=x+1
	int d=q(n,m); //2 y=-x+n-d+m y=-x+6

	// -x+a+1=x+m-b-1
	// a+1-m+b+1
	double ab=(a+2-m+b+1)*0.5;
	if(ab==(int)ab)
	{
		cout<<"A"<<endl;
		cout<<ab<<" "<<(-ab+a+1)<<endl;
		return ;
	}

	// -x+a+1=x-m+c
	// a+1+m-c=2x
	double ac=(a+2+m-c)*0.5;
	if(ac==(int)ac)
	{
		cout<<"B"<<endl;
		cout<<ac<<" "<<(-ac+a+1)<<endl;
		return ;
	}

	// x+m-b-1=-x+n-d+m
	// +n-d+m-m+b+1
	double bd=(n-d+b-1)*0.5;
	if(bd==(int)bd)
	{
		cout<<"C"<<endl;
		cout<<bd<<" "<<(-bd+n-d+m)<<endl;
		return ;
	}

	//x-m+c=-x+n-d+m
	// n-d+m+m-c
	double cd=(n-d+m+m-c)*0.5;
	if(cd==(int)cd)
	{
		cout<<"D"<<endl;
		cout<<cd<<" "<<(-cd+n-d+m)<<endl;
		return ;
	}
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}
/*
3 1
4 2
*/