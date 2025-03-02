#include<bits/stdc++.h>
using namespace std;

int main(){
	system("g++ gen.cpp -o gen.exe  -O2 -O3");
	system("g++ main.cpp -o main.exe  -O2 -O3");

	for(int i=1;i<=5;i++)
	{
		int len=i*10000;
		char tmp[100];
		memset(tmp,0,sizeof(tmp));
		sprintf(tmp, "./gen.exe %d > ./data/%d.in",len,i);
		cout<<tmp<<endl;
		system(tmp);
	}

	for(int i=6;i<=20;i++)
	{
		int len=1e6;
		char tmp[100];
		memset(tmp,0,sizeof(tmp));
		sprintf(tmp, "./gen.exe %d > ./data/%d.in",len,i);
		cout<<tmp<<endl;
		system(tmp);
	}

	for(int i=1;i<=20;i++)
	{
		char tmp[100];
		memset(tmp,0,sizeof(tmp));
		sprintf(tmp,"./main.exe < ./data/%d.in > ./data/%d.out",i,i);
		cout<<tmp<<endl;
		system(tmp);
	}

	return 0;
}
/*
time -f "-----------------\nreal time(seconds): %e \nmem(kbytes): %M" ./main < now.in > now.out
*/