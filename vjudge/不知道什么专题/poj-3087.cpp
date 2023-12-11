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
string a,b,t;
int n;
string f(string a)
{
	string s=string(n*2,'a');
	for(int i=0;i<n;i++)
	{
		s[i*2]=a[i+n];
		s[i*2+1]=a[i];
	}
	return s;
}
void solve()
{
	cin>>n>>a>>b>>t;
	a=a+b;
	for(int i=1;i<=n*2;i++)
	{
		a=f(a);
		if(a==t){
			cout<<i<<endl;
			return ;
		}
	}
	cout<<-1<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int __;cin>>__;
    for(int i=1;i<=__;i++){
    	cout<<i<<" ";
        solve();
    }
    return 0;
}
/*
haha
ahah

haah
haah
hhaaaahh

*/