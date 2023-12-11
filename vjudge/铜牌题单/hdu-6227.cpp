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
vector<int>v;
int p[maxn];
int n;
void solve()
{
	cin>>n;
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		if(i!=1)
			sum+=p[i]-p[i-1]-1;
	}
	int fa=p[2]-p[1]-1;
	int fb=p[n]-p[n-1]-1;
	cout<<sum-min(fa,fb)<<endl;
}
signed main(){
 // freopen("C:\Users\tob\Desktop\P4391_9.in.txt","r",stdin);
 // freopen("C:\Users\tob\Desktop\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}