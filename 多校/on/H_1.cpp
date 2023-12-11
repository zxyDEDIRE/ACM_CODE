#include<bits/stdc++.h>
using namespace std;

pair<int, int> p[50];
void solve()
{
	int k, r;
	cin >> k >> r;
	int len = 512 / r;
	if(512 % r != 0) len ++;

	int s = 256 - len;
	int t = s / (k - 1);

	int x = len + (r - 1) * t, f = 0;
	if(x <= 128){
		f = 128 - x;
		if(f > r - 1){
			cout << "-1";
			return ;
		}
	}

	printf("len = %d t = %d f = %d\n", len, t, f);
	p[1] = {1, len};
	for(int i = 1; i <= k; i += r){
		for(int j = i; j <= i + r - 1; j ++){
			if(j == 1) continue ;
			if(i + r - 1 - j + 1 <= f){
				p[j].second = p[j - 1].second + t + 1;
			}
			else p[j].second = p[j - 1].second + t;
			p[j].first = p[j].second - len + 1;
		}
	}

	for(int i = 1; i <= k; i ++){
		int l = i, ri = i + r - 1;
		if(ri > k) break;
		if(p[ri].second - p[l].first + 1 < 128){
			cout << "-1";
			return ;
		}
	}
	for(int i = 1; i <= k; i ++){
		for(int j = 1; j <= 256; j ++){
			if(p[i].first <= j && j <= p[i].second) cout << "1";
			else cout << "0";
		}
		if(i != k) cout << "\n";
	}
}

int main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}