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
const int maxn=1e6+100;
int p[maxn];
int a[maxn];
int cnt[20];
set<int>st;
int n,k,mi=1e9;
string doit(int fl)
{
	int flag=-1;
	int x=cnt[fl];
	for(int i=1;i<=n;i++)
		a[i]=p[i];
	cnt[10]=101002;
	for(int i=1;i<=10;i++)
	{
		int y=0;
		if(fl-i>=0)y+=cnt[fl-i];
		if(fl+i<=9)y+=cnt[fl+i];
		if(x+y>k){
			flag=i-1;
			break;
		}
		else x+=y;
	}
	if(flag==-1)flag=9;
	int need=max(0ll,k-x);
	for(int i=1;i<=n;i++)
		if(abs(a[i]-fl)<=flag)a[i]=fl;
	for(int i=1;i<=n;i++)
		if(a[i]-fl==flag+1&&need){
			a[i]=fl;
			need--;
		}
	for(int i=n;i>=1;i--)
		if(fl-a[i]==flag+1&&need){
			a[i]=fl;
			need--;
		}
	string ans="";
	for(int i=1;i<=n;i++)
		ans+=(char)('0'+a[i]);
	return ans;
}
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		char ch;cin>>ch;
		p[i]=ch-'0';
		cnt[p[i]]++;
	}
	int fl=0;
	for(int i=0;i<=9;i++)
	{
		int ans=0;
		int tot=cnt[i];
		for(int j=1;j<=9;j++)
		{
			int x=0;
			if(i-j>=0)x+=cnt[i-j];
			if(i+j<=9)x+=cnt[i+j];
			if(tot+x>=k)
			{
				if(tot<k)
				ans+=(k-tot)*j;
				break;
			}
			else{
				tot+=x;
				ans+=x*j;
			}
		}
		if(ans<mi){
			st.clear();
			st.insert(i);
			mi=ans;
		}
		else if(ans==mi){
			st.insert(i);
		}
	}
	cout<<mi<<endl;
	string ans=doit(*st.begin());
	st.erase(*st.begin());
	for(auto i:st)
		ans=min(ans,doit(i));
	cout<<ans<<endl;

}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}