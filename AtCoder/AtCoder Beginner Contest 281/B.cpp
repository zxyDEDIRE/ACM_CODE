/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
void NO(){
	cout<<"No"<<endl;
}
void solve()
{
	string str;
	cin>>str;
	if(str.size()!=8)return NO();
	char a=str[0];
	if(a>'Z'||a<'A')return NO();
	a=str[7];
	if(a>'Z'||a<'A')return NO();
	int x=0;
	for(int i=1;i<str.size()-1;i++){
		if(str[i]<'0'||str[i]>'9')return NO();
		x=x*10+(str[i]-'0');
	}
	if(x>=100000&&x<=999999)
		cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}
//100000
//999999
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