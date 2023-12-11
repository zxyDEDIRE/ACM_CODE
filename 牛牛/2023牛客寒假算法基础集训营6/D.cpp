/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
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
int a[maxn];
int b[maxn];
int dp[10];
string str;
int ma=0;
int n;
void solve()
{
	cin>>str;
	n=str.size();
	int ma=0,fl=0;
	for(int i=0;i<str.size();i++)
	{
		if(str[i]=='d')dp[1]+=dp[0];
		else if(str[i]=='u')
		{
			if(ma<dp[1])
			{
				ma=dp[1];
				fl=i;
			}
			dp[2]+=dp[1];
			dp[0]++;
		}
	}
	for(int i=0;i<n;i++)
		a[i]+=a[i-1]+(str[i]=='u'?1:0);
	for(int i=n-1;i>=0;i--)
		b[i]+=b[i+1]+(str[i]=='u'?1:0);
	
	for(int i=0;i<n;i++)
	{
		if(str[i]=='d')
		{
			if(ma<a[i]*b[i])
			{
				ma=a[i]*b[i];
				fl=i;
			}
		}
	}
	// cout<<fl<<endl;
	// cout<<ma<<endl;
	for(int i=0;i<n;i++)
		if(i!=fl)cout<<str[i];
		else cout<<'a';
	cout<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
uuduuduu
auduuduu
uaduuduu
uuauuduu
uudauduu
uuduaduu
uuduuauu
uuduudau
uuduudua
*/