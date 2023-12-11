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
vector<int>v[maxn];
int p[maxn];
int n,q;
void solve()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		int x=p[i];
		for(int j=1;j<=sqrt(x);j++){
			if(x%j==0){
				v[j].push_back(i);
				if(x/j!=j)v[x/j].push_back(i);
			}
		}

	}
	int now=n;
	while(q--)
	{
		int op,x;
		cin>>op>>x;
		if(op==1)
		{
			now++;
			p[now]=x;
			for(int j=1;j<=sqrt(x);j++){
				if(x%j==0){
					v[j].push_back(now);
					if(x/j!=j)v[x/j].push_back(now);
				}
			}
		}
		else
		{
			int y=p[x];
			int fl=upper_bound(v[y].begin(),v[y].end(),x)-v[y].begin();
			cout<<v[y].size()-fl<<endl;
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
	// clock_t start, finish;
	// start = clock();
	solve();
	// finish = clock();
	// cout << "the time cost is" << double(finish - start) / CLOCKS_PER_SEC;
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
0 1 2
3
*/