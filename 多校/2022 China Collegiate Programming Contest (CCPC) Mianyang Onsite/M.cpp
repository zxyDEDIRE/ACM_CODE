/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
#include<windows.h>
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
const int N=100;
char p[N][N];
char s[]={'S','P','R'};
map<char,int>mp;
int n;
void solve()
{
	// cin>>n;
	n=10;
	mp['S']=0;
	mp['P']=1;
	mp['R']=2;
	for(int i=1;i<=n;i++)
		p[1][i]=s[rand()%3];
	// for(int i=1;i<=n;i++)
	// 	cin>>p[1][i];
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=n-i+1;j++)
		{
			if(p[i-1][j]==p[i-1][j+1])
				p[i][j]=p[i-1][j];
			int x=mp[p[i-1][j]];
			int y=mp[p[i-1][j+1]];
			if(abs(x-y)==1)
			{
				if(x<y)p[i][j]=p[i-1][j];
				else p[i][j]=p[i-1][j+1];
			}
			else
			{
				if(x>y)p[i][j]=p[i-1][j];
				else p[i][j]=p[i-1][j+1];
			}
		}
	}
	for(int i=n;i>=1;i--)
	{
		for(int j=1;j<=i;j++)cout<<" ";
		for(int j=1;j<=n-i+1;j++)
		{
			if(p[i][j]=='S')cout<<"\033[32;1mS\033[0m"<<" ";
			if(p[i][j]=='P')cout<<"\033[34;1mP\033[0m"<<" ";
			if(p[i][j]=='R')cout<<"\033[31;1mR\033[0m"<<" ";
		}
		cout<<endl;
	}
	for(int i=1;i<=n;i++)
		cout<<p[1][i];
	cout<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
	{
		Sleep(1000);
		srand(time(0));
		solve();
	}
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
R S S R R P S R P R
R-> S <-R <-P <-S <-R <-P-> R


*/