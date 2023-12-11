#include <iostream>
#include <vector>
#include <map>
#include <set>
#define endl "\n"
using namespace std;

typedef long long LL;

LL a, x, m;

LL qmi(LL a, LL b)
{
	LL res = 1;
	while(b)
	{
		if(b & 1) res = res * a % m;
		b >>= 1;
		a = a * a % m;
	}
	return res % m;
}

LL sum(LL x)
{
	if(x == 1) return 1;
	
	if(x % 2 == 0) return ((1 + qmi(a, x / 2)) * sum(x / 2) % m) % m;
	else return (1 + a * sum(x - 1)) % m;
}

void solve()
{
	cin >> a >> x >> m;
	cout << sum(x) % m << endl;
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}