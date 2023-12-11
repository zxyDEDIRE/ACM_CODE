// /*
//     嵌套变量重复
//     特殊样例 0 1 2 n
//     数组越界
//     开long long
// */
// #include<bits/stdc++.h>
// #define int long long
// using namespace std;
// using ll=long long;
// using pii=pair<int,int>;
// const int mod=1e9+7;
// const int maxn=105;
// const int N=105;
// ll n,power;
// struct matrix{
// 	ll a[maxn][maxn];
// 	matrix(){
// 		memset(a,0,sizeof(a));
// 	}
// 	void build(){
// 		for(int i=1;i<=n;i++)
// 			a[i][i]=1;
// 	}
// }a;
// matrix operator*(const matrix&a,const matrix&b){
// 	matrix z;
// 	for(int k=1;k<=n;k++)
// 		for(int i=1;i<=n;i++)
// 			for(int j=1;j<=n;j++)
// 				z.a[i][j]=(z.a[i][j]+a.a[i][k]*b.a[k][j]%mod)%mod;
// 	return z;
// }
// matrix mfp(matrix b,ll p)
// {
// 	matrix r;
// 	r.build();
// 	while(p)
// 	{
// 		if(p&1)r=r*b;
// 		b=b*b;
// 		p>>=1;
// 	}
// 	return r;
// }
// void solve()
// {
// 	cin>>n>>power;
// 	for(int i=1;i<=n;i++)
// 		for(int j=1;j<=n;j++)
// 			cin>>a.a[i][j];
// 	matrix ans=mfp(a,power);
// 	for(int i=1;i<=n;i++)
// 	{
// 		for(int j=1;j<=n;j++)
// 			cout<<ans.a[i][j]<<" ";
// 		cout<<endl;
// 	}
// }
// signed main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);cout.tie(nullptr);
//         solve();
//     return 0;
// }
/*
    嵌套变量重复
    特殊样例 0 1 2 n
    数组越界
    开long long
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
void solve()
{
	int m,n;
	cin>>m>>n;
	char ch='A'-1;
	int t=(n+m-1)/m;
	ch+=t;
	cout<<ch<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

        solve();
    return 0;
}