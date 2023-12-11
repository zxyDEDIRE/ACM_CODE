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
string str;
int n,k;
void solve()
{
	cin>>n>>k>>str;
	for(int len=1;len<=n;len++)
	{
		if(n%len!=0)continue;
		vector<vector<int>>v(len,vector<int>(27,0));
		for(int i=0;i<n;i++)
		{
			v[i%len][str[i]-'a']++;
			v[i%len][26]++;
		}
		int tot=0;
		for(int i=0;i<len;i++)
		{
			int ma=0;
			for(int j=0;j<26;j++)
				ma=max(ma,v[i][j]);
			tot+=v[i][26]-ma;
		}
		if(tot<=k){
			cout<<len<<endl;
			return ;
		}
	}
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
abaaba
baabaa
aabaab
*/