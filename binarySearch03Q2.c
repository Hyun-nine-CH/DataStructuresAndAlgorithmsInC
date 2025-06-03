#include <stdio.h>

int main(void) {
    int i;
    int x[] = {6, 4, 3, 2, 1, 9, 8};
    int nx = sizeof(x) / sizeof(x[0]);
    int key;

    printf("검색할 값: ");
    scanf("%d", &key);

    // 인덱스 출력
    printf("  |");
    for (i = 0; i < nx; i++)
        printf(" %d", i);
    printf("\n--+");
    for (i = 0; i < nx * 2 + 1; i++)
        putchar('-');
    putchar('\n');

    // 선형 검색 과정
    for (i = 0; i < nx; i++) {
        printf("  |");
        for (int j = 0; j < i * 2 + 1; j++) putchar(' ');
        printf("*\n");

        printf("%2d|", i);
        for (int j = 0; j < nx; j++)
            printf(" %d", x[j]);
        putchar('\n');

        if (x[i] == key)
            break;
    }

    if (i == nx)
        printf("\n%d은 존재하지 않습니다.\n", key);
    else
        printf("\n%d은 x[%d]에 존재합니다.\n", key, i);

    return 0;
}