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
	int n;
	vector<int>p;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int x;cin>>x;
		if(!p.size()||p.back()!=x)
			p.push_back(x);
	}
	int ma=*max_element(p.begin(),p.end());
	int cnt=0;
	if(p.size()>1)
	for(int i=0;i<p.size();i++)
	{
		if(i==0&&p[1]<p[0])cnt++;
		else if(i==p.size()-1&&p[i-1]<p[i])cnt++;
		else if(p[i-1]<p[i]&&p[i+1]<p[i])cnt++;
	}
	if(cnt<=1)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
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