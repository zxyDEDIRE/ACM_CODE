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
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
const int N=333;
char mp[N][N];
char p[N][N];
int n,m;
void NO(){cout<<"error"<<endl;}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>mp[i][j];
	if(m==100)
	{
		for(int i=1;i<=n;i++)
			cout<<mp[i]+1<<endl;
	}
	else if(m==200)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
				cout<<mp[i][j]<<mp[i][j];cout<<endl;
			for(int j=1;j<=n;j++)
				cout<<mp[i][j]<<mp[i][j];cout<<endl;
		}
	}
	else if(m==150)
	{
		int k=2;
		for(int i=1;i<=n;i++)
		{
			int len=0;
			for(int j=1;j<=n;j++)
			{
				if(mp[i][j]!=mp[i][j-1])
				{
					if(len%2!=0)return NO();
					len=1;
				}
				else len++;
			}
			if(len%2!=0)return NO();


			len=0;
			for(int j=1;j<=n;j++)
			{
				if(mp[j][i]!=mp[j-1][i])
				{
					if(len%2!=0)return NO();
					len=1;
				}
				else len++;
			}
			if(len%2!=0)return NO();
		}

		for(int i=1;i<=n;i++)
		{
			if(i%2==0)
			{
				for(int _j=1;_j<=k;_j++)
				{
					for(int j=1;j<=n;j++)
					{
						if(j%2==0)
						{
							for(int _i=1;_i<=k;_i++)
								cout<<mp[i][j];
						}
						else cout<<mp[i][j];
					}
					cout<<endl;
				}

			}
			else
			{
				for(int j=1;j<=n;j++)
				{
					if(j%2==0)
					{
						for(int _i=1;_i<=k;_i++)
							cout<<mp[i][j];
					}
					else cout<<mp[i][j];
				}
				cout<<endl;
			}
		}
	}
	else
	{
		int k=(m-100)/25;k++;
		for(int i=1;i<=n;i++)
		{
			int len=0;
			for(int j=1;j<=n;j++)
			{
				if(mp[i][j]!=mp[i][j-1])
				{
					if(len%4!=0)return NO();
					len=1;
				}
				else len++;
			}
			if(len%4!=0)return NO();


			len=0;
			for(int j=1;j<=n;j++)
			{
				if(mp[j][i]!=mp[j-1][i])
				{
					if(len%4!=0)return NO();
					len=1;
				}
				else len++;
			}
			if(len%4!=0)return NO();
		}

		for(int i=1;i<=n;i++)
		{
			if(i%4==0)
			{
				for(int _j=1;_j<=k;_j++)
				{
					for(int j=1;j<=n;j++)
					{
						if(j%4==0)
						{
							for(int _i=1;_i<=k;_i++)
								cout<<mp[i][j];
						}
						else cout<<mp[i][j];
					}
					cout<<endl;
				}

			}
			else
			{
				for(int j=1;j<=n;j++)
				{
					if(j%4==0)
					{
						for(int _i=1;_i<=k;_i++)
							cout<<mp[i][j];
					}
					else cout<<mp[i][j];
				}
				cout<<endl;
			}
		}
	}
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
12 125
aaaabbbbaaaa
aaaabbbbaaaa
aaaabbbbaaaa
aaaabbbbaaaa
aaaabbbbaaaa
aaaabbbbaaaa
aaaabbbbaaaa
aaaabbbbaaaa
aaaaaaaaaaaa
aaaaaaaaaaaa
aaaaaaaaaaaa
aaaaaaaaaaaa


4
175


6 150
aaaaaa
aaaaaa
aaaaaa
aaaaaa
aaaaaa
aaaaaa

1
4 150
aabb
aabb
aaaa
aaaa


aaaaabbbbbaaaaa
aaaaabbbbbaaaaa
aaaaabbbbbaaaaa
aaaaabbbbbaaaaa
aaaaabbbbbaaaaa
aaaaaaaaaaaaaaa
aaaaaaaaaaaaaaa
aaaaaaaaaaaaaaa
aaaaaaaaaaaaaaa
aaaaaaaaaaaaaaa
aaaaaaaaaaaaaaa
aaaaaaaaaaaaaaa
aaaaaaaaaaaaaaa
aaaaaaaaaaaaaaa
aaaaaaaaaaaaaaa
*/