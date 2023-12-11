#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e6;
string str;
stack<char>s;
char p[maxn];
int cnt,n;
int a,b;
void doit()
{
	if(cnt==2&&p[1]=='('&&p[2]==')'){
		a++;cnt=0;
		return ;
	}	
	for(int i=1;i<=cnt/2;i++)
		if(p[i]!=p[cnt-i+1])return ;
	cnt=0;
	a++;	
}
void solve()
{
	cin>>n;
	cin>>str;
	a=b=cnt=0;
	
}
signed main(){
	int __;cin>>__;
	while(__--)solve(); 
}
/*
8  6
5 12
*/
