#include<bits/stdc++.h>
using namespace std;


const int maxn=1e5;
int p[maxn];
int n;

// 假设数组的大小是 n + 1，冒泡排序从数组下标 1 开始
void bubble_sort(int *a, int n) {
	bool flag = true;
	while (flag) {
		flag = false;
		for (int i = 1; i < n; ++i) {
			if (a[i] > a[i + 1]) {
				flag = true;
				int t = a[i];
				a[i] = a[i + 1];
				a[i + 1] = t;
			}
		}
	}
}
signed main(){
	return 0;
}