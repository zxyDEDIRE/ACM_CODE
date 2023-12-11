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
int f[maxn];
string str;
int n;
int doit(char a)
{
	int now=-1;
	int ans=0;
	for(int i=0;i<str.size();i++)
		if(str[i]==a)
			ans=max(ans,f[i-now-1]),now=i;
	ans=max(ans,f[str.size()-now-1]);
	return ans;
}
void solve()
{
	cin>>str;
	int res=INF;
	for(int i=0;i<26;i++)
		res=min(res,doit('a'+i));
	cout<<res<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	f[0]=0;
	f[1]=1;
	for(int i=2;i<=2e5+10;i++){
		f[i]=f[(i)/2]+1;
	}
	// for(int i=1;i<=10;i++)
	// 	cout<<i<<" "<<f[i]<<endl;
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*

m e wh e nis ee arulhiiarul
0123456 7

1234567890
*/
