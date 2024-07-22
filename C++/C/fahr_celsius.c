#include <stdio.h>
/*多行注释
多行注释
多行注释*/

//单行注释
#define LOWER 0
#define UPPER 20
#define STEP 20
main(){
    float fahr, celsius;
    float lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;
    fahr = celsius;
    // while (fahr <= upper) {
    //     celsius = 5.0 / 9.0 * (fahr - 32.0);
    //     printf("%3.0f %6.1f\n", fahr, celsius);
    //     fahr = fahr + step;
    // }
    for (fahr = LOWER; fahr <= UPPER ; fahr = fahr + STEP){
        printf("%3.0f %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32.0));

    }
}