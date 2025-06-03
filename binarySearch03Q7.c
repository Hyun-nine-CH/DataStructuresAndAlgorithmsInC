#include <stddef.h>
#include <stdio.h>
#include <string.h>

void *seqsearch(const void *key, const void *base, size_t nmemb, size_t size,
                int (*compar)(const void *, const void *)) {
    const char *ptr = base;  // void*는 산술 연산 안 되므로 char*로 캐스팅

    for (size_t i = 0; i < nmemb; i++) {
        const void *element = ptr + i * size;
        if (compar(key, element) == 0) {
            return (void *)element;  // 찾으면 그 요소의 주소 반환
        }
    }

    return NULL;  // 못 찾으면 NULL 반환
}

int int_cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int main(void) {
    int arr[] = {5, 7, 3, 2, 9, 1};
    int key = 1;

    int *result = seqsearch(&key, arr, sizeof(arr)/sizeof(arr[0]), sizeof(int), int_cmp);

    if (result != NULL)
        printf("찾은 값: %d\n", *result);
    else
        printf("값을 찾지 못했습니다.\n");

    return 0;
}