#include<bits/stdc++.h>
using namespace std;

int main(){
	system("g++ gen.cpp -o gen  -O2 -O3");
	system("g++ main.cpp -o main  -O2 -O3");

	for(int i=1;i<=3;i++)
	{
		int n=i*1000;
		int m=n*10;
		int k=i*2;
		int q=n/2;
		char tmp[100];
		sprintf(tmp,"./gen %d %d %d %d > ./data/%d.in",n,m,k,q,i);
		cout<<tmp<<endl;
		system(tmp);
	}
	for(int i=4;i<=20;i++)
	{
		int n=5000;
		int m=n*8;
		int k=7;
		int q=n/2;
		char tmp[100];
		sprintf(tmp,"./gen %d %d %d %d > ./data/%d.in",n,m,k,q,i);
		cout<<tmp<<endl;
		system(tmp);
	}

	for(int i=1;i<=20;i++)
	{
		char tmp[100];
		memset(tmp,0,sizeof(tmp));
		sprintf(tmp,"./main < ./data/%d.in > ./data/%d.out",i,i);
		cout<<tmp<<endl;
		system(tmp);
	}

	return 0;
}
/*
time -f "-----------------\nreal time(seconds): %e \nmem(kbytes): %M" ./main < now.in > now.out
*/