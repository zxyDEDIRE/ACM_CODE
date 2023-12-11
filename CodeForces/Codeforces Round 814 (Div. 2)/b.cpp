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
bitset<maxn>vis;
vector<int>v;
int p[maxn];
int n,k;
void solve()
{
	cin>>n>>k;
	k%=4;
	if(k==0){
		cout<<"No"<<endl;
		return ;
	}
	cout<<"Yes"<<endl;
	for(int i=1;i<=n;i+=4)
	{
		if(k==2)
		{
			cout<<i+1<<" "<<i<<endl;
			if(i+3<=n)cout<<i+2<<" "<<i+3<<endl;
		}
		else
		{
			cout<<i<<" "<<i+1<<endl;
			if(i+3<=n)cout<<i+2<<" "<<i+3<<endl;
		}
	}
}
signed main(){
//  freopen("in1.txt","r",stdin);
//  freopen("out1.txt","w",stdout);
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
1 2 3 4
0 
1 1 2 3 4   1 2
2 2 1 3 4   2 1
3 1 2 3 4   1 2
*/