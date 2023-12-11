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
const int maxn=1e6;
string mp[maxn];
int a[maxn],b[maxn];
int p[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>mp[i];
		for(auto ch:mp[i])
			if(ch=='X')a[i]++;
			else b[i]+=(ch-'0');
		p[i]=i;
	}
	sort(p+1,p+1+n,[&](int x,int y){
		return  b[y]*a[x]>b[x]*a[y];
	});
	int ans=0;
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		string str=mp[p[i]];
		for(auto i:str)
			if(i=='X')cnt++;
			else ans+=cnt*(i-'0');
	}
	cout<<ans<<endl;

}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}