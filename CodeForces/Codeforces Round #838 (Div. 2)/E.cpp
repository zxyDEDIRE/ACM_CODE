/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
// #define endl "\n"
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
int q(int x,int y){
	cout<<"? "<<x<<" "<<y<<endl;
	cin>>x;
	return x;
}
void solve()
{
	int n;
	cin>>n;
	int x=1,y=2;
	int ma=q(x,y);
	for(int i=3;i<=n;i++)
	{
		int ma_x=q(x,i);
		int ma_y=q(y,i);
		if(ma_x>=max(ma,ma_y))
			y=i,ma=ma_x;
		else if(ma_y>=max(ma,ma_x))
			x=i,ma=ma_y;
	}
	cout<<"! "<<x<<" "<<y<<endl;
	int ans;
	cin>>ans;
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
1 3 4 0 2
*/