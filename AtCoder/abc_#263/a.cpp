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
const int INF=0x3f3f3f3f;
const int maxn=1e6;
int p[10];
void solve()
{
	for(int i=1;i<=5;i++)
		cin>>p[i];
	sort(p+1,p+1+5);
	int a=1,b=1;
	for(int i=2;i<=4;i++)
		if(p[i]==p[1])a++;
		else if(p[i]==p[5])b++;
	if((a==2&&b==3)||(a==3&&b==2))cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}