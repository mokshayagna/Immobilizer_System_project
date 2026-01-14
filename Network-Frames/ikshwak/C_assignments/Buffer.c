#include <stdio.h>
int main() {
    FILE *fp = fopen("1.txt", "r");
    char buffer[256];

    if (fp == NULL) {
        perror("File open failed");
        return 1;
    }

    while (fgets(buffer, sizeof(buffer), fp)) {
        printf("%s\n", buffer);
    }

    fclose(fp);
    return 0;
}
