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
vector<int>v;
string s,t,str;
int n,num=0;
void solve()
{
	cin>>n>>s>>t;
	for(int i=0;i<n;i++)
		if(s[i]!=t[i])
			v.push_back(i),num++;
	if(num&1){
		cout<<-1<<endl;
		return ;
	}
	int a=0,b=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]==t[i])str+='0';
		else
		{
			if(num==a)str+=s[i],a--;
			else if(num==b)str+=t[i],b--;
			else if(s[i]=='0')str+=s[i],b++;
			else if(t[i]=='0')str+=t[i],a++;
			num--;
			if(a&&b)a--,b--;
		}
	}
	cout<<str<<endl;
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
/*
0000
1111

4
1101
0010

0001
*/