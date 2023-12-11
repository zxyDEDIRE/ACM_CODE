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
#define nullptr 0
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=300;
vector<string>ans;
int p[11];
string f(int x)
{
	if(x==0)return "";
	int y=x%10;
	return f(x/10)+(char)(y+'0');
}
bool ok(string str){
	if(str.size()!=9)return false;
	memset(p,0,sizeof(p));
	for(int i=0;i<str.size();i++)
		p[str[i]-'0']++;
	for(int i=1;i<=9;i++)
		if(p[i]!=1)
			return false;
	return true;
}
void solve()
{
	for(int i=1;i<=100000;i++)
	{
		string str="";
		for(int j=1;j<=9;j++)
		{
			str=str+f(i*j);
			if(ok(str)){
				ans.push_back(str);
				break;
			}
		}
	}
	sort(ans.begin(),ans.end());
	for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<endl;
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