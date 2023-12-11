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
string s;
string f(string now)
{
	reverse(now.begin(),now.end());
	int flag=0;
	for(int i=0;i<now.size();i++)
	{
		now[i]-=1;
		if(now[i]<='0'){
			if(i!=now.size()-1)
				now[i]='9';
			else{
				flag=1;
			}
		}
		else break;
	}
	if(flag)now.erase(now.end()-1);
	reverse(now.begin(),now.end());
	return now;
}
void solve()
{
	cin>>s;
	int n=s.size();
	int ans=0;
	for(int len=1;len<=n/2;len++)
	{
		if(n%len!=0)continue;
		// cout<<"LEN "<<len<<endl;
		string t="";
		int flag=1;
		for(int i=0;i<len;i++)
			t=t+s[i];
		// cout<<"T "<<t<<endl;
		for(int i=len;i<n;i+=len)
		{
			string now="";
			for(int j=0;j<len;j++)
				now=now+s[i+j];
			// cout<<"Now "<<now<<endl;
			if(now<t&&flag==1)
				t=f(t),flag=0;
		}
		string now="";
		for(int i=1;i<=(n/len);i++)
			now=now+t;
		// cout<<"NOW "<<now<<endl;
		int now_ans=stoll(now);
		ans=max(ans,now_ans);
	}
	int MAX = stoll(string(n-1,'9'));
	ans=max(ans,MAX);
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
/*
100
*/