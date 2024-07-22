#include <stdio.h>

void state_one() {
    printf("State one\n");
}

void state_two() {
    printf("State two\n");
}

void state_three() {
    printf("State three\n");
}

int main() {
    void (*state_table[3])() = {state_one, state_two, state_three};

    for (int i = 0; i < 3; i++) {
        state_table[i]();
    }

    return 0;
}
