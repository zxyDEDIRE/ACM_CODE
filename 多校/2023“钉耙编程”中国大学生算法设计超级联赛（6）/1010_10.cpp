/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
const int mod=998244353;
const int maxn=1e6+100;
vector<int>v[maxn];
bool onT[maxn];
int to[maxn];
int in[maxn];
int k[maxn];
int b[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>k[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	for(int i=1;i<=n;i++)cin>>to[i],in[to[i]]++,onT[i]=true;
	queue<int>q;
	for(int i=1;i<=n;i++)
		if(!in[i])
			q.push(i);
	while(!q.empty()){
		int x=q.front();q.pop();
		onT[x]=false;
		if(--in[to[x]]==0){
			q.push(to[x]);
			v[to[x]].push_back(x);
		}
	}


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