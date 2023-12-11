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
	vector<int>v;
	string str;
	int n;	
	cin>>n>>str;
	for(int i=0;i<str.size();i++)
	{
		if(str[i]!='R')continue;
		int fl=0;
		while(i-fl-1>=0&&i+fl+1<n&&str[i-fl-1]=='A'&&str[i+fl+1]=='C')
			fl++;
		if(fl)
			v.push_back(fl);
	}
	int a=0,b=0;
	for(auto i:v)
		if(i==1)a++;
		else b++;
	int sum=accumulate(v.begin(),v.end(),0);
	int ans=v.size();
	sum-=ans;
	for(int i=0;i<v.size();i++)
		if(sum>0&&i%2==0)
			ans++,sum--;
	cout<<ans<<endl;
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