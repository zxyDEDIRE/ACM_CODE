#include<bits/stdc++.h>
using namespace std;


void solve()
{
	long double n;
	cin>>n;
	long double res=1;
	long double fm=1;
	for(int i=1;i<=n;i++){
		res=res*i*i/n;
	}
	cout<<fixed<<setprecision(20)<<res<<'\n';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	solve();
	return 0;
}
/*
104147662762941310876516258165213199001976832.00000000000000000000
104147662762941310907813025277584020848013430.758061352192
*/