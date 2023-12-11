/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define x first
#define y second
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
pii p[maxn];
int ans;
int n;
int ms(pii p[],int l,int r)
{
	if(l==r)return 0;
	int mid=(l+r)>>1;
	return ms(p,l,mid)+ms(p,mid+1,r);
	vector<int>tmp(r-l+2);
	

}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i].x;
	for(int i=1;i<=n;i++)
		cin>>p[i].y;
	cout<<ms(p,1,n)<<endl;
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