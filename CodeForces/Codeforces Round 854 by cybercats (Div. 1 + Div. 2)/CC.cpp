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
	string str;
	vector<char>ans;
	vector<int>cnt(30,0);

	cin>>str;
	int n=str.size();
	ans.resize(n);

	for(auto i:str)
		cnt[i-'a']++;
	int l=0,r=n-1;
	for(int i=0;i<26;i++)
	{
		while(cnt[i]>=2)
		{
			ans[l++]='a'+i;
			ans[r--]='a'+i;
			cnt[i]-=2;
		}
		if(cnt[i])
		{
			if(l==r)ans[l]='a'+i;
			else
			{
				int x=i+1;
				while(cnt[x]==0)x++;
				if(cnt[x]==r-l)
				{
					while(cnt[x]>=2)
					{
						ans[l++]='a'+x;
						ans[r--]='a'+x;
						cnt[x]-=2;
					}
					if(cnt[x])ans[l++]='a'+x;
					ans[l]='a'+i;
				}
				else
				{
					for(;x<26;x++)
						while(cnt[x]){
							ans[l++]='a'+x;
							cnt[x]--;
						}
					ans[r]='a'+i;
				}
			}
			break;
		}
	}
	for(auto i:ans)
		cout<<i;
	cout<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
abbb
*/