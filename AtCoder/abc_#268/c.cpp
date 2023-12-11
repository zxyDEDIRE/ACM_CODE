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
map<int,int>mp;
int p[maxn];
int n;
int f(int x){
	return (x%n+n)%n;
}
void solve()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>p[i];
		mp[f(p[i]-i)]++;
		mp[f(p[i]+1-i)]++;
		mp[f(p[i]-1-i)]++;
	}
	int ma=0;
	for(int i=0;i<n;i++)
		ma=max(ma,mp[i]);
	cout<<ma<<endl;

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