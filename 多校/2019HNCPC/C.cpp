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
const int mod=1e9+7;
const int maxn=1e6+100;
struct ExKmp{
	void exkmp(int *s,int lens,int *t,int lent,int *ext,int *nxt){
		ext[0]=0;
		for(int i=1,p0=0,p=0;i<=lens;i++){
			ext[i]=i<=p?min(nxt[i-p0+1],p-i+1):0;
			while(i+ext[i]<=lens&&ext[i]<lent&&s[i+ext[i]]==t[ext[i]+1])ext[i]++;
			if(i+ext[i]-1>=p&&i!=1)p0=i,p=i+ext[i]-1;                  //最右端
		}
	}
}exKMP;
int nxt[maxn];
int T[maxn];
int h[maxn];
int s[maxn];
int n,m;
void solve()
{
	// cin>>n>>m;
	for(int i=1;i<=m;i++)
		h[i]=0;
	for(int i=1;i<=n;i++)
		cin>>s[n-i+1];
	exKMP.exkmp(s,n,s,n,nxt,nxt);
	for(int i=2;i<=n;i++)
	{
		// int len=max(1,nxt[i]);
		h[s[i-1]]=max(h[s[i-1]],nxt[i]+1);
	}
	h[s[n]]=max(h[s[n]],1);
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		int now=n-h[i]+1;
		now=(now*T[i])%mod;
		ans=(ans^now);
	}
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
	T[0]=1;
	for(int i=1;i<=1e6+10;i++)
		T[i]=(T[i-1]*3)%mod;
	while(cin>>n>>m)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
2 1
*/
/*
2 1 1
https://ac.nowcoder.com/acm/contest/view-submission?submissionId=41328843
https://blog.csdn.net/tianyizhicheng/article/details/101901028
https://littlefall.blog.csdn.net/article/details/101847725?spm=1001.2101.3001.6650.1&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7ERate-1-101847725-blog-101901028.pc_relevant_multi_platform_whitelistv3&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7ERate-1-101847725-blog-101901028.pc_relevant_multi_platform_whitelistv3&utm_relevant_index=2
*/