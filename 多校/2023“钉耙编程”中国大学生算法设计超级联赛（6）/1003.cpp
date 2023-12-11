#include <iostream>
#include <vector>
using namespace std;
void gauss_jordan_solve(const matrix<double>& A, vector<double>& b, vector<double>& x) {
    int n = A.rows();
    int m = A.cols();
    // 进行行初等变换，使矩阵左上角的部分成为单位矩阵
    for (int i = 0; i < n; i++) {
        double divisor = A(i, i);
        for (int j = i; j < m; j++) {
            A(i, j) /= divisor;
        }
        b[i] /= divisor;
        for (int j = 0; j < m; j++) {
            if (j != i) {
                swap(A(i, j), A(j, i));
            }
        }
    }
    // 进行列初等变换，使矩阵的其余部分都变为零
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j < m; j++) {
            A(i, j) /= A(i, i);
        }
        b[i] /= A(i, i);
        for (int j = 0; j < m; j++) {
            if (j != i) {
                swap(A(i, j), A(j, i));
            }
        }
    }
    // 求解线性方程组 Ax=b
    x.resize(m);
    for (int i = 0; i < m; i++) {
        x[i] = b[i];
        for (int j = 0; j < m; j++) {
            x[i] -= A(i, j) * x[j];
        }
    }
}
 int main()
 {
 // 定义四个三维向量
 vector<double> a1 = {1, 2, 3};
 vector<double> a2 = {4, 5, 6};
 vector<double> a3 = {7, 8, 9};
 vector<double> a4 = {10, 11, 12};
 // 初始化x为零向量
 vector<double> x(3, 0);
 // 构建系数矩阵
 matrix<double> A(3, 3);
 A(0,0) = a1[0];  A(0,1) = a2[0];  A(0,2) = a3[0];
 A(1,0) = a1[1];  A(1,1) = a2[1];  A(1,2) = a3[1];
 A(2,0) = a1[2];  A(2,1) = a2[2];  A(2,2) = a3[2];
 // 构建常数向量
 vector<double> b(3);
 b[0] = a4[0];
 b[1] = a4[1];
 b[2] = a4[2];
 // 解决线性方程组 Ax=b
 vector<double> solution(3);
 gauss_jordan_solve(A, b, solution);
 // 将解向量x输出到控制台
 cout << "x = [" << solution[0] << ", " << solution[1] << ", " << solution[2] << "]" << endl;
 return 0;
 }
