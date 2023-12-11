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
int p[100];
string str;
void solve()
{
	cin>>str;
	for(auto i:str)
	{
		if(i>='0'&&i<='9')p[i-'0']++;
		else p[i-'a'+10]++;
	}
	int ans=0;
	for(auto i:str)
	{
		if(i>='0'&&i<='9')
		{
			ans+=p[i-'0'],p[i-'0']--;
			ans+=p[i-'0'];
		}
		else
		{
			ans+=p[i-'a'+10],p[i-'a'+10]--;
			ans+=p[i-'a'+10];
		}
	}
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
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

*/