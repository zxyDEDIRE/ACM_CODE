#include <stdio.h>
#include <ctype.h>
#include <iostream> 

void E();
void G();
void T();
void S();
void F();

char lookahead; // ??ǰ?????ַ?

void match(char c) {
    if (lookahead == c) {
        lookahead = getchar(); // ????һ?????
    } else {
        printf("Error: invalid syntax\n");
        exit(0);
    }
}

void E() {
    T();
    G();
}

void G() {
    if (lookahead == '+') {
        match('+');
        T();
        G();
    } else if (lookahead == '-') {
        match('-');
        T();
        G();
    } // else: ?մ?
}

void T() {
    F();
    S();
}

void S() {
    if (lookahead == '*') {
        match('*');
        F();
        S();
    } else if (lookahead == '/') {
        match('/');
        F();
        S();
    } // else: ?մ?
}

void F() {
    if (lookahead == '(') {
        match('(');
        E();
        match(')');
    } else if (isalpha(lookahead)) {
        match(lookahead);
    } else {
        printf("Error: invalid syntax\n");
        exit(0);
    }
}

int main() {
    printf("???һ???#????ķ??Ŵ?(????+-*/????i#)??");
    lookahead = getchar();
    E();

    if (lookahead == '#') {
        printf("???Ŵ??Ϸ?\n");
    } else {
        printf("Error: invalid syntax\n");
    }

    return 0;
}
