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
int p[maxn];
int a[maxn];
int n,k;
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		if(p[i]-(i-1)*k>0)
			a[p[i]-(i-1)*k]++;
	}
	int ma=0,fl=1;
	for(int i=1;i<=1000;i++)
		if(a[i]>ma){
			ma=a[i];
			fl=i;
		}
	int cnt=0;
	for(int i=1;i<=n;i++)
		if(p[i]!=(fl+(i-1)*k))cnt++;
	cout<<cnt<<endl;
	for(int i=1;i<=n;i++)
	{
		int t=fl+(i-1)*k;
		if(p[i]==t)continue;
		if(p[i]>t)cout<<"- "<<i<<" "<<p[i]-t<<endl;
		if(p[i]<t)cout<<"+ "<<i<<" "<<t-p[i]<<endl;
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