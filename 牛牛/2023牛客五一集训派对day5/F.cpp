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
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
ll d[maxn];
ll s[maxn];
int n;
void out(int x){
	for(int i=1;i<=x;i++)cout<<"-";
}
void solve()
{
	cin>>n;
	ll ma=0;
	for(int i=1;i<=n;i++)
		cin>>d[i],ma=max(ma,d[i]);
	ll _ma=0;
	for(int i=1;i<=n;i++){
		s[i]=(50*d[i]+ma-1)/ma;
		_ma=max(_ma,s[i]);
	}
	for(int i=1;i<=n;i++)
	{
		int flag=(d[i]==ma);
		cout<<"+";out(s[i]);cout<<"+"<<endl;

		cout<<"|";
		for(int j=1;j<s[i];j++)
			cout<<" ";

		if(flag)cout<<"*|"<<d[i]<<endl;
		else if(s[i]==0)cout<<"|"<<d[i]<<endl;
		else cout<<" |"<<d[i]<<endl;

		cout<<"+";out(s[i]);cout<<"+"<<endl;
	}
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}