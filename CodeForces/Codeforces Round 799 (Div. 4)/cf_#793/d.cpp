#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6;
int p[maxn];
int n,m;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	cin>>m;
	int T=1;
	for(int i=1;i<=m;i++){
		int x;
		cin>>x;
		T=T+x;
		if(T>n)T-=n;
	}
	cout<<p[T]<<endl;
}
int main(){
    int __;
    cin>>__;
    while(__--)solve();
    return 0;
}
/*
4
2 3 1 4
2
3 1
*/