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
ll T[maxn];
vector<int>v;
int ok[100];
string s,t;
int n,k;
ll ans;
ll f()
{
	// for(int i=0;i<26;i++)
	// 	if(ok[i]){
	// 		cout<<(char)(i+'a')<<" ";
	// 	}
	// 	cout<<endl;
	int len=0;
	ll sum=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]==t[i]||ok[s[i]-'a']==1)
			len++;
		else sum+=T[len],len=0;
	}
	sum+=T[len];
	// cout<<sum<<endl;
	return sum;
}
void dfs(int x,int step)
{
	if(x==v.size()+1)return ;
	if(step>k)return ;
	if(step==k)
	{
		ans=max(ans,f());
		return ;
	}
	dfs(x+1,step);
	ok[s[x]-'a']=1;
	dfs(x+1,step+1);
	ok[s[x]-'a']=0;
}
void solve()
{
	cin>>n>>k>>s>>t;
	set<char>sa;
	for(auto i:s)
		sa.insert(i);
	v.clear();
	ans=0;
	for(auto i:sa)
		v.push_back(i);
	k=min(k,(int)sa.size());
	dfs(0,0);
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	for(int i=1;i<=1e5;i++)
		T[i]=T[i-1]+i;
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
10 3
lkwhbahuqa
qoiujoncjb

1 1
2 3
3 6
4 10
1 2 3 4
12 23 34
123 234
1234
*/