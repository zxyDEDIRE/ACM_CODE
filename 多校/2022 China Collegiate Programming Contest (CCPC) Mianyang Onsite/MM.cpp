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
string s;
int p[maxn];
int n;
int find(int r){
	return p[r]=p[r]==r?p[r]:find(p[r]);
}
void solve()
{
	cin>>s;
	n=s.size();
	s=" "+s;
	for(int i=1;i<=n;i++)
		p[i]=i;
	for(int i=1;i<n;i++)
	{
		int fa=find(i);
		int fb=find(i+1);
		if(s[i]==s[i+1])
			p[fa]=fb;
		else if(s[i]=='R'&&s[i+1]=='P')p[fa]=fb;
		else if(s[i]=='R'&&s[i+1]=='S')p[fb]=fa;
		else if(s[i]=='S'&&s[i+1]=='P')p[fb]=fa;
		else if(s[i]=='S'&&s[i+1]=='R')p[fa]=fb;
		else if(s[i]=='P'&&s[i+1]=='R')p[fb]=fa;
		else if(s[i]=='P'&&s[i+1]=='S')p[fa]=fb;
		for(int j=1;j<=n;j++)
			cout<<find(j)<<" ";cout<<endl;
	}
}
/*
PPRSRSPSPR
p-> R-> S <-R-> S-> P <-S-> P-> R
p-> R-> S-> P <-S-> P-> R
p-> R-> S-> P <-S
p-> R-> S
*/
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