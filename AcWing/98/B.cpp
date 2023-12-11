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
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
string p[maxn];
int n;
void solve()
{
	cin>>n;
	int len=0;
	string ans="1";
	for(int i=1;i<=n;i++)
	{
		string x;cin>>x;
		int flag=1;
		if(x[0]=='0'){
			cout<<"0"<<endl;
			return ;
		}
		if(x[0]!='1')flag=0;
		if(flag)
		{
			for(int i=1;i<x.size();i++)
				if(x[i]!='0')flag=0;
		}
		if(flag)len+=x.size()-1;
		else ans=x;
	}
	cout<<ans;
	for(int i=1;i<=len;i++)
		cout<<"0";
	cout<<endl;
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