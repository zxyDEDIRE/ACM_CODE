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
const int maxn=1e6;
int a[11];
int b[11];
int n,x,y;
void solve()
{
	cin>>n>>x>>y;
	a[n]=1;
	while(1)
	{
		int flag=0;
		for(int i=10;i>=2;i--)
			if(a[i])
				a[i-1]+=a[i],b[i]+=x*a[i],a[i]=0,flag=1;
		for(int i=10;i>=2;i--)
		 	if(b[i])
				a[i-1]+=b[i],b[i-1]+=y*b[i],b[i]=0,flag=1;
		if(!flag)break;
	}
	cout<<b[1]<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}