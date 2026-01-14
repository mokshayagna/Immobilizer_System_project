#include <stdio.h>
#include <string.h>

int main() {
    unsigned char a[4] = {0x12, 0x00, 0x34, 0x56};
    unsigned char b[4] = {0x12, 0x00, 0x34, 0x56};

    if (memcmp(a, b, 4) == 0)
        printf("Memory is equal\n");
    else
        printf("Memory is NOT equal\n");

    return 0;
}
