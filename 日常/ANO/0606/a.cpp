#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
int n;
ll f(int x,int y)
{
	ll res=0;
	ll a=1,b=1;
	for(int i=1;i<=y;i++)
	{
		a=a*(x-i+1);
		b=b*i;
	}
	return a/b;
}
void solve()
{
	cin>>n;
	cout<<n<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int __;cin>>__;
    while(__--)
    solve();
    return 0;
}
/*
3
4

4*3*2
1*2*3

1 2 3 4
A: 123
B: 124
C: 234
D: 134
1
2
3
4

123
1
2
3
*/