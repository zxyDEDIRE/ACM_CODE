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
int Len(int x){
	int cnt=0;
	while(x)cnt++,x/=2;return cnt;
}
string S(int x)
{
	string str="";
	while(x)
	{
		if(x&1)str+='1';
		else str+='0';
		x/=2;
	}
	reverse(str.begin(),str.end());
	return str;
}
string S1(string s)
{
	string str=s;
	for(int i=s.size()-1;i>=0;i--)
		str+=s[i];
	return str;
}
string S2(string s)
{
	string str=s;
	for(int i=s.size()-2;i>=0;i--)
		str+=s[i];
	return str;
}
void ok(string str,int x)
{
	int y=0;
	for(int i=0;i<str.size();i++)
		y=y*2+((str[i]=='1')?1:0);
	if(y<=x)v.push_back(y);
}
int doit()
{
	int x=(1ll<<31)-1;
	int m=Len(x);
	int n=(m+1)/2;
	int ans=0;
	for(int i=1;i<(1<<n);i++)
	{
		string str=S(i);
		ok(S1(str),x);
		ok(S2(str),x);
	}
	return ans;
}
void solve()
{
	int n,m;
	cin>>n>>m;
	int fl1=lower_bound(v.begin(),v.end(),n-1)-v.begin();
	if(v[fl1]>n-1)fl1--;
	int fl2=lower_bound(v.begin(),v.end(),m)-v.begin();
	if(v[fl2]>m)fl2--;
	cout<<fl2-fl1<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	doit();
	sort(v.begin(),v.end());
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
1 2 3 4 5 6
1234
1235
1236
1245
1246
1345
1346
1356
1456
2345
2346
2356
2456
3456

*/