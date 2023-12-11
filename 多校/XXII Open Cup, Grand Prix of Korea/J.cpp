#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 100;
const ll inf = 1e18;
pair<int,int>p[N];
map<int,int>mp;
map<int, bool>res, ct;

void get_p(int x){
	for(int i = 1; i * i <= x; i ++){
		if(x % i == 0){
			res[i] = 1;
			if(x / i != i) res[x / i] = 1;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++){
		cin >> p[i].first >> p[i].second;
		mp[p[i].first] = p[i].second;
	}


	for(int i = 1; i <= n; i ++){
		for(int j = i + 1; j <= n; j ++){
			if(p[i].second != p[j].second){
				get_p(abs(p[i].first - p[j].first));
			}
		}
	}
	
	ll min_t = inf;
	for(int i = 1; i <= n; i ++){
		for(int j = i + 1; j <= n; j ++){
			if(p[i].second == p[j].second && !res.count(abs(p[i].first - p[j].first))){
				min_t = min(min_t, 1ll * abs(p[i].first - p[j].first));
			}
		}
	}

	if(min_t == inf){
		cout << "0 0";
		return 0;
	}

	// printf("mint = %lld\n",min_t);
	for(int i = 1; i < n; i ++){
		// bool flag = 0;
		for(int j = 1; j <= n; j ++){
			int idx = p[j].first, flag = 1;
			for(int k = idx; k <= idx + i - 1; k ++){
				if(!mp.count(k + min_t)){
					flag = 0;
					break;
				}
			}
			if(flag) res[i + 1] = 1;
		}
	}

	ll sum = 0;
	for(auto it : res){
		sum += it.first;
	}
	cout << res.size() << " " << sum;
	return 0;
}

/*
7
1 1
2 1
3 1
7 1
8 1
9 1
10 1

4
1 1
2 1
10 1
11 1


1 2 3 4 5      6 7 8 9 10
1 1 1 1 1      1 1 1 1 1      
*/