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
int num[maxn];
int p[maxn];
int v[maxn];
int n;
int find(int r){
	return p[r]=p[r]==r?p[r]:find(p[r]);
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		p[i]=i,num[i]=1;
	for(int i=1;i<=n;i++)
		cin>>v[i];
	for(int i=1;i<=n;i++)
	{
		int fa=find(i);
		int fb=find(v[i]);
		if(fa!=fb){
			p[fa]=fb;
			num[fb]+=num[fa];
		}
	}
	for(int i=1;i<=n;i++)
		cout<<num[find(i)]<<" ";
	cout<<endl;
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