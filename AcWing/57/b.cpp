/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
int p[maxn],cnt;
int ans=1;
int n;
void solve()
{
	cin>>n;
	for(int i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			ans*=i;
			cnt++;
			while(n%i==0)n/=i,p[cnt]++;
		}
	}
	if(n>1)ans*=n,p[++cnt]=1;
	int ma=0;
	for(int i=1;i<=cnt;i++)
		ma=max(ma,p[i]);
	int t=1;
	int num=0;
	for(int i=1;i;i++)
	{
		t*=2;
		if(t==ma){
			num=i;
			break;
		}
		else if(t>ma){
			num=i+1;
			break;
		}
	}
	cout<<ans<<" "<<num<<endl;
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

		solve();
	return 0;
}
/*
6 4


16
4
2
1
*/