#include<bits/stdc++.h>
using namespace std;

#define  ull unsigned long long

const int N = 1e6 + 10, SIZ = 1000000;
const ull mod=212370440130137957ll;
const ull base=131;
const ull prime=233317;
string p[N];
int nxt[N];
int n;
ull Hash1(int id, int x){
	ull val = 0;
	for(int i = 0; i < x; i ++){
		cout << p[id][i];
		val = val * 131 + (p[id][i] - 'a' + 1);
	}
	return val;
}

ull Hash2(int id, int x){
	ull val = 0;
	for(int i = 0; i < x; i ++){
		val=(val*base+(ull)(p[id][i]))%mod+prime;
	}
	return val;
}
 
int main()
{
	p[0] = "av";
	p[1] = "af";
	cout << Hash1(0, 2) << " " << Hash1(1, 2);
	return 0;
}
/*
11
aehtbbdcx
aerian
aiixmu
aqa
ajsxie
af
akeyl
aqmngdq
ayjyxngfn
av
auqsfo

2
af
av
*/


