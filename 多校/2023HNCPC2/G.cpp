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
const int N=2010;
int n,m;
char mp[N][N];
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>mp[i][j];
	cout<<1<<'\n';
	map<char,char>to;
	to['B']='W';
	to['W']='B';
	if(n==1&&m==1&&mp[n][m]=='W')
	{
		cout<<1<<'\n';
	}
	else{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(i==n)
				{
					if(j==m)
					{
						if(mp[i][j]=='W'){
							cout<<2<<'\n';
						}
						else{
							cout<<3<<'\n';
						}
					}
					else{
						if(mp[i][j]=='B')
						{
							cout<<2;
							if(j-1>=1)
							{
								mp[i][j-1]=to[mp[i][j-1]];
							} 
							mp[i][j+1]=to[mp[i][j+1]];
							mp[i+1][j]=to[mp[i+1][j]];
						}
						else{
							cout<<3;
							mp[i][j]=to[mp[i][j]];
							if(j-1>=1)
							{
								mp[i][j-1]=to[mp[i][j-1]];
							} 
							mp[i][j+1]=to[mp[i][j+1]];
							mp[i+1][j]=to[mp[i+1][j]];
						}
					}
				}
				else{
					if(j==m)
					{
						if(mp[i][j]=='B'){
							cout<<2<<'\n';
						}
						else cout<<3<<'\n';
						mp[i+1][j]=to[mp[i+1][j]];
					}
					else{
						if(mp[i][j]=='W')
						{
							cout<<2;
							if(j-1>=1)
							{
								mp[i][j-1]=to[mp[i][j-1]];
							} 
							mp[i][j+1]=to[mp[i][j+1]];
							mp[i+1][j]=to[mp[i+1][j]];
						}
						else{
							cout<<3;
							mp[i][j]=to[mp[i][j]];
							if(j-1>=1)
							{
								mp[i][j-1]=to[mp[i][j-1]];
							} 
							mp[i][j+1]=to[mp[i][j+1]];
							mp[i+1][j]=to[mp[i+1][j]];
						}
					}
				}
			}
		}
	}
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}