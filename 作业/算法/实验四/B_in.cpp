// 生成树

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;
int a[100000];

int random(int n){
	return (long long) rand() * rand() % n;
}

int main()
{
	freopen("C:\\Users\\tob\\Desktop\\in_2.txt","w",stdout);

	srand((unsigned)time(0));
	int n, m;
	// scanf("%d", &n);
	n=2000;m=3500;
	printf("%d %d\n",n,m);
	for (int i = 2; i <= m; i ++ ){
		int fa = random(i - 1) + 1;
		int val = random(1000000) + 1;
		printf("%d %d %d\n", fa, i, val);
	}

	fclose(stdout);
}