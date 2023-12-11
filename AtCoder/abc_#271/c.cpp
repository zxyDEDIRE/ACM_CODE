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
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
map<int,int>mp;
deque<int>q;
int p[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		if(!mp[p[i]])mp[p[i]]=1;
		else p[i]=INF+p[i];
	}
	sort(p+1,p+1+n);
	for(int i=1;i<=n;i++)
		q.push_back(p[i]);
	int fl=1;
	for(int i=1;;i++)
	{
		if(q.size()==0){
			cout<<fl-1<<endl;
			return ;
		}
		int x=q.front();
		if(x==fl)fl++,q.pop_front();
		else if(x<fl)
		{
			q.pop_front();
			q.push_back(INF);
		}
		else if(x>fl)
		{
			if(q.size()<2){
				cout<<fl-1<<endl;
				return ;
			}
			fl++;
			q.pop_back();
			q.pop_back();
		}
	}
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
/*
5
1 3 3 3 4
*/
