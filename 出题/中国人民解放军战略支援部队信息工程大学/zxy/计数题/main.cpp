#include<bits/stdc++.h>
using namespace std;

int main(){
	system("g++ gen.cpp -o gen.exe");
	system("g++ std.cpp -o std.exe");

	for(int i=1;i<=50;i++)
	{
		char tmp[100];
		int n;
		if(i<=5)n=10;
		else if(i<=10)n=100;
		else if(i<=15)n=1000;
		else if(i<=20)n=10000;
		else if(i<=30)n=100000;
		else n=1000000;
		sprintf(tmp,"./gen.exe %d > ./data/%d.in",n,i);
		cout<<tmp<<endl;
		system(tmp);
	}

	for(int i=1;i<=50;i++)
	{
		char tmp[100];
		sprintf(tmp,"./std.exe < ./data/%d.in > ./data/%d.out",i,i);
		cout<<tmp<<endl;
		system(tmp);
	}
	return 0;
}
