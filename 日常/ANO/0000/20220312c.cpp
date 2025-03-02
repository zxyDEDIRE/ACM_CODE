#include<iostream>
#include<algorithm>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;
string a,b,c;
int aa[4][30];
int p[105];
int func() {
	for (int i = 0; i < 12; i++) {
		aa[i % 4][a[i] - 'A']++;
	}
	for (int i = 0; i < 8; i++) {
		aa[i % 4][b[i] - 'A']++;
	}
	for (int i = 0; i < 4; i++) {
		aa[i % 4][c[i] - 'A']++;
	}
    char A='B';
    for(int i=1;i<26;i++)cout<<A++<<" ";
    cout<<endl;
    for(int i=0;i<4;i++)
    {
        for(int j=1;j<=26;j++)
            cout<<aa[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
	if (aa[0]['Y' - 'A'] == 1 && aa[0]['R' - 'A'] == 2 && aa[0]['G' - 'A'] == 3 &&
		aa[1]['Y' - 'A'] == 1 && aa[1]['R' - 'A'] == 2 && aa[1]['G' - 'A'] == 3 &&
		aa[2]['Y' - 'A'] == 1 && aa[2]['R' - 'A'] == 2 && aa[2]['G' - 'A'] == 3 &&
		aa[3]['Y' - 'A'] == 1 && aa[3]['R' - 'A'] == 2 && aa[3]['G' - 'A'] == 3	)
		return 1;
		return 0;
}
int main() {
	int n; 
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		p[i] = func();
		memset(aa, 0, 4 * 30 * sizeof(int));
	}
	for (int i = 0; i < n; i++) {
		if (p[i]) cout << "YES"<<endl;
		else cout << "NO"<<endl;
	}
		return 0;

}
/*
2
GYGGGGGGGGGG
RGRRRRRR
YRYY
YGGGRRRRGGGY
YGGGRRRR
YGGG
*/