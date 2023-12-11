/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
int p[maxn];
int a[maxn];
int n;
int f(int x)
{
	int cnt=0;
	while(x)
		cnt++,x/=10;
	return cnt;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	sort(p+1,p+1+n,[&](int a,int b){
		if(f(a)!=f(b))return f(a)>f(b);
		return a>b;
	});
	sort(p+1,p+1+3,[&](int a,int b){
		return a*pow(10,f(b))+b>b*pow(10,f(a))+a;
	});
	cout<<p[1]<<p[2]<<p[3]<<endl;
}
signed main(){
//  freopen("in1.txt","r",stdin);
//  freopen("out1.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
4



1000
1000
1000
999
*/

