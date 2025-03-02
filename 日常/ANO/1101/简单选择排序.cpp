#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+100;

void selection_sort(int* a, int n) {
	for (int i = 1; i < n; ++i) {
		int ith = i;
		for (int j = i + 1; j <= n; ++j) {
			if (a[j] < a[ith]) {
				ith = j;
			}
		}
		std::swap(a[i], a[ith]);
	}
}

signed main(){
	return 0;
}