/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define p(x) array<int,x>
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
int n;
void solve()
{
	cin>>n>>str;
	int fl=-1;
	for(int i=0;i<n;i++)
	{
		if(str[i]=='B')fl=1;
		else if(str[i]=='R')fl=2;
		else
		{
			if(fl==1)str[i]='R',fl=2;
			else if(fl==2)str[i]='B',fl=1;
		}
	}
	if(fl==-1)str.back()='R';
	for(int i=n-1;i>=0;i--)
	{
		if(str[i]=='B')fl=1;
		else if(str[i]=='R')fl=2;
		else
		{
			if(fl==1)str[i]='R',fl=2;
			else if(fl==2)str[i]='B',fl=1;
		}
	}
	cout<<str<<endl;
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
/*
?R???BR
BRBRBBR
*/