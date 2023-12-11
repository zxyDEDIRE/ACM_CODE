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
bool vis[maxn];
int p[maxn];
int n;
void F(){cout<<"First"<<endl;}
void S(){cout<<"Second"<<endl;}
void T(){cout<<"Tie"<<endl;}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i],vis[i]=0;
	int a=0,b=0,c=0;
	for(int i=1;i<=n;i++)
		if(p[i]!=i){
			vis[i]=1,a++;
		}
	for(int i=1;i<=n;i++)
		if(p[i]!=n-i+1){
			b++;
			if(vis[i])c++;
		}
	// cin>>a>>b>>c;
	deque<int>q;
	// cout<<a<<" "<<b<<" "<<c<<endl;
	a-=c;
	b-=c;
	for(int i=1;i<=a;i++)q.push_back(0);
	for(int i=1;i<=c;i++)q.push_back(2);
	for(int i=1;i<=b;i++)q.push_back(1);
	while(q.size()) 
	{
		int x=q.front();q.pop_front();
		if(x==0)a--;
		else if(x==2)c--;
		if(a==0&&c==0&&b!=0)return F();
		else if(!a&&!c&&!b)return T();

		int y=q.back();q.pop_back();
		if(y==1)b--;
		else if(y==2)c--;
		if(b==0&&c==0&&a!=0)return S();
		else if(!a&&!c&&!b)return T();

	}
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
/*
a=2 b=2 c=0 F
aabb
a=3 b=3 c=3 T
ccc
a=5 b=2 c=1 S
aaaacb
a=5 b=3 c=2 T
aaaccb

3 4 5 2 1
1 2 3 4 5
5 4 3 2 1
aaaacbb

2 1 4 3
1 2 3 4
4 3 2 1
a=4 b=4 c=4

*/