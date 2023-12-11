/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define p(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
map<int,int>mp,mpp;
string s;
int n;
int check(int s){
	int last=-1;
	while(mpp[s]!=-1){
		s=mpp[s];
	}
	return s;
}
void solve()
{
	cin>>n>>s;
	s="?"+s;
	mpp.clear();
	mp.clear();
	string res = "";
	for(int i=0;i<26;i++)
		mpp[i]=mp[i]=-1;
	for(int i=1;i<=n;i++)
	{
		if(~mpp[s[i]-'a'])
			res+=(char)(mpp[s[i]-'a']+'a');
		else 
		{
			int t=-1;
			for(int j=0;j<26;j++)
			{
				if(j==s[i]-'a')continue;
				if(mp[j]==-1&&check(j)!=s[i]-'a')
				{
					t = j;
					break;
				}
			}
			if(t==-1)
			{
				for(int j=0;j<26;j++)
					if(mp[j]==-1&&j!=s[i]-'a')t=j;
			}
			mp[t]=s[i]-'a';
			mpp[s[i]-'a']=t;
			res+=(char)(mpp[s[i]-'a']+'a');
		}
	}
	cout << res << endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}