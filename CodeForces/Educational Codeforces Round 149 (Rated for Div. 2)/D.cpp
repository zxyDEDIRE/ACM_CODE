/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;

int p[maxn];
string str;
int n;
bool ok(char x)
{
	stack<char>s;
	for(auto i:str)
	{
		if(i==x)
			s.push(x);
		else
		{
			if(s.size()&&s.top()==x)
				s.pop();
			else s.push(x);
		}
	}
	if(s.size()==0)return 1;
	else return 0;
}
void solve()
{
	cin>>n>>str;
	int a=0,b=0;
	
	for(auto i:str)
		if(i=='(')a++;
		else b++;
		
	if(a!=b){
		cout<<-1<<endl;
		return ;
	}
	if(ok('(')||ok(')'))
	{
		cout<<1<<endl;
		for(int i=1;i<=n;i++)
			cout<<1<<" ";
		return ;
	}
	cout<<2<<endl;
	stack<int>s;
	for(int i=0;i<str.size();i++)
	{
		char x=str[i];
		if(x=='(')
			s.push(i);
		else
		{
			if(s.size()&&str[s.top()]=='(')
				s.pop();
			else s.push(i);
		}
	}
	for(int i=0;i<n;i++)
		p[i]=1;
	while(s.size())
	{
		int x=s.top();
		p[x]=2;
		s.pop();
	}
	for(int i=0;i<n;i++)
		cout<<p[i]<<" ";
	cout<<endl;



}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
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
((())))(

*/