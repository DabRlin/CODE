#include <stdio.h>
int main(void){
    int array2[2][4]={{1,2,3,4},{2,3,4,5}};
    int max = array2[0][0];
    for (int i = 0; i < sizeof(array2)/sizeof(array2[0]); i++)
    {
        for (int j = 0; j < sizeof(array2[0])/sizeof(array2[0][0]); j++)
        {

            if (array2[i][j]>max)
            {
                max = array2[i][j];
            }
            
            printf("%d\n",array2[i][j]);
        }
        
    }
    printf("二阶数组的最大值是：%d",max);
    return 0;
}