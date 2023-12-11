/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define p(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
int p[maxn];
int n;
void solve()
{
	cin>>n;
	int a=0,b=0,cnt=0;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	for(int i=1;i<=n;i++)
	{
		if(p[i]==i)continue;
		if(p[p[i]]==i)a++;
		else b++;
		cnt++;
	}
	int mi=INF;

	for(int i=1;i<n;i++)
	{
		int x=i;
		int y=i+1;
		int aa=a,bb=b;
		int ans;
		if(p[x]==y&&p[y]==x)
		{
			aa-=2;
			if(bb<=1)ans=aa/2+bb;
			else ans=mi,aa/2+bb-1;
		}
		else
		{
			// cout<<aa<<" "<<bb<<endl;
			if(p[x]==x)bb++;
			else if(p[p[x]]==x)aa-=2,bb+=2;
			if(p[y]==y)bb++;
			else if(p[p[y]]==y)aa-=2,bb+=2;

			if(p[p[x]]==y)aa+=2,bb-=2;
			if(p[p[y]]==x)aa+=2,bb-=2;

			if(p[x]==y)bb--;
			if(p[y]==x)bb--;



			// cout<<aa<<" "<<bb<<endl;

			if(bb<=1)ans=aa/2+bb;
			else ans=aa/2+bb-1;
		}
		// cout<<"ans: "<<ans<<endl;
		// cout<<endl;
		mi=min(mi,ans);
	}
	cout<<"mi "<<mi<<endl;
	// cout<<mi<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\a.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\b.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
 // fclose(stdin);
 // fclose(stdout);
	return 0;
}
/*
1 4 3 2

*/