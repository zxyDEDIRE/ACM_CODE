#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long ksm(long long a,long long b)
{
	long long res=1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
#define LL long long
LL mul(LL a, LL b, LL p) {
    return (a * b - (LL)(a / (long double)p * b + 1e-3) * p + p) % p;
}
LL power(LL a, LL r, LL p) {
    LL res = 1;
    for (; r; a = mul(a, a, p), r >>= 1)
        if (r & 1)
            res = mul(res, a, p);
    return res;
};
bool miller_rabin(LL n) {
    static LL p[9] = {2, 3, 5, 7, 11, 13, 17, 19, 23};
    if (n == 1)
        return false;
    LL d = n - 1, r = 0;
    for (; not(d & 1); d >>= 1)
        r += 1;
    bool res = true;
    for (int i = 0; i < 9 and p[i] < n and res; i += 1) {
        LL x = power(p[i], d, n);
        if (x == 1 or x == n - 1)
            continue;
        for (int j = 1; j < r; j += 1) {
            x = mul(x, x, n);
            if (x == n - 1)
                break;
        }
        if (x != n - 1)
            res = false;
    }
    return res;
};
vector<LL> pollard_rho(LL n) {
    vector<LL> res;
    function<void(LL)> rho = [&](LL n) {
        if (n == 1)
            return;
        if (miller_rabin(n))
            return res.push_back(n), void();
        LL d = n;
        while (d == n) {
            d = 1;
            for (LL k = 1, y = 0, x = 0, s = 1, c = rand() % n; d == 1;
                 k <<= 1, y = x, s = 1) {
                for (int i = 1; i <= k; i += 1) {
                    x = (mul(x, x, n) + c) % n;
                    s = mul(s, abs(x - y), n);
                    if (not(i % 127) or i == k) {
                        d = __gcd(s, n);
                        if (d != 1)
                            break;
                    }
                }
            }
        }
        rho(d);
        rho(n / d);
    };
    rho(n);
    return res;
}
void solve(long long N)
{
	long long n;
	// cin>>n;
	n=N;
	vector<LL>pr=pollard_rho(n);
	if(pr.size()==0&&n>1) pr.push_back(n);
	long long ans=1;
	sort(pr.begin(),pr.end());
	pr.erase(unique(pr.begin(),pr.end()),pr.end());
	int m=pr.size();
	for(int i=0;i<(1<<m);i++)
	{
		long long res=1;
		int f=1;
		for(int j=0;j<m;j++)
		{
			if((i>>j)&1)
			{
				f=-f;
				res=res*pr[j];
			}
		}
		res=n/res;
		if(f>0) ans=ans*res%mod;
		else ans=ans*ksm(res,mod-2)%mod; 
	}
	cout<<ans<<" ";
}

int main()
{
	freopen("C:\\Users\\tob\\Desktop\\in2.txt","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
;
	int t=1000;
	for(int i=1;i<=t;i++)
		solve(i);
	return 0;
}
