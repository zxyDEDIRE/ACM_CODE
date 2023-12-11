/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
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
ll p[maxn];
ll a[maxn];
ll n,ma;
void f()
{
	for(int i=1;i<=n;i++)
		a[i]=p[i];
	for(int j=n-1;j>=1;j--)
	{
		for(int i=1;i<=j;i++)
			a[i]+=a[i+1];
	}
	if(a[1]>=ma){
		ma=a[1];
		cout<<a[1]<<endl;
		for(int i=1;i<=n;i++)
			cout<<p[i]<<" ";
		cout<<endl;
	} 
}
void solve()
{
	cin>>n;
	int now=1;
	int l=1,r=n;
	// while(now<=n)
	// {
	// 	p[l++]=now++;
	// 	if(now<=n)p[r--]=now++;
	// }
	ma=0;
	for(int i=1;i<=n;i++)
		p[i]=i;
	do{
		f();
	}while(next_permutation(p+1,p+1+n));
	
}
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
}
/*

*/