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
bitset<maxn>vis;
string s;
int n,m;
int MI()
{
	int cnt=m/4;
	int ans=0;
	int num=0;
	for(int i=1;i<=m;i++)
		if(s[i]=='1')num++;
	for(int i=2;i<=m;i++)
		if(cnt&&s[i-1]=='1'&&s[i]=='1')
		{
			i++;
			ans++;
			cnt--;
		}
	return num-min(ans,m/4);
}
int MA()
{
	int cnt=0;
	int num=0;
	for(int i=1;i<=m;i++)
		if(s[i]=='1')num++;
	for(int i=1;i<=m;i++)
	{
		if(i+1<=m&&(s[i]!=s[i+1]||s[i]=='0'))
			cnt++,i++;
	}
	if(cnt<=m/4)
		return num-(m/4-cnt);
	else return num;
}
void solve()
{
	cin>>n>>m;
	int ans_mi=0,ans_ma=0;
	for(int tp=1;tp<=n;tp++)
	{
		cin>>s;
		s=" "+s;
		ans_mi+=MI();
		ans_ma+=MA();
		// cout<<tp<<" "<<MI()<<endl;
	}
	cout<<ans_mi<<" "<<ans_ma<<endl;
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
/*
5 4
0000
1100
0110
1010
1011

*/