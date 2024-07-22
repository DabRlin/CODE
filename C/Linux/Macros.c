#include <stdio.h>

#define DEBUG

int main() {
#ifdef DEBUG
    printf("Debug mode is enabled\n");
#else
    printf("Debug mode is disabled\n");
#endif
    return 0;
}
