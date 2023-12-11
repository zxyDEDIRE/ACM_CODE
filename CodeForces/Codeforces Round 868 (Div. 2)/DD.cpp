/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
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
char s[maxn];
int n;
void solve()
{
	set<string>S;
	cin>>s+1;
	n=strlen(s+1);
	
	for(int i=1;i<=n;i++)
	{
		S.insert(string(1,s[i]));
		for(int j=1;i-j>=1&&i+j<=n;j++)
		{
			if(s[i-j]!=s[i+j])break;
			string str;
			for(int k=i-j;k<=i+j;k++)
				str=str+s[k];
			S.insert(str);
		}
		int l=i,r=i+1;
		while(l>=1&&r<=n&&s[l]==s[r])
		{
			if(s[l]!=s[r])break;
			string str="";
			for(int k=l;k<=r;k++)
				str=str+s[k];
			S.insert(str);
			l--,r++;
		}
	}
	for(auto i:S)
		cout<<i<<" "<<i.size()<<endl;
	cout<<S.size()<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
8 8
aaaaaaaa
8 8
aaaaaaab
8 
aaaaabba
aaaabbbb
aaaacbbc
abababab
abbabbab


abcabcabca 3
abcabcaabc 4
abcabcabca 5
abcabcaaaa 6
aaaaabcaaa 7
abcabaaaaa 8
aaaaaaabca 9

给你 n,k
然后长度为k的限制条件
x1 x2 ... xk (2 <= x1 < x2 <...< xk = n)
y1 y2 ... yk (3 <= y1 < y2 <...< yk <= min(1e9,(n+1)*n/2))

定义f(s,len)
s=为你需要构造的长为n的字符串
len是int 意思是只取s长为len的前缀

f(s,len)=s中唯一回文子字符串的个数
比如 s=abcbbc f(s,6)=6(a,b,c,bb,bcb,cbbc)

限制条件解释：
f(s,x1)=y1,
f(s,x2)=y2,
...
f(s,xk)=yk.

2<=n<=2e5 1<=k<=20
*/  