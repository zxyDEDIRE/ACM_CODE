#include<bits/stdc++.h>
using namespace std;

int main(){
	system("g++ gen.cpp -o gen.exe");
	system("g++ FUCK_std.cpp -o std.exe");

	// for(int i=1;i<=50;i++)
	// {
	// 	char tmp[100];
	// 	int n,q,r;

	// 	if(i<=5)n=10,r=10,q=10;
	// 	else if(i<=10)n=100,r=100,q=200;
	// 	else n=1000,r=10000,q=2000;

	// 	sprintf(tmp,"./gen.exe %d %d %d > ./data/%d.in",n,q,r,i);
	// 	cout<<tmp<<endl;
	// 	system(tmp);
	// }

	for(int i=1;i<=50;i++)
	{
		char tmp[100];
		sprintf(tmp,"./std.exe < ./data/%d.in > ./data/%d.out",i,i);
		cout<<tmp<<endl;
		system(tmp);
	}
	return 0;
}
/*
00000
*/
