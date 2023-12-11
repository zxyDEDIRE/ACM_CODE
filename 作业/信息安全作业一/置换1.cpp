#include <iostream>
#include <string>
#include <map>
using namespace std;
// 加密函数
string encrypt(string message, map<char, char> cipher) {
	string encrypted;
	// 遍历明文中的每个字符，用密文中对应的字符替换它
	for (char c : message) {
		if (c == ' ') {  // 保留空格不加密
			encrypted += ' ';
		} else {
			encrypted += cipher[c];
		}
	}
	return encrypted;
}
// 解密函数
string decrypt(string message, map<char, char> cipher) {
	string decrypted;
	// 遍历密文中的每个字符，用明文中对应的字符替换它
	for (char c : message) {
		if (c == ' ') {  // 保留空格不解密
			decrypted += ' ';
		} else {
			for (auto it : cipher) {
				if (it.second == c) {
					decrypted += it.first;
					break;
				}
			}
		}
	}
	return decrypted;
}
void init(string &alphabet,string &key)
{
	for(char i=(char)(32);i<='~';i++)
		alphabet=alphabet+i;
	cout<<alphabet<<endl;
}
int main() {
	// 定义明文和密文的字符集
	string alphabet = "abcdefghijklmnopqrstuvwxyz";
	string key = "qwertyuiopasdfghjklzxcvbnm";
	init(alphabet,key);
	return 0;
	// 定义置换表，将明文中的字符替换为密文中的字符
	map<char, char> cipher;
	for (int i = 0; i < 26; i++) {
		cipher[alphabet[i]] = key[i];
	}
	// 输入明文
	std::string message;
	cout << "Message: \n";
	getline(cin, message);
	// 加密明文
	string encrypted = encrypt(message, cipher);
	cout << "ciphertext: \n" << encrypted << endl;
	// 解密密文
	string decrypted = decrypt(encrypted, cipher);
	cout << "Message: \n" << decrypted << endl;
	return 0;
}