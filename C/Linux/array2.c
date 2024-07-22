#include <stdio.h>
int main (){
    int matrix[3][4] = {
        {1, 2, 3, 4},   // 第一行
        {5, 6, 7, 8},   // 第二行
        {9, 10, 11, 12} // 第三行
    };

// 错误的示例：不能在循环中使用 sizeof(matrix)
for (int i = 0; i < sizeof(matrix) / sizeof(matrix[0]); i++) {
    for (int j = 0; j < sizeof(matrix[0]) / sizeof(matrix[0][0]); j++) {
        printf("%3d ", matrix[i][j]);
    }
    printf("\n");
}

    return 0;
}