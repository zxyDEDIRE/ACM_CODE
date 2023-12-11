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
const int maxn=1e6+100;
int n,m,cnt=0;
int f(int x)
{
	int num=0;
	while(x%10==0)
		num++,x/=10;
	return num;
}
int h(int x)
{
	while(x%10==0)
		x/=10;
	return x%10;
}
int ned(int x)
{
	if(x==1||x==3||x==7||x==9)return 10;
	else if(x==2||x==4||x==6||x==8)return 5;
	else if(x==5)return 2;
}
void solve()
{
	cin>>n>>m;
	cnt=f(n);

	while(m!=1)
	{
		int need = ned(h(n));
		if(m<need)
		{
			n*=m;
			break;
		}
		else
		{
			n*=need;
			m/=need;
		}
	}
	cout<<n<<endl;
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