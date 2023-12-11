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
using ll=long long;
using pii=pair<int,int>;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
int n,m;
int a,b;
int f(int x)
{
	int ans=0;
	while(x)
	{
		ans=ans*10+x%10;
		x/=10;
	}
	return ans;
}
void solve()
{
	cin>>n>>m;
	if(m>n){
		cout<<0<<endl;
		return ;
	}
	a=m;
	b=f(m);
	if(a%10==0)
	{
		if(m<=n)cout<<1<<endl;
		else cout<<0<<endl;
	}
	else
	{
		int ans=0;
		for(int i=a;;i=i*10)
			if(i<=n)ans++;
			else break;
		for(int i=b;;i=i*10)
			if(i<=n&&a!=b)ans++;
			else break;
		cout<<ans<<endl;
	}
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*

100
*/