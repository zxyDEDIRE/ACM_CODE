/*
	斐波那契数列：
	f_0=1 f_1=1
	f_i=f_i-1+f_i-2 (i>=2)
	一个序列由 从1开始 由 f_i个i 拼接得到
	如 1 2 2 3 3 3 4 4 4 4 4...
	问你序列第n项是什么
	n<=1e18
*/

#include<bits/stdc++.h>
using namespace std;

void solve(){
	long long n;
	cin>>n;
	long long now=0;
	long long a=1,b=1;
	int t=0;
	while(now<n){
		now+=b;
		t++;
		a=a+b;
		swap(a,b);
	}
	cout<<t<<'\n';
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t=1;
	while(t--){
		solve();
	}
	return 0;
}