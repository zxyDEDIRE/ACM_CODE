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
	bool checkArray(vector<int>& p, int k) {
		int n=p.size();
		vector<int>v(n);
		v[0]=p[0];
		for(int i=1;i<n;i++)
			v[i]=p[i]-p[i-1];
		for(auto i:v)
			cout<<i<<" ";cout<<endl;


		int sum=0;
		p.push_back(0);
		for(int i=0;i<n;i++)
		{
			sum+=v[i];
			if(sum>0 && i+k<=n)
			{
				v[i+k]+=sum;
				v[i]=0;
				sum=0;
			}

			for(auto j:v)
				cout<<j<<" ";cout<<endl;

			if(sum)return false;
		}


		return true;
	}
};
/*
0 1 2 
2 2 3 1 1 0
2 0 1 -2 0 0
*/

void solve()
{
	Solution a;
	vector<int>x={2,2,3,1,1,0};
	cout<<a.checkArray(x,3)<<endl;
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