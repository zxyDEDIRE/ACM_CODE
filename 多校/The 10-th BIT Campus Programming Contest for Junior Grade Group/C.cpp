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
vector<int> grayCode(int n) {
	int count = 1 << n;
	vector<int> res(count,0);
	for(int i = 1 ; i < count; i ++)
	{
		int bin = i,cur = bin >> (n - 1);
		for(int k = n - 1;k > 0;k --)
			cur = (cur << 1) + (((bin >> k) & 1) ^ ((bin >>(k - 1)) & 1));
		res[i] = cur;
	}
	return res;
}
int ma[maxn];
int p[maxn];
void solve()
{
	int n,x;
	cin>>n>>x;
	if(x<ma[n])cout<<"NO"<<endl;
	else
	{
		cout<<"YES"<<endl;
		for(int i=1;i<=n;i++)
			cout<<p[i]<<" ";
		cout<<endl;
	}
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	vector<int>v=grayCode(10);
	int len=v.size();
	p[1]=1;
	for(int i=2;i<len;i++)
		p[i]=(v[i]^v[i-1]);
	for(int i=1;i<len;i++)
		ma[i]=max(p[i],ma[i-1]);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
00000
00001
00011
00010
00110
00111
00101
00100

00001
00010
00001
00100
00001
00010
00001
*/