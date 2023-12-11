/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
string s,t;
void solve()
{
	vector<int>v;
	cin>>s>>t;
	reverse(s.begin(),s.end());
	reverse(t.begin(),t.end());
	int ma=(int)max(s.size(),t.size());
	while((int)s.size()<ma)s=s+'0';
	while((int)t.size()<ma)t=t+'0';
	reverse(s.begin(),s.end());
	reverse(t.begin(),t.end());
	int flag=0;
	int ans=0;
	for(int i=0;i<ma;i++)
	{
		if(flag==0)
		{
			if(t[i]>s[i])flag=1;
			ans+=abs(s[i]-t[i]);
		}
		else if(flag==1)
		{
			ans+=9;
		}
	}
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
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
88 1914

1914
0088
*/