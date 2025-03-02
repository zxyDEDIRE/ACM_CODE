/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
// using ull=unsigned long long;
// using ll=long long;
// using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
struct node{
	string a,b;
	int c,d,id;
}p[maxn];
bool cmp(node a,node b)
{
	if(a.d!=b.d)return a.d<b.d;
	else return a.id<b.id;
}
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i].a>>p[i].b>>p[i].c>>p[i].d,p[i].id=i;
	sort(p+1,p+1+n,cmp);
	for(int i=1;i<=n;i++)
		cout<<p[i].a<<" "<<p[i].b<<" "<<p[i].c<<" "<<p[i].d<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);

		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
3
Alice female 18 98
Bob male 19 90
Miller male 17 92
*/