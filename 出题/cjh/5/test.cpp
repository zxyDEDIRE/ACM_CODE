#include<bits/stdc++.h>
using namespace std;

int main(){
	system("g++ gen.cpp -o gen");
	system("g++ main.cpp -o main");

	for(int i=1;i<=20;i++)
	{
		char tmp[100];
		sprintf(tmp,"./gen  > ./data/%d.in",i);
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