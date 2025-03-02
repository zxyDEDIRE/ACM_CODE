#include<bits/stdc++.h>
using namespace std;
const int maxn=100;
int n,m;
void solve()
{
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a<c)cout<<"Takahashi"<<endl;
	else if(a==c&&b<=d)cout<<"Takahashi"<<endl;
	else cout<<"Aoki"<<endl;
}
int main(){
	int __;__=1;
//	cin>>__;
	while(__--)solve();
}