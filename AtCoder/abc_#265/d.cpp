/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
using ll=long long;
using pii=pair<int,int>;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
map<int,int>mp;
int t[maxn];
int n,a,b,c;
void solve()
{
	cin>>n>>a>>b>>c;
	for(int i=1;i<=n;i++){
		cin>>t[i],t[i]+=t[i-1];
		mp[t[i]]=i;
	}
	for(int i=0;i<n;i++)
	{
		int x=t[i];
		if(mp[x+a]&&mp[x+a+b]&&mp[x+a+b+c]){
			cout<<"Yes"<<endl;
			return ;
		}
	}
	cout<<"No"<<endl;

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