#include <stdio.h>
#include <stdlib.h>

int bin_search(const int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    do {
        int mid = left + (right - left) / 2; // Prevents overflow

        if (arr[mid] == target) {
            return mid; // Target found
        } else if (arr[mid] < target) {
            left = mid + 1; // Search in the right half
        } else {
            right = mid - 1; // Search in the left half
        }
    } while (left <= right);

    return -1; // Target not found
}

int main(void) {
    int nx, ky;

    puts("이진 검색");
    printf("요소의 개수: ");
    scanf("%d", &nx);
    int *x = malloc(nx * sizeof(int));
    printf("x[0]: ");
    scanf("%d", &x[0]);
    for (int i = 1; i < nx; i++) {
        do {
            printf("x[%d]: ", i);
            scanf("%d", &x[i]);
        } while (x[i] < x[i - 1]); // Ensure the array is sorted
    }
    printf("검색할 값: ");
    scanf("%d", &ky);
    int idx = bin_search(x, nx, ky);
    if (idx == -1) {
        puts("검색 값이 존재하지 않습니다.");
    } else {
        printf("%d값은 x[%d]에 있습니다.\n", ky, idx);
    }
    free(x);
    return 0;
}