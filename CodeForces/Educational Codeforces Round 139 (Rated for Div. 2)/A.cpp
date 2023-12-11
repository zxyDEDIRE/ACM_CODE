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
const int maxn=1999999;
int p[maxn];
bool check(int x)
{
	int cnt=0;
	while(x){
		int y=x%10;
		if(y)cnt++;
		x/=10;
	}
	if(cnt==1)return 1;
	else return 0;
}
void doit()
{
	for(int i=1;i<=999999;i++)
	{
		if(check(i))p[i]++;
		p[i]+=p[i-1];
	}
}
void solve()
{
	int n;
	cin>>n;
	cout<<p[n]<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	doit();
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}