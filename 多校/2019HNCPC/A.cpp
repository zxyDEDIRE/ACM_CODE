#include <iostream>
using namespace std;
const int N = 15;
char a[N][N];
int sum = 0;
bool check(int x1, int y1, int x2, int y2){
	int res = 0;
	for(int i = x1; i <= x2; i ++){
		for(int j = y1; j <= y2; j ++){
			res += (a[i][j] == '1');
		}
	}
	return res == sum;
}
int n, m;
void solve(){
	for(int i = 1; i <= n; i ++){
			scanf("%s",a[i] + 1);
		}
		sum = 0;
		for(int i = 1; i <= n; i ++){
			for(int j = 1; j <= m; j ++){
				if(a[i][j] == '1') sum ++;
			}
		}

		for(int i = 1; i <= n; i ++){
			for(int j = 1; j <= m; j ++){
				for(int k = i; k <= n; k ++){
					for(int f = j; f <= m; f ++){
						if((k - i + 1) * (f - j + 1) == sum){
							if(check(i,j,k,f)){
								puts("Yes");
								return ;
							}
						}
					}
				}
			}
		}
		puts("No");
}
int main(){
	while(cin >> n >> m){
		solve();
	}
	
	return 0;
}