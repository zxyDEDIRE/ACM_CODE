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
int p[maxn];
int n;
void solve()
{
	cin>>n;
	if(n==1){
		cout<<1<<endl;
		return ;
	}
	for(int i=1;i<=n;i++)
		cin>>p[i];
	sort(p+1,p+1+n);
	for(int i=2;i<=n;i++)
		p[i]-=p[1];
	int ans=-1;
	for(int i=2;i<=n;i++)
	{
		if(p[i]!=0)
		{
			if(ans==-1)ans=p[i];
			else ans=__gcd(ans,p[i]);
		}
	}
	if(ans==-1)ans=2;

	if(ans>1)cout<<1<<endl;
	else cout<<2<<endl;
}
signed main(){
 // freopen("C:\Users\tob\Desktop\P4391_9.in.txt","r",stdin);
 // freopen("C:\Users\tob\Desktop\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
1 8 15
*/