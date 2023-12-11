/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define p(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
int cnt[maxn];
int sum[maxn];
int p[maxn];
int a[maxn];
int t[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		p[i]=cnt[a[i]];
		cout<<p[i]<<" ";
	}
	cout<<endl;
	sort(p+1,p+1+n);
	int m=unique(p+1,p+1+n)-p-1;
	for(int i=1;i<=m;i++)
		sum[i]=sum[i-1]+p[i];
	for(int i=m+1;i<=n;i++)
		sum[i]=sum[i-1];
	int r=m;
	int num=0;
	for(int i=n;i>=1;i--)
	{
		t[i]=sum[i]+num*i;
		while(p[r]>=i)r--,num++;
	}
	for(int i=1;i<=n;i++)
		cout<<t[i]<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}