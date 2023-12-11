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
string str;
int n;
void solve()
{
	cin>>n>>str;
	int x=0;
	reverse(str.begin(),str.end());
	vector<char>v;
	for(int i=0;i<n;i++)
	{
		if(str[i]=='0')
		{
			int x=(str[i+1]-'0')+(str[i+2]-'0')*10;
			i=i+2;
			v.push_back((char)(x+'a'-1));
		}
		else
		{
			int x=(str[i]-'0');
			v.push_back((char)(x+'a'-1));
		}
	}
	reverse(v.begin(),v.end());
	for(auto i:v)
		cout<<i;cout<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
*/