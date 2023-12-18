# G [草莓豪的斐波那契](https://ac.nowcoder.com/acm/contest/72386/G)

出题人:爆哥

考察点:思维

可以通过观察斐波那契序列值是指数形势增长，所以直接模拟即可 

~~~cpp
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
~~~

