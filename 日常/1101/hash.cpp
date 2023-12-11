#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+100;


unsigned long long Seed = 146527;
unsigned long long Mod = 998244353;

void solve()
{

	char s[100];
	int n;

	n=strlen(s);

	unsigned long long Hash=0;
	for(int i=0;i<n;i++)
		Hash = (Hash * Seed%Mod +s[i])%Mod;



}
signed main(){
		solve();
	return 0;
}