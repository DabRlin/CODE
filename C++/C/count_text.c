// #include <stdio.h>
// main(){
//     int c, cl1,cl2;
//     while(c = getchar()!=EOF){
//         if (c == '\n')
//             cl1++;
//     }
// }
// #include <stdio.h>

// int main() {
//     int c;
//     int previous_char = EOF; // 用于记录前一个字符

//     while ((c = getchar()) != EOF) {
//         if (c != ' ' || previous_char != ' ') {
//             putchar(c); // 输出字符
//             putchar(c);
//         }
//         previous_char = c; // 更新前一个字符
//     }

//     return 0;
// }
#include <stdio.h>
main(){
    int c, nl;
    nl = 0;
    while((c = getchar()) != EOF){
        if(c ==' '|| nl ==0){
            putchar(c);
        }
    }
}