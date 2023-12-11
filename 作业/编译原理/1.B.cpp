#include<bits/stdc++.h>
using namespace std;

// 单词类型枚举
enum TokenType {
	erwer,		//填充
	Keyword,    // 关键字
	Identifier, // 标识符
	Numeric,    // 数字常量
	Operator,    // 运算符
	Delimiter	//界符
};

// Token结构体定义
struct Token {
	TokenType type;
	string value;
};

// 关键字和对应的Token类型
map<string, TokenType> keywordTokens = {
	{"if", Keyword},
	{"else", Keyword},
	{"while", Keyword},
	{"do", Keyword},
	{"switch", Keyword},
	{"case", Keyword},
	{"break", Keyword},
	{"return", Keyword},
	{"int", Keyword},
	{"float", Keyword}
};

// 运算符和对应的Token类型
map<string, TokenType> operatorTokens = {
	{"+", Operator},
	{"-", Operator},
	{"*", Operator},
	{"/", Operator},
	{"%", Operator},
	{"<", Operator},
	{">", Operator},
	{"==", Operator},
	{"!=", Operator},
	{"<=", Operator},
	{">=", Operator},
	{"=", Operator},
};

// 界符和对应的Token类型
map<string, TokenType> delimiterTokens = {
	{"{", Delimiter},
	{"}", Delimiter},
	{"(", Delimiter},
	{")", Delimiter},
	{"\"", Delimiter},
	{"\'", Delimiter},
	{",", Delimiter}
};

//界符判断
stack<char>DelimiterStack;

// 判断字符是否是字母
bool isLetter(char c) {
	return isalpha(c) || c == '_';
}

// 判断字符是否是数字
bool isDigit(char c) {
	return isdigit(c);
}

// 判断字符是否是运算符
bool isOperator(char c) {
	return operatorTokens.count(string() + c) > 0;
}

// 判断界符
bool isDelimiter(char c){
	return delimiterTokens.count(string() + c) > 0;
}





// 词法分析函数
vector<Token> lex(string input) {
	vector<Token> tokens;

	int i = 0;
	while (i < input.size()) {
		// 跳过空格和Tab
		if (input[i] == ' ' || input[i] == '\t') {
			i++;
			continue;
		}
		// 标识符和关键字
		if (isLetter(input[i])) {
			string iden = "";
			while (i < input.size() && (isLetter(input[i]) || isDigit(input[i]))) {
				iden += input[i];
				i++;
			}
			// 判断是否是关键字
			if (keywordTokens.count(iden) > 0) {
				tokens.push_back({keywordTokens[iden], iden});
			} else {
				tokens.push_back({Identifier, iden});
			}
		}
		// 数字常量
		else if (isDigit(input[i])) {
			string num = "";
			while (i < input.size() && isDigit(input[i])) {
				num += input[i];
				i++;
			}
			tokens.push_back({Numeric, num});
		}
		// 运算符
		else if (isOperator(input[i])) {
			// 判断是否是双运算符
			string op = "";
			op += input[i];
			if (i < input.size() - 1 && isOperator(input[i + 1])) {
				op += input[i + 1];
				i += 2;
			} else {
				i++;
			}
			tokens.push_back({operatorTokens[op], op});
		}
		//界符
		else if(isDelimiter(input[i])) {
			string op = string() +input[i];
			if(input[i] == ',') {
				tokens.push_back({delimiterTokens[op], op});
			}
			else if(input[i] == '{' || input[i] == '(') {
				DelimiterStack.push(input[i]);
				tokens.push_back({delimiterTokens[op], op});
			}
			else {
				if(input[i] == '}') {
					if(DelimiterStack.empty() || DelimiterStack.top() != '{')
						cout << "False delimitation" << endl;
					else {
						DelimiterStack.pop();
						tokens.push_back({delimiterTokens[op], op});
					}
				}
				else {
					if(DelimiterStack.empty() || DelimiterStack.top() != '(')
						cout << "False delimitation" << endl;
					else {
						DelimiterStack.pop();
						tokens.push_back({delimiterTokens[op], op});
					}
				}
			}
			i++;
		}
		// 分号判定
		else if(input[i] == ';') {
			i++;
		}
		// 换行符
		else if(input[i] == '\n') {
			i++;
		}
		// 不支持的字符
		else {
			cout << "Invalid character: " << input[i] << endl;
			i++;
		}
	}
	if(DelimiterStack.size()) {
		cout << "False delimitation" << endl;
	}
	return tokens;
}

string input_1(){
	string input,now;
	while(getline(cin,now)){
		if(input=="")input=now;
		else input=input+'\n'+now;
	}
	return input;
}

// 测试程序
int main() {

	string input;


	// input = input_1();
	input = "int main() {\n\tint a = 10;\n\t if (a > 5) {\n\t\t return 1;\n\t } else {\n\t\t return 0;\n\t }\n}";


	vector<Token> tokens = lex(input);

	// 输出Token序列
	for (auto t : tokens) {
		cout << "(" << t.type << ", " << t.value << ")" << endl;
	}


	fclose(stdin);
	return 0;
}