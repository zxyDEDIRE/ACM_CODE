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
stack<char>s;
char ch[maxn];
int n;
bool check(char a,char b)
{
	if(a=='b'&&b=='q')return 1;
	if(a=='d'&&b=='p')return 1;
	if(a=='p'&&b=='d')return 1;
	if(a=='q'&&b=='b')return 1;
	if(a=='n'&&b=='u')return 1;
	if(a=='u'&&b=='n')return 1;
	if(a=='o'&&a==b)return 1;
	if(a=='s'&&a==b)return 1;
	if(a=='x'&&a==b)return 1;
	if(a=='z'&&a==b)return 1;
	if(a=='#'&&a==b)return 1;
	return 0;
}
bool check_1(char a)
{
	char b=a;
	if(a=='o'&&a==b)return 1;
	if(a=='s'&&a==b)return 1;
	if(a=='x'&&a==b)return 1;
	if(a=='z'&&a==b)return 1;
	if(a=='#'&&a==b)return 1;
	return 0;
}
bool check_2(char a)
{
	if(a=='b')return 1;
	if(a=='d')return 1;
	if(a=='p')return 1;
	if(a=='q')return 1;
	if(a=='n')return 1;
	if(a=='u')return 1;
	return 0;
}
void solve()
{
	cin>>ch+1;
	n=strlen(ch+1);
	stack<char>s;
	for(int i=1;i<=n;i++)
	{
		if(check_1(ch[i]))
			s.push(ch[i]);
		else if(check_2(ch[i]))
		{

		}
		else {
			cout<<"No"<<endl;
			return ;
		}
	}
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
o
x
z
s
un
dp
pd
*/