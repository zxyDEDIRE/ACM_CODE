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
using ll=long long;
using pii=pair<int,int>;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
bool check(int k)
{
	long double p=1.0*3*k/2;
	long double s=p*(p-(k-1))*(p-k)*(p-(k+1));
	int x=s;
	int y=sqrt(s);
	if(x==y*y)return  1;
	else return 0;
}
void solve()
{
	// string str;
	// cin>>str;
	// int n=str.size();
	// if(n>5)cout<<-1<<endl;
	// else
	// {
	// 	int x=0;
	// 	for(int i=0;i<str.size();i++)
	// 		x=x*10+(str[i]-'0');
	// 	if(x<=4)cout<<4<<endl;
	// 	else if(x<=14)cout<<14<<endl;
	// 	else if(x<=52)cout<<52<<endl;
	// 	else if(x<=194)cout<<194<<endl;
	// 	else if(x<=724)cout<<724<<endl;
	// 	else if(x<=2702)cout<<2702<<endl;
	// 	else if(x<=10084)cout<<10084<<endl;
	// 	else if(x<=37634)cout<<37634<<endl;
	// 	else cout<<-1<<endl;
	// }
	for(int i=100;i<=1000000;i++)
		if(check(i)){
			cout<<i<<endl;
		}
}
signed main(){
 // freopen("C:\Users\tob\Desktop\P4391_9.in.txt","r",stdin);
 // freopen("C:\Users\tob\Desktop\P4391_9.out.txt","w",stdout);
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
4
14
52
194

3 4 5
x*x+(x-1)*(x-1)=(x+1)*(x+1)
2x^2-2x=x^2+2x;
x^2=4x
x=4
*/