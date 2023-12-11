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
const int dx[]={-1,-1,0,0,1,1};
const int dy[]={-1,0,-1,1,0,1};
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
map<pii,pii>p;
int n;
pii find(pii r){
	return p[r]=p[r]==r?p[r]:find(p[r]);
}
void solve()
{
	cin>>n;
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		int x,y;
		cin>>x>>y;
		p[{x,y}]={x,y};
		cnt++;
		for(int k=0;k<6;k++)
		{
			int xx=x+dx[k];
			int yy=y+dy[k];
			if(p.count({xx,yy}))
			{
				pii fa=find({x,y});
				pii fb=find({xx,yy});
				if(fa!=fb)
				{
					p[fa]=fb;
					cnt--;
				}
			}
		}
	}
	cout<<cnt<<endl;
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