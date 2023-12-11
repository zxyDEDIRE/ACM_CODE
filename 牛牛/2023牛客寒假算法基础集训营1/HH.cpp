/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define p(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
string p[maxn];
vector<int>v[20];
int n;
vector<int> vector_set_intersection(vector<int>v1 ,vector<int>v2){
	vector<int>v;
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),back_inserter(v));
	return v;
}
void solve()
{
	cin>>n;
	int sum=n*n*10;
	for(int i=1;i<=n*n-1;i++)
	{
		cin>>p[i];
		for(int j=0;j<4;j++)
		{
			if(p[i][j]=='1')sum--;
			if(p[i][j]=='2')sum++;
		}
	}
	cout<<n*n*10-sum+10<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}