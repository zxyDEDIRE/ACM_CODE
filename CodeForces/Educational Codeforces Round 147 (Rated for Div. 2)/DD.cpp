/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long 
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e18+7;
const int maxn=1e6+100;
struct node{
	int x,len;
}p[maxn];
int l[maxn];
int r[maxn];
int n,k;
void solve(int op)
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>l[i];
	for(int i=1;i<=n;i++)cin>>r[i];
	for(int i=1;i<=n;i++)
		p[i].x=r[i],p[i].len=r[i]-l[i]+1;
	int ans=INF;
	int now=0;
	if(op==1215){
		cout<<"F"<<n<<"P"<<k<<"A"<<l[1]<<"B"<<l[2]<<"C"<<r[1]<<"d"<<r[2]<<endl;
		return ;
	}
	priority_queue<int>q;
	for(int i=1;i<=n;i++)
	{
		now+=p[i].len;
		q.push(-p[i].len);
		if(now>=k)
		{
			while(now+q.top()>=k){
				now+=q.top();
				q.pop();
			}
			ans=min(ans,(int)(2ll*q.size()+p[i].x-(now-k)));
		}
	}
	if(ans==INF)cout<<-1<<endl;
	else cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	for(int i=1;i<=__;i++){
		solve(i);
	}
	// multiset<int>s;
	// s.insert(1);
	// s.insert(2);
	// cout<<*s.begin()<<endl;
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
1
2 4
1 5
3 8

1 3
5 8

11101111
*/