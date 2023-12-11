#include <iostream>
#include <stack>
#include <string>
#include <map>

using namespace std;

struct LR1Item
{
    string left;     // 产生式左部
    string right;    // 产生式右部
    string lookahead;    // 向前看符号
};

// 定义产生式集合
LR1Item productions[] = {
    { "E", "S", "#" },
    { "S", "B B", "#" },
    { "B", "a B", "a" },
    { "B", "b", "b" }
};
int prodCount = sizeof(productions) / sizeof(productions[0]);

// 定义动作集合
string actions[] = {
    "shift",    // 移进
    "reduce",   // 规约
    "accept"    // 接受
};
int actionCount = sizeof(actions) / sizeof(actions[0]);

// 定义状态转移表
int GOTO[][3] = {
    { 1, 0, 0 },
    { 0, 2, 0 },
    { 0, 0, 0 }
};

// 定义规约表
int REDUCE[][2] = {
    { 2, 1 },
    { 4, 2 },
    { 3, 1 },
    { 3, 1 }
};
int reduceCount = sizeof(REDUCE) / sizeof(REDUCE[0]);

// 定义符号集合
string symbols[] = {
    "a",
    "b",
    "S",
    "B",
    "#"
};
int symbolCount = sizeof(symbols) / sizeof(symbols[0]);

// 将LR1Item转换为字符串形式
string itemToString(LR1Item item)
{
    return item.left + " -> " + item.right + ", " + item.lookahead;
}

int main()
{
    // 初始化分析表
    map<pair<int, string>, int> ACTION;
    map<pair<int, string>, int> GOTO;
    for (int i = 0; i < prodCount; i++)
    {
        LR1Item item = productions[i];
        int fromState = i;
        string lookahead = item.lookahead;

        if (item.right == "#")
        {
            ACTION[make_pair(fromState, lookahead)] = 2;    // 接受
        }
        else if (lookahead == "a" || lookahead == "b")
        {
            int toState = GOTO[fromState][symbolCount - 3]; // 符号对应的列索引为(symbolCount - 3)
            ACTION[make_pair(fromState, lookahead)] = 0;    // 移进
            GOTO[make_pair(fromState, item.right.substr(0, 1))] = toState;
        }
        else
        {
            int ruleIndex = 0;
            for (int j = 0; j < prodCount; j++)
            {
                if (item.right == productions[j].right)
                {
                    ruleIndex = j;
                    break;
                }
            }
            ACTION[make_pair(fromState, lookahead)] = 1;    // 规约
            GOTO[make_pair(fromState, item.left)] = REDUCE[ruleIndex][1];
        }
    }

    // 输入符号串
    cout << "输入以#结束的符号串（只包含a、b、空格和#）：";
    string input;
    getline(cin, input);
    input += "#";   // 将输入串以#结尾，便于处理

    // 初始化状态栈、符号栈
    stack<int> states;
    stack<string> symbols;

    // 初始化输入指针
    int inputPtr = 0;

    // 将状态0压入状态栈
    states.push(0);

    // 进行LR(1)分析
    while (true)
    {
        // 获取栈顶状态和当前输入符号
        int state = states.top();
        string symbol = input.substr(inputPtr, 1);

        // 查找分析表
        int action = ACTION[make_pair(state, symbol)];
        int nextState = GOTO[make_pair(state, symbol)];

        // 输出分析过程
        cout << inputPtr + 1 << " " << state << " ";
        if (symbols.empty())
        {
            cout << " # ";  // 空栈使用#表示
        }
        else
        {
            cout << " " << symbols.top() << " ";
        }
        cout << input.substr(inputPtr) << " " << actions[action] << " ";
        if (action == 0)
        {
            // 移进
            symbols.push(symbol);
            states.push(nextState);
            inputPtr++;
        }
        else if (action == 1)
        {
            // 规约
            LR1Item item = productions[REDUCE[nextState - 1][0]];
            for (int i = 0; i < item.right.length(); i++)
            {
                symbols.pop();
                states.pop();
            }
            symbols.push(item.left);
            int prevState = states.top();
            states.push(GOTO[make_pair(prevState, item.left)]);
        }
        else
        {
            // 接受
            break;
        }
        cout << endl;
    }

    cout << "分析成功！" << endl;

    return 0;
}