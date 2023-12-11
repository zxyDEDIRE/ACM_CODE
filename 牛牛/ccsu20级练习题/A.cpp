/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
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
void solve()
{
	int p[7],a[7],n=6;
	for(int i=1;i<=n;i++){
		cin>>p[i];
		a[i]=i;
	}
	auto check=[&](int a,int b,int c)->bool{
		int sum=a+b+c;
		int ma=max({a,b,c});
		if(ma<sum-ma)return 1;
		else return 0;
	};
	int flag=0;
	do{
		if(check(p[a[1]],p[a[2]],p[a[3]])&&check(p[a[4]],p[a[5]],p[a[6]]))flag=1;
	}while(next_permutation(a+1,a+1+n));
	if(flag)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}