#include<bits/stdc++.h>
using namespace std;
int n,m,cnt;
void solve()
{
	cin>>n;
	cnt=0;
	int A=0,B=0;
	int x,y;
	for(int i=1;i<=n;i++)
		cin>>x,A=max(A,x);
	cin>>m;
	for(int i=1;i<=m;i++)
		cin>>y,B=max(B,y);
	if(A<B)cout<<"Bob\nBob"<<endl;
	else if(A>B)cout<<"Alice\nAlice"<<endl;
	else cout<<"Alice\nBob"<<endl;
}
int main(){
    int __;
    cin>>__;
    while(__--)solve();
    return 0;
}