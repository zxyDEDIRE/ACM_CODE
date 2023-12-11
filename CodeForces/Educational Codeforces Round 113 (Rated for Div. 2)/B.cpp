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
	string str;int n;
	vector<int>v;
	int cnt_a=0,cnt_b=0;
	cin>>n>>str;
	for(int i=0;i<n;i++)
		if(str[i]=='1')cnt_a++;
	else cnt_b++,v.push_back(i+1);
	if(cnt_b>0&&cnt_b<=2){
		cout<<"NO"<<endl;
		return ;
	}
	cout<<"YES"<<endl;
	map<pii,bool>win,los;
	if(v.size()>=2)
	{
		for(int i=0;i<v.size()-1;i++)
		{
			los[{v[i+1],v[i]}]=1;
			win[{v[i],v[i+1]}]=1;
		}
		los[{v[0],v.back()}]=1;
		win[{v.back(),v[0]}]=1;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j)cout<<"X";
			else if(win.count({i,j}))cout<<"+";
			else if(los.count({i,j}))cout<<"-";
			else cout<<"=";
		}
		cout<<endl;
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