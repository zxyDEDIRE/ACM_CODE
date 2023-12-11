/*
    嵌套变量重复
    特殊样例 0 1 2 n
    数组越界
    开long long
*/
#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<bitset>
#include<queue>
#include<stack>
#include<map>
#include<set>
using namespace std;
#define endl "\n"
typedef long long ll;
typedef pair<int,int> pii;
const int INF=0x3f3f3f3f;
const int maxn=1e6;
struct ExKmp{
//result: ext[i] = LCP(S[i,lens],T)
//require: nxt[i] = LCP(T[i,lent],T)
//nxt : s  Mode_String
//ext : s  Text_String t Mode_String
	void exkmp(char *s,int lens,char *t,int lent,int *ext,int *nxt)
	{
		ext[0]=0;
		for(int i=1,p0=0,p=0;i<=lens;i++)
		{
			ext[i]=i<=p?min(nxt[i-p0+1],p-i+1):0;
			while(i+ext[i]<=lens&&ext[i]<lent&&s[i+ext[i]]==t[ext[i]+1])ext[i]++;
			if(i+ext[i]-1>=p&&i!=1)p0=i,p=i+ext[i]-1;                  //最右端
		}
	}
	void debug_ext(int *ext,int len){
		for (int i=1;i<=len;i++){
			printf("[debug] ext[%d]=%d\n",i,ext[i]);
		}
	}
	void debug_nxt(int *nxt,int len){
		for (int i=1;i<=len;i++){
			printf("[debug] nxt[%d]=%d\n",i,nxt[i]);
		}
	}
}exKMP;
char s[maxn];
int nxt[maxn];
void solve()
{
	exKMP.exkmp(s,strlen(s+1),s,strlen(s+1),nxt,nxt);
	vector<int>v;
	int n=strlen(s+1);
	for(int i=n;i>=1;i--)
		if(i+nxt[i]-1>=n)cout<<nxt[i]<<" ";
	cout<<endl;


}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    while(cin>>s+1)
        solve();
    return 0;
}
/*
aaagaaag

*/