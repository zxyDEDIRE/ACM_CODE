/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
void solve()
{
	int n;
	cin>>n;
	vector<int>a(n+1,0);
	vector<int>p(n+1,0);
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		a[x]=i;
	}
	for(int i=1;i<=n;i++)
		cin>>p[i];
	int fl;
	for(int i=n;i>=1;i--)
	{
		// cout<<p[i-1]<<" "<<p[i]<<endl;
		// cout<<a[p[i-1]]<<" "<<a[p[i]]<<endl;
		// cout<<endl;
		fl=i;
		if(a[p[i-1]]>a[p[i]])
			break;
	}
	// cout<<"ANS ";
	cout<<fl-1<<endl;
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
8 2 4 7 1 6 5 3
5 6 1 4 8 2 7 3

8 2 4 7 1 6 5 3
5 6 1 4 8 2 3 7
*/