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
const int maxn=1e6;
bool su(int x)
{
	if(x==1)return 1;
	if(x==2||x==3)return 1;
	if(x%6!=5&&x%6!=1)return 0;
	int tmp=sqrt(x);
	for(int i=5;i<=tmp;i+=6)
		if(x%i==0||x%(i+2)==0)
			return 0;
	return 1;
}
void solve()
{
	int n,ans=0;
	cin>>n;
	if(n==1||n==2)
	{
		cout<<1<<endl;
		return ;
	}
	else if(su(n))cout<<1<<endl;
	else
	{
		if(n&1)
		{
			if(su(n-2))cout<<2<<endl;
			else cout<<3<<endl;
		}
		else
		{
			for(int i=1;i*i<=n;i+=2)
			{
				if(su(i)&&su(n-i))
				{
					//cout<<i<<" "<<n-i<<endl;
					cout<<2<<endl;
					return ;
				}
			}
			cout<<3<<endl;
		}
	}
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
*/