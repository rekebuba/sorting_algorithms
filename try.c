#include <stdio.h>
#include <stdlib.h>

int main() {
    const char* word = "h";
    int value = strtol(&word[0], NULL, 10);
    printf("%d\n", value);

    return 0;
}
