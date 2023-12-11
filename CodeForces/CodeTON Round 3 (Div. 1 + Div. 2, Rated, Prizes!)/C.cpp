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
string s,t;
int n;
void solve()
{
	cin>>n>>s>>t;
	int fa=1,fb=1;
	for(int i=0;i<n;i++)
		if(s[i]==t[i])fb=0;
		else if(s[i]!=t[i])fa=0;
	if(!fa&&!fb){
		cout<<"No"<<endl;
		return ;
	}
	cout<<"Yes"<<endl;
	int l=0,r=n-1,cnt=0;
	vector<pii>ans;
	while(l<=r)
	{

		if(cnt&1)
		{
			if(s[l]=='0'&&s[r]=='0')
				ans.push_back({l,r}),l++,r--,cnt++;
			else if(s[l]=='1')l++;
			else if(s[r]=='1')r--;
		}
		else
		{
			if(s[l]=='1'&&s[r]=='1')
				ans.push_back({l,r}),l++,r--,cnt++;
			else if(s[l]=='0')l++;
			else if(s[r]=='0')r--;
		}
	}
	if(s[0]=='1')cnt--;
	if(t[0]=='0'&&(cnt%2)==0);
	else if(t[0]=='1'&&(cnt%2)==1);
	else
	{
		ans.push_back({1-1,1-1});
		ans.push_back({1-1,n-1});
		ans.push_back({2-1,n-1});
	}
	cout<<ans.size()<<endl;
	for(auto [x,y]:ans)
		cout<<x+1<<" "<<y+1<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
0101
0101
|
0010
1101
|
0000
0000

01001
10110
|
00110
00110
|
00000
11111
|
10000
10000
|
01111
10000
|
00000
00000


111
111
|
000
111
|
100
100
|
011
100
|
000
000

10
10
|

*/