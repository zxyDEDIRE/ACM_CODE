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
int sa[100];
int sb[100];
string a,b;
int n;
void solve()
{
	cin>>n>>a>>b;
	for(auto i:a)
		sa[i-'a']++;
	for(auto i:b)
		sb[i-'a']++;
	for(int i=0;i<26;i++)
		if(sa[i]!=sb[i]){
			cout<<-1<<endl;
			return ;
		}
	a=" "+a;
	b=" "+b;
	int l=0,r=0;
	while(l<n)
	{
		r=0;
		while(l<n&&a[l+1]==b[r+1])
			l++,r++;
		if(r==0)l++;
	}
	cout<<n-r<<endl;
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
abcd
dcba
abc
acb
*/