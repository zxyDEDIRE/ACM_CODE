import re
import math

# 定义运算符优先级
priority = {'+': 1,
            '-': 1,
            '*': 2,
            '/': 2,
            '%': 2,
            '^': 3}


def is_digit(c):
    return c.isdigit() or c == '.'


def infix_to_postfix(infix_str):
    postfix_str = ''
    op_stack = []
    i = 0
    while i < len(infix_str):
        c = infix_str[i]
        if is_digit(c):
            # 如果是数字，直接输出
            postfix_str += c
            # 如果下一个字符不是数字，加上分隔符&
            if i == len(infix_str) - 1 or not is_digit(infix_str[i + 1]):
                postfix_str += '&'
        elif c == '(':
            op_stack.append(c)
        elif c == ')':
            while op_stack[-1] != '(':
                postfix_str += op_stack.pop()
                postfix_str += '&'
            op_stack.pop()  # 弹出左括号
        elif c in priority:
            while op_stack and op_stack[-1] != '(' and c in priority and priority[c] <= priority[op_stack[-1]]:
                postfix_str += op_stack.pop()
                postfix_str += '&'
            op_stack.append(c)
        elif c == ' ':
            pass
        else:
            raise ValueError(f'非法字符: {c}')
        i += 1
    while op_stack:
        postfix_str += op_stack.pop()
        postfix_str += '&'
    return postfix_str[:-1]  # 去掉最后一个分隔符


def eval_postfix(postfix_str):
    num_stack = []
    tokens = re.split('&', postfix_str)
    for token in tokens:
        if is_digit(token[0]):
            num_stack.append(float(token))
        elif token in priority:
            num2 = num_stack.pop()
            num1 = num_stack.pop()
            if token == '+':
                num_stack.append(num1 + num2)
            elif token == '-':
                num_stack.append(num1 - num2)
            elif token == '*':
                num_stack.append(num1 * num2)
            elif token == '/':
                if num2 == 0:
                    raise ZeroDivisionError("除数为0")
                num_stack.append(num1 / num2)
            elif token == '%':
                if num2 == 0:
                    raise ZeroDivisionError("除数为0")
                num_stack.append(num1 % num2)
            elif token == '^':
                num_stack.append(math.pow(num1, num2))
            else:
                raise ValueError(f'不支持的操作符: {token}')
    return num_stack.pop()


def main():
    infix_str = input("输入中缀表达式: ")
    try:
        postfix_str = infix_to_postfix(infix_str)
        print(f"逆波兰式为: {postfix_str.replace('&', ' ')}")
        result = eval_postfix(postfix_str)
        print(f"计算结果为: {result}")
    except Exception as e:
        print(f"错误: {e}")


if __name__ == '__main__':
    main()


通过学习和查询资料，我解决了中缀表达式如何转化为逆波兰式、逆波兰式如何求值、如何处理除数为0的情况。同时，在代码编写过程中，我尝试通过注释和调试，提高了代码的可读性和可维护性。