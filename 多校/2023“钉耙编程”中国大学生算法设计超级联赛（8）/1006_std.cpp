#pragma comment(linker, "/STACK:1024000000,1024000000")
/*
    Author: elfness@UESTC
*/
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define PB push_back
#define fi first
#define se second
#define MP make_pair
const int oo = 1000000000;
const int P = 1000000007;
const int V = 10000100;

void e_kmp(char *s,char *t,int *has,int *e_has)
{
	int sp,p,mx,tn;
	for(sp=p=mx=0;s[p]>0;p++)
	{
		if(mx==p||p+e_has[p-sp]>=mx )
		{
			for(tn=mx-p;s[mx]==t[tn];tn++)mx++;
			has[sp=p]=mx-p;
			if(mx==p)sp=++mx;
		}
		else has[p]=e_has[p-sp];
	}
}

char t1[V], t2[V], s[V], rs[V], rt[V];
int t1_has[V], t2_has[V], s1_has[V], s2_has[V], rt_has[V], rs_has[V];
int sum[V], _;
int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%s%s%s", t1, t2, s);
        int l1 = strlen(t1);
        int l2 = strlen(t2);
        int n = strlen(s);
        t1[l1] = t2[l2] = -1;
        for (int i = 0; i < l1; ++i) rt[i] = t1[l1 - i -  1]; rt[l1] = -1;
        for (int i = 0; i < n; ++i) rs[i] = s[n - i - 1]; rs[n] = 0;
        t1_has[0] = l1;
        e_kmp(t1+1,t1,t1_has+1,t1_has);
        e_kmp(s,t1,s1_has,t1_has);
        t2_has[0] = l2;
        e_kmp(t2+1,t2,t2_has+1,t2_has);
        e_kmp(s,t2,s2_has,t2_has);
        rt_has[0] = l1;
        e_kmp(rt+1,rt,rt_has+1,rt_has);
        e_kmp(rs,rt,rs_has,rt_has);
        sum[0] = 0;
        for (int i = 0; i < n; ++i) {
            sum[i + 1] = sum[i];
            if (s2_has[i] >= l2) sum[i + 1]++;
        }
        LL ans = 0;
        for (int i = 0; i + l1 + l2 <= n; ++i) {
            int R = s1_has[i] + i;
            int L = i + l1 - rs_has[n - i - l1 - l2];
            if (R >= L) ans += sum[R + 1] - sum[L];
        }
        printf("%lld\n", ans);
    }
    return 0;
}

/*
3
abab ab
abababab
ab a
aaabbaabaa
aba ab
ababaabbabaab

*/
