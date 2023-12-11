/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
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
int a[maxn];
int b[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>b[i];
	int l=1,r=n;
	set<int>s;
	for(int i=1;i<=n;i++)
		if(a[i]!=b[i]){
			l=i;
			break;
		}
	for(int i=n;i>=1;i--)
		if(a[i]!=b[i]){
			r=i;
			break;
		}
	for(int i=l;i<=r;i++)
		s.insert(a[i]);
	for(int i=l-1;i>=1;i--)
	{
		int x=*s.begin();
		if(a[i]<=x)l=i,s.insert(a[i]);
		else break;
	}
	for(int i=r+1;i<=n;i++)
	{
		int x=*s.rbegin();
		if(a[i]>=x)r=i,s.insert(a[i]);
		else break;
	}
	cout<<l<<" "<<r<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*


2 3 4 
2 4 3
*/