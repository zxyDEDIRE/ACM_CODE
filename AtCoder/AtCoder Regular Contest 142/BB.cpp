/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
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
const int N=1e3;
int p[N][N];
int n;
void solve()
{
	cin>>n;
	if(n==1)cout<<1<<endl;
	else if(n==2){
		cout<<"1 2\n3 4"<<endl;
	}
	else if(n==3){
		cout<<"1 2 3\n5 4 6\n7 8 9"<<endl;
	}
	else
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				p[i][j]=(i-1)*n+j;
		for(int i=2;i<n;i++)
		{
			for(int j=2;j<n;j+=2)
			{
				swap(p[i][j],p[i][j+1]);
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
				cout<<p[i][j]<<" ";
			cout<<endl;
		}
		cout<<endl;
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