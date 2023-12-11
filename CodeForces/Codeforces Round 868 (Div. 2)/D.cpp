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
char S[maxn];
int ans;
pii p[maxn];
int n,k;
void NO(){cout<<"NO"<<endl;}
void solve()
{
	cin>>n>>k;
	p[0]={0,0};
	ans=0;
	for(int i=1;i<=k;i++)cin>>p[i].first;
	for(int i=1;i<=k;i++)cin>>p[i].second;
	for(int i=1;i<=k;i++)
		if(p[i].second-p[i-1].second>p[i].first-p[i-1].first)
			return NO();
	string fl="abc";
	S[1]='a',S[2]='b',S[3]='c';
	ans=3;
	char now='d';
	int j=0;
	for(int i=1;i<=k;i++)
	{
		int len=p[i].first-p[i-1].first;
		int num=p[i].second-p[i-1].second;
		int s=1;
		int nxt=0;
		// cout<<i<<" "<<s<<endl;
		if(i==1)s=4;
		for(int i=s;i<=num;i++)
			S[++ans]=now;
		for(int i=num+1;i<=len;i++,j++)
			S[++ans]=fl[j%3];
		if(num)now++;
	}
	cout<<"YES"<<endl;
	for(int i=1;i<=n;i++)
		cout<<S[i];
	cout<<endl;
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
abcccdabca
abccdaeeea
abccdaeeea
abccdaeeeb
abccdaeeeb
YES
abcccdabab
YES
abc
YES
abca
YES
abcd
NO
YES
abccdaeeeb
NO

=====
Used: 15 ms, 7832 KB
*/