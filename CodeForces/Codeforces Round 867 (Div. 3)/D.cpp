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
bitset<maxn>vis,ok;
int a[maxn];
int p[maxn];
int n,flag;

void solve()
{
	cin>>n;
	if(n==1){
		cout<<1<<endl;
		return ;
	}
	if(n&1){
		cout<<-1<<endl;
		return ;
	}
	for(int j=2,i=n-1;j<=n;j+=2)
		a[j]=i,i--;
	for(int j=1,i=0;j<=n;j+=2)
		a[j]=i,i++;
	p[1]=n;
	for(int i=2;i<=n;i++)
	{
		int x=a[i]-a[i-1];
		if(x<0)x+=n;
		p[i]=x;
	}
	for(int i=1;i<=n;i++)
		cout<<p[i]<<" ";
	cout<<endl;
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
8 7 2 5 4 3 6 1
0 7 1 6 2 5 3 4

6 5 2 3 4 1
0 5 1 4 2 3
*/