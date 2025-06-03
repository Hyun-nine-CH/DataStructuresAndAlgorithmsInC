#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    int n1 = *(int *)a;
    int n2 = *(int *)b;
    if (n1 < n2) return -1;
    if (n1 > n2) return 1;
    return 0;
}

int lower_bound(int *arr, int size, int target) {
    int left = 0, right = size;
    while (left < right) {
        int mid = (left + right) / 2;
        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

int main() {
    int N;
    scanf("%d", &N);

    int X[100000], sorted[100000];

    for (int i = 0; i < N; i++) {
        scanf("%d", &X[i]);
        sorted[i] = X[i];
    }

    // 1. 정렬
    qsort(sorted, N, sizeof(int), compare);

    // 2. 중복 제거
    int unique[100000], unique_cnt = 0;
    unique[unique_cnt++] = sorted[0];
    for (int i = 1; i < N; i++) {
        if (sorted[i] != sorted[i - 1])
            unique[unique_cnt++] = sorted[i];
    }

    // 3. 각 원소에 대해 lower_bound 위치 출력
    for (int i = 0; i < N; i++) {
        int pos = lower_bound(unique, unique_cnt, X[i]);
        printf("%d ", pos);
    }

    return 0;
}