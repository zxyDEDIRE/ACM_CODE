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
const int maxn=1e6;
struct node{
	int x,y;
};
vector<node>v;
vector<int>ans;
string str;
int n,a,b,k;
int num=0;
void solve()
{
	cin>>n>>a>>b>>k>>str;
	str=" "+str;
	int len=0;
	for(int i=1;i<=n;i++)
	{
		if(str[i]=='0')len++;
		else
		{
			if(len!=0&&len>=b)
			{
				v.push_back({i-len,len});
				num+=len/b;
			}
			len=0;
		}
	}
	if(len!=0&&len>=b)
	{
		v.push_back({(n)-len+1,len});
		num+=len/b;
	}
	int fl=0;
	for(int i=0;i<v.size();i++)
	{
		for(int j=v[i].x,k=1;k<=v[i].y;j+=b,k+=b)
		{
			if(k+b-1<=v[i].y)
				ans.push_back(j+b-1),num--;
			if(num<a)break;
		}
		if(num<a)break;
	}
	sort(ans.begin(),ans.end());
	cout<<ans.size()<<endl;
	for(auto i:ans)
		cout<<i<<" ";cout<<endl;
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
/*
13 3 2 3
1010100010001
*/