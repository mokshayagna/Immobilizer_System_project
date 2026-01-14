#include <stdio.h>
#include <string.h>

int main() {
    char a[] = "engine";
    char b[] = "engine";

    if (strcmp(a, b) == 0)
        printf("Strings are equal\n");
    else
        printf("Strings are NOT equal\n");

    return 0;
}
