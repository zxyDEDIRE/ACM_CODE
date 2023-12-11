#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
int a[MAXN], b[MAXN], q[MAXN], front, rear;
long long ans;
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        b[i] = b[i-1] + a[i] - a[n-i+1];
    }
    front = rear = 0;
    for (int j = 1; j <= n; j++) {
        while (front < rear && b[q[rear-1]] >= b[j]) rear--;
        q[rear++] = j;
        while (front < rear && b[q[front]] < b[j-1]) front++;
        ans += b[q[front]] - b[j-1];
    }
    printf("%lld\n", ans);
    return 0;
}