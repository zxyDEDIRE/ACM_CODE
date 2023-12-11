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
void solve()
{
	int n,m,flag=0;;
	vector<int>in;
	cin>>n>>m;
	in.resize(n+1);
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		in[x]++;
		in[y]++;
	}
	//n
	if(n<=3)flag=1;
	// jvhua
	int cnt_1=0,cnt_2=0;
	for(int i=1;i<=n;i++)
		if(in[i]==1)cnt_1++;
		else if(in[i]==n-1)cnt_2++;
	if(cnt_1==n-1&&cnt_2==1)flag=1;
	//gudu
	int cnt_a=0,cnt_b=0;
	for(int i=1;i<=n;i++)
		if(in[i]==n-2)cnt_a++;
		else if(in[i]==0)cnt_b++;
	if(cnt_a==n-1&&cnt_b==1)flag=1;
	//wanquan
	int cnt_x=0,cnt_y=0;
	for(int i=1;i<=n;i++)
		if(in[i]==n-1)cnt_x++;
		else cnt_y++;
	if(cnt_x==n&&cnt_y==0)flag=1;
	//si ge cheng huan
	if(n==4)
	{
		if(m==4&&in[1]==2&&in[2]==2&&in[3]==2&&in[4]==2)flag=1;
		if(m==2&&in[1]==in[2]&&in[3]==in[4]&&in[1]==in[3]&&in[1]==1)flag=1;
	}
	if(flag)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}