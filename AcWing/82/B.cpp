/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
string str;
int a[maxn];
int b[maxn];
int n,m;
void solve()
{
	cin>>n>>str;
	str=" "+str;
	for(int i=1;i<=n;i++)
	{
		if(str[i]=='R')
			a[i]=1;
		else if(str[i]=='.'&&a[i-1]>0)
			a[i]=a[i-1]+1;
	}
	for(int i=n;i>=1;i--)
	{
		if(str[i]=='L')
			b[i]=1;
		else if(str[i]=='.'&&b[i+1]>0)
			b[i]=b[i+1]+1;
	}
	int cnt=0;
	// for(int i=1;i<=n;i++)
	// 	cout<<a[i]<<" ";cout<<endl;
	// for(int i=1;i<=n;i++)
	// 	cout<<b[i]<<" ";cout<<endl;
	for(int i=1;i<=n;i++)
		if(a[i]==b[i])
			cnt++;
	cout<<cnt<<endl;
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