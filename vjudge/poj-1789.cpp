/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<iostream>
#include<algorithm>
using namespace std;
#define endl "\n"
const int maxn=1e6;
string p[2222];
int n,mi;
void solve()
{
	while(cin>>n&&n)
	{
		mi=1e9;
		for(int i=1;i<=n;i++)
			cin>>p[i];
		for(int i=1;i<=n;i++)
		{
			int ans=0;
			for(int j=1;j<=n;j++)
			{
				//if(i==j)continue;
				for(int k=0;k<7;k++)
					if(p[i][k]!=p[j][k])ans++;
			}
			mi=min(mi,ans);
		}
		//cout<<mi<<endl;
		cout<<"The highest possible quality is 1/"<<mi<<"."<<endl;
	}
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
		solve();
	return 0;
}
/*
11110
11000
11001
*/