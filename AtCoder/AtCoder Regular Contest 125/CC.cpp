#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
int n, k;
int a[N];
bool st[N];
int main()
{
  cin >> n >> k;
  for (int i = 1; i <= k; i ++ ) scanf("%d", &a[i]);
  if (k == 1)
  {
    for (int i = n; i >= 1; i -- ) printf("%d ", i);
    return 0;
  }

  int j = 1;
  for (int i = 1; i < k; i ++ )
  {
    printf("%d ", a[i]);
    st[a[i]] = true;
    while (st[j]) j ++;
    if (j < a[i])
    {
      printf("%d ", j);
      st[j] = true;
    }
  }
  for (int i = n; i >= j; i -- )
    if (!st[i]) printf("%d ", i);
  puts("");
  return 0;
}
