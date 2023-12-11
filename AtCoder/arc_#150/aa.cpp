/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
void solve()
{
	int a,b;
	cin>>a>>b;
	if(b<=a)
	{
		cout<<a-b<<endl;
		return;
	}
	int ans=b-a;
	if(a<=100000)
	{
		for(int i=0;i<=100000+7;i++)
			ans=min(ans,((b>(a+i))?((b%(a+i)==0)?i:(i*2+a-b%(a+i))):(i*2+a-b)));
	}
	else
	{
		for(int i=1;i<=100000+7;i++)
			ans=min(ans,(((a*i)<=b)?((i-b%i)%i)+((b-a*i+((i-b%i)%i))/i):(a*i-b)));
	}
	cout<<ans<<endl;
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