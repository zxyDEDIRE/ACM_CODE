/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
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
	int n;
	cin>>n;
	int x=n/3;//0
	int y=(n+1)/3;//2
	int z=(n+2)/3;//1
	int a=x*n-(3*1+3*x)*x/2;
	int b=(0+n/3)*z/2;
	int c=(0+n/3)*z/2;
	if(n%3==0)
	{
		b+=(n+5)/6;
		c+=(n+5)/6;
	}
	// cout<<x<<" "<<y<<" "<<z<<endl;
	// cout<<a<<" "<<b<<" "<<c<<endl;
	cout<<a+b+c<<endl;
}
// void solve()
// {
// 	int n,sum=0;
// 	cin>>n;
// 	solve(n);
// 	int a,b,c;
// 	a=b=c=0;
// 	for(int i=1;i<=n;i++)
// 	{
// 		if(i%3==0)sum+=n-i,a+=n-i;
// 		else if(i%3==1)sum+=(n-i+1)/3,b+=(n-i+1)/3;
// 		else if(i%3==2)sum+=(n-i+2)/3,c+=(n-i+2)/3;
// 	}
// 	cout<<a<<" "<<b<<" "<<c<<endl;
// 	cout<<sum<<endl;



// }
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}//1236