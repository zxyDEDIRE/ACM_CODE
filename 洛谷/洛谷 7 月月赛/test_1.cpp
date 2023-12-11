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
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;

class Solution {
public:
	int sumImbalanceNumbers(vector<int>& p) {
		int n=p.size();
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			set<int>s;
			int cnt=0;
			for(int j=i;j<=n;j++)
			{
				int x=p[j-1];
				if(s.count(x)){
					ans+=cnt;
					continue;
				}
				s.insert(x);
				
				
				if((*s.begin())!=x && (*s.rbegin())!=x)
				{
					int a=*(--s.lower_bound(x));
					int b=*(++s.lower_bound(x));
					if(b-a>1)cnt--;
					if(x-a>1)cnt++;
					if(b-x>1)cnt++;
				}
				else if((*s.begin()) == x)
				{
					int b=*(++s.lower_bound(x));
					if(b-x>1)cnt++;
				}
				else if((*s.rbegin()) == x)
				{
					int a=*(--s.lower_bound(x));
					if(x-a>1)cnt++;
				}
				cout<<i<<" "<<j<<" "<<cnt<<endl;
				ans+= cnt;
			}
		}
		return ans;
	}
};

void solve()
{
	vector<int>p={1,3,3,3,5};
	cout<<Solution().sumImbalanceNumbers(p)<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}