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
string str;
int n;
void solve()
{
	cin>>n>>str;
	vector<int>cnt(40);
	for(int i=0,j=n-1;i<j;i++,j--)
	{
		if(str[i]==str[j])
		{
			cnt[str[i]-'a']++;
		}
		else cout<<str[i]<<" "<<str[j]<<endl;
	}
	for(int i=0;i<26;i++)
		if(cnt[i]){
			cout<<char('a'+i)<<" ";
			cout<<cnt[i]<<endl;
		}


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
aa
bb
cc
10
cccbcabaaa

cccabcabaa
*/