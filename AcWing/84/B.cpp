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
int a[maxn],aa[maxn];
int b[maxn],bb[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],b[i]=a[i];
	sort(b+1,b+1+n);
	for(int i=1;i<=n;i++)
	{
		aa[i]=aa[i-1]+a[i];
		bb[i]=bb[i-1]+b[i];
	}
	int m;
	cin>>m;
	while(m--)
	{
		int fl,l,r;
		cin>>fl>>l>>r;
		if(fl==1)cout<<aa[r]-aa[l-1]<<endl;
		else cout<<bb[r]-bb[l-1]<<endl;
	}
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