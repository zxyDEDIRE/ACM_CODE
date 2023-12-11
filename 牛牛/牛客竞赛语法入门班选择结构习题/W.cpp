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
const int maxn=1e6;
string str;
void solve()
{
	cin>>str;
	int cnt=0;
	int ans=0;
	for(int i=0;i<str.size()-1;i++)
	{
		if(str[i]>='0'&&str[i]<='9')
		{
			cnt++;
			ans+=(str[i]-'0')*cnt;
		}
	}
	ans%=11;
	char ch=str.back();
	if(ans==10&&ch=='X')cout<<"Right"<<endl;
	else if(ans==10)
	{
		for(int i=0;i<str.size()-1;i++)
			cout<<str[i];
		cout<<"X";
	}
	if(ans==10)return ;

	int x=ch-'0';
	if(x!=ans)
	{
		for(int i=0;i<str.size()-1;i++)
			cout<<str[i];
		cout<<ans;
	}
	else cout<<"Right"<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}