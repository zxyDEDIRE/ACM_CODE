#include<bits/stdc++.h>
using namespace std;

int main(){
	system("g++ gen.cpp -o gen");
	system("g++ main.cpp -o main");

	for(int i=1;i<=10;i++)
	{
		char tmp[100];
		sprintf(tmp,"./gen %d > ./data/%d.in",i,i);
		system(tmp);
		// system("./gen %d > %d.in",i,i);
	}

	for(int i=1;i<=10;i++)
	{
		char tmp[100];
		memset(tmp,0,sizeof(tmp));
		sprintf(tmp,"./main < ./data/%d.in > ./data/%d.out",i,i);
		system(tmp);
		cout<<tmp<<endl;
		// system("./gen %d > %d.in",i,i);
	}
	// system("./main < 6.in > 6.out");

	return 0;
}