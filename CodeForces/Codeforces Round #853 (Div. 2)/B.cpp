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
void solve()
{
	int n;
	string str;
	vector<bool>vis;

	cin>>n>>str;
	vis.resize(n);

	for(int i=0;i<(n+1)/2;i++)
	{
		if(str[i]!=str[n-i-1])
			vis[i]=1;
	}
	int cnt=0,len=0;
	for(int i=0;i<(n+1)/2;i++)
	{
		if(vis[i])
		{
			if(len==0)cnt++;
			len++;
		}
		else len=0;
	}
	if(cnt>1)cout<<"No"<<endl;
	else cout<<"Yes"<<endl;
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