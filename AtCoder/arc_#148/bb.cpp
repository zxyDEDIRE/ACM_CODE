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
string str,s,mi;
int n;
void f(int l,int r)
{
	s=str;
	for(int i=l,j=r;i<=r;i++,j--)
	{
		if(str[j]=='p')
			s[i]='d';
		else s[i]='p';
	}
}
void solve()
{
	cin>>n>>str;
	mi=str;
	int fl=0;
	for(int i=0;i<str.size();i++)
		if(str[i]=='p'){
			fl=i;
			break;
		}
	for(int j=fl;j<str.size();j++)
	{
		f(fl,j);
		mi=min(mi,s);
	}
	cout<<mi<<endl;
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
ddpdpdppddp
ddddpdpdddp
dddppddpdpd
123456789
123987654
123654789
*/