#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
string p[10][6];

int main()
{
	p[0][1]="XXX";p[0][2]="X.X";p[0][3]="X.X";p[0][4]="X.X";p[0][5]="XXX";
	p[1][1]="..X";p[1][2]="..X";p[1][3]="..X";p[1][4]="..X";p[1][5]="..X";
	p[2][1]="XXX";p[2][2]="..X";p[2][3]="XXX";p[2][4]="X..";p[2][5]="XXX";
	p[3][1]="XXX";p[3][2]="..X";p[3][3]="XXX";p[3][4]="..X";p[3][5]="XXX";
	p[4][1]="X.X";p[4][2]="X.X";p[4][3]="XXX";p[4][4]="..X";p[4][5]="..X";
	p[5][1]="XXX";p[5][2]="X..";p[5][3]="XXX";p[5][4]="..X";p[5][5]="XXX";
	p[6][1]="XXX";p[6][2]="X..";p[6][3]="XXX";p[6][4]="X.X";p[6][5]="XXX";
	p[7][1]="XXX";p[7][2]="..X";p[7][3]="..X";p[7][4]="..X";p[7][5]="..X";
	p[8][1]="XXX";p[8][2]="X.X";p[8][3]="XXX";p[8][4]="X.X";p[8][5]="XXX";
	p[9][1]="XXX";p[9][2]="X.X";p[9][3]="XXX";p[9][4]="..X";p[9][5]="XXX";

	string str;
	int n;
	cin>>n;
	cin>>str;
	for(int i=1;i<=5;i++)
	{
		for(int j=0;j<str.size();j++)
		{
			int x=str[j]-'0';
			cout<<p[x][i];
			if(j!=n-1)cout<<".";
		}
		cout<<endl;
	}
}
/*
..X...X.X.X.XXX...X.X.X
..X...X.X.X.X.....X.X.X
..X...X.XXX.XXX...X.XXX
..X...X...X...X...X...X
..X...X...X.XXX...X...X

*/