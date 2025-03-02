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


class Solution {
public:
	vector<vector<int>> sandyLandManagement(int size) {
		vector<vector<int> >ans;
		if(size<=3)
		{
			for(int i=1;i<=size;i++)
			{
				if(i==1)ans.push_back({1,1});
				else
				{
					ans.push_back({i,1});
					ans.push_back({i,i*2-1});
				}
			}
		}
		else if(size%2==1)
		{
			ans.push_back({1,1});
			ans.push_back({2,1});
			ans.push_back({3,3});
			ans.push_back({3,5});
			for(int i=5;i<=size;i+=2)
			{
				ans.push_back({i-1,2});
				for(int j=2;j<=i*2-1;j+=2)
					ans.push_back({i,j});
			}
		}
		else if(size%2==0)
		{
			ans.push_back({1,1});
			ans.push_back({2,1});
			ans.push_back({2,3});
			for(int i=4;i<=size;i+=2)
			{
				ans.push_back({i-1,2});
				for(int j=2;j<=i*2-1;j+=2)
					ans.push_back({i,j});
			}
		}
		return ans;
	}
};

void solve()
{

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
[[1,1],[2,1],[2,3],[3,1],[4,3],[4,5],[4,7],[5,2],[6,1],[6,3],[6,5],[6,7],[6,9],[6,11],[7,1],[8,3],[8,5],[8,7],[8,9],[8,11],[8,13],[8,15],[9,2],[10,1],[10,3],[10,5],[10,7],[10,9],[10,11],[10,13],[10,15],[10,17],[10,19]]
*/