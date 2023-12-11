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
void solve()
{
	srand(time(0));
	int n,m,T;
	cin>>n>>m>>T;
	cout<<n<<" "<<m<<" "<<T<<endl;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<T;j++)
			cout<<rand()%2;
		cout<<endl;
	}
	for(int i=1;i<=m-10;i++)
	{
		int x=rand()%n;if(!x)x++;
		int y=rand()%n;if(!y)y++;
		int w=rand()%n;
		cout<<x<<" "<<y<<" "<<w<<endl;
	}
	for(int i=1;i<=10;i++)
	{
		int x=rand()%n;if(!x)x++;
		int w=rand()%n;
		cout<<x<<" "<<n<<" "<<w<<endl;
	}

}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
 fclose(stdout);
	return 0;
}
/*
5 10 4
*/