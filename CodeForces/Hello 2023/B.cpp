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
int p[maxn];
int n,fl;
void solve()
{
	cin>>n;
	if(n==3)cout<<"No"<<endl;
	else if(n%2==0)
	{
		cout<<"YES"<<endl;
		for(int i=1;i<=n;i++)
			if(i&1)cout<<1<<" ";
			else cout<<-1<<" ";
		cout<<endl;
	}
	else
	{
		int x=n/2+1;
		int y=n-x;
		for(int i=-2000;i<0;i++)
		{
			for(int j=1;j<=2000;j++)
			{
				int sum=x*i+y*j;
				if(sum==i+j){
					cout<<"Yes"<<endl;
					for(int k=1;k<=n;k++)
					{
						if(k&1)cout<<i<<" ";
						else cout<<j<<" ";
					}
					cout<<endl;
					return ;
				}
			}
		}
		cout<<"No"<<endl;
	}
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
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

*/