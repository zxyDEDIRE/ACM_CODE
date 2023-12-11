/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
void solve()
{
	int p[100];
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	cout<<endl;
	do{
		int flag=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					if(p[k]-p[j]==p[j]-p[i])flag=0;
				}
			}
		}
		if(flag==1)
		{
			for(int i=1;i<=n;i++)
				cout<<p[i]<<" ";
			cout<<endl;
		}
	}while(next_permutation(p+1,p+1+n));
}
signed main(){
//  freopen("in1.txt","r",stdin);
//  freopen("out1.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}