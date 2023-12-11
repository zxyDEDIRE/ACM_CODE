#include "testlib.h"

// main 需要接收命令行参数
int main(int argc, char *argv[])
{
    // 初始化 checker 环境 —— 解析命令行参数、打开文件……
    // registerTestlibCmd(argc, argv, 1);
    registerGen(argc, argv, 1);//初始化数据生成器

    int n = atoi(argv[1]);
    printf("%d\n",n);

    return 0;
}