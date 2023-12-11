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
string str;
int n,k;
int f()
{
	str=str+"1";
	int fl=str[1];
	int cnt=0;
	int ans=0;
	for(int i=1;i<=n+1;i++)
	{
		if(str[i]=='1')
		{
			ans+=cnt*(cnt+1)/2;
			cnt=0;
		}
		else cnt++;
	}
	return ans;
}
/*
000
0 0 0
00 00
000

0000
0 0 0 0
00 00 00 
000 000
0000
*/
void solve()
{
	cin>>k>>str;
	n=str.size();
	str=" "+str;
	if(k==0){
		cout<<f()<<endl;
		return ;
	}
	int ans=0,cnt=0;
	deque<int>q;
	int j=1;
	for(int i=1;i<=n;i++)
	{
		while(j<=n&&cnt<=k)
		{
			if(str[j]=='1'&&cnt==k)break;
			else if(str[j]=='1')q.push_back(j),cnt++;
			j++;
		}
		if(q.size()<k)break;
		int r=j-q.back();
		ans+=r;
		if(str[i]=='1')
		{
			cnt--;
			q.pop_front();
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
0
100101001010

0 0 0
00 00
000
0 0
00
*/