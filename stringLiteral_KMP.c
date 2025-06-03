#include <stdio.h>
#include <time.h>
#include <string.h>

int kmp_match(const char txt[], const char pat[]) {
    int pt = 1, pp = 0;
    int skip[1024];
    skip[pt] = 0;
    while(pat[pt] != '\0') {
        if (pat[pt] == pat[pp])
            skip[++pt] = ++pp;
        else if (pp == 0)
            skip[++pt] = 0;
        else
            pp = skip[pp];
    }
    pt = pp = 0;
    while (txt[pt] != '\0' && pat[pp] != '\0') {
        if (txt[pt] == pat[pp]) {
            pt++;
            pp++;
        } else if (pp == 0) {
            pt++;
        } else {
            pp = skip[pp];
        }
    }
    return (pat[pp] == '\0') ? pt - pp : -1;
}

int bf_match(const char txt[], const char pat[]) {
    int pt, pp;
    int len_txt = strlen(txt);
    int len_pat = strlen(pat);
    for (pt = 0; pt <= len_txt - len_pat; pt++) {
        for (pp = 0; pp < len_pat; pp++) {
            if (txt[pt + pp] != pat[pp])
                break;
        }
        if (pp == len_pat)
            return pt;
    }
    return -1;
}

int main(void) {
    char s1[256], s2[256];
    printf("텍스트 입력: ");
    scanf("%s", s1);
    printf("패턴 입력: ");
    scanf("%s", s2);

    clock_t start, end;
    double duration;

    // Brute-force 실행 시간 측정
    start = clock();
    int bf_idx = bf_match(s1, s2);
    end = clock();
    duration = (double)(end - start) / CLOCKS_PER_SEC;
    printf("[Brute-Force] 위치: %d, 실행 시간: %.6f초\n", bf_idx + 1, duration);

    // KMP 실행 시간 측정
    start = clock();
    int kmp_idx = kmp_match(s1, s2);
    end = clock();
    duration = (double)(end - start) / CLOCKS_PER_SEC;
    printf("[KMP] 위치: %d, 실행 시간: %.6f초\n", kmp_idx + 1, duration);

    return 0;
}
