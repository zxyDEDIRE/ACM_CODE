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
const int maxn=1e6+100;
vector<pii>v;
int n;
void q(int x,int y)
{
	cout<<"? "<<x<<" "<<y<<endl;
}
void solve()
{
	cin>>n;
	srand((unsigned)time(NULL));
	int x = rand() % (n+1);
	while(x==0)x+=rand()%(n+1);

	for(int i=1;i<=n;i++)
	{
		if(i==x)continue;
		q(x,i);
		int y;
		cin>>y;
		if(y==0){
			cout<<"! "<<x<<" "<<i<<endl;
			return ;
		}
		else if(y!=1)
			v.push_back({i,y});
	}
	if(v.size()==n-2){
		cout<<"! "<<x<<" "<<x<<endl;
		return ;
	}
	while(1)
	{
		if(v.size()==1){
			cout<<"! "<<v[0].first<<" "<<v[0].first<<endl;
			return ;
		}
		vector<pii>u;
		sort(v.begin(),v.end(),[&](pii a,pii b){
			return a.second<b.second;
		});
		pii a=v[0];
		for(int i=1;i<v.size();i++)
		{
			q(a.first,v[i].first);
			int ans;
			cin>>ans;
			if(ans==0){
				cout<<a.first<<" "<<v[i].first<<endl;
				return ;
			}
			else if(ans>=a.second)
				u.push_back({i,ans});
		}
		v=u;
	}

}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
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
0 1 2 3
0 2 4 8

0 4 8
2 2 2

*/