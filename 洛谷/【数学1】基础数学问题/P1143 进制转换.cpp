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
void solve()
{
	int s,t;
	string n;
	cin>>s>>n>>t;

	auto A=[&](int s,string n)->int{
		int ans=0;
		int now=1;
		reverse(n.begin(),n.end());
		for(int i=0;i<n.size();i++)
		{
			int x;
			if(n[i]>='0'&&n[i]<='9')x=n[i]-'0';
			else x=n[i]-'A'+10;
			ans+=now*x;
			now*=s;
		}
		return ans;
	};

	int x=A(s,n);
	vector<char>v;
	while(x)
	{
		int y=x%t;
		if(y<=9)v.push_back((char)(y+'0'));
		else v.push_back((char)(y-10+'A'));
		x/=t;
	}
	reverse(v.begin(),v.end());
	for(auto i:v)
		cout<<i;
	cout<<endl;
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