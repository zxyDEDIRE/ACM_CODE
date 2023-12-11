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
int a[maxn][20];
int b[maxn][20];
int n,tot;
int f(int x)
{
	return log2(x);
}
void solve()
{
	cin>>n;
	cout<<n*12<<endl;
	for(int i=1;i<=n;i++)
	{
		int x=1;
		for(int j=0;j<12;j++)
			if(i+x-1<=n){
				a[i][j]=++tot;
				b[i+x-1][f(x)]=tot;
				cout<<i<<" "<<(i+x-1)<<endl,x*=2;
				
			}
			else cout<<i<<" "<<i<<endl,tot++;
	}
	int q;
	cin>>q;
	while(q--)
	{
		int l,r,x;
		cin>>l>>r;
		for(int i=11;i>=0;i--)
		{
			x=l+(1<<i)-1;
			if(x<=r){
				cout<<a[l][i]<<" ";
				break;
			}
		}
		for(int i=11;i>=0;i--)
		{
			x=r-(1<<i)+1;
			if(x>=l){
				cout<<b[r][i]<<endl;
				break;
			}
		}

	}
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
16
1 2 3 4 5 6 7 8 9 
1
1 2
1 2 3 4
1 2 3 4 5 6 7 8
2
2 3
2 3 4 5
2 3 4 5 6 7 8 9
3 
3 4
3 4 5 6
4
4 5
4 5 6 7
5
5 6
5 6 7 8
7
7 8 
8
9
*/