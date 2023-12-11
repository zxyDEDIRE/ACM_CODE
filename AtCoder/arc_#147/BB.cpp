/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
vector<pair<char,int> >v;
int p[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j+2<=n;j++)
		{
			if(p[j]>p[j+2])
			{
				swap(p[j],p[j+2]);
				v.push_back({'B',j});
			}
		}
	}
	for(int i=1;i<=n;i++)
	{ 
		for(int j=i;j+1<=n;j++)
		{
			if(p[j]>p[j+1])
			{
				swap(p[j],p[j+1]);
				v.push_back({'A',j});
			}
		}
	}
	cout<<v.size()<<endl;
	for(auto i:v)
		cout<<i.first<<" "<<i.second<<endl;

}
signed main(){
//  freopen("in1.txt","r",stdin);
//  freopen("out1.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}