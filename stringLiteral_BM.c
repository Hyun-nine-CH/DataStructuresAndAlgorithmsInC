#include <stdio.h>
#include <string.h>
#include <limits.h>

int bm_match(const char txt[], const char pat[]) {
    int pt, pp;
    int skip[UCHAR_MAX + 1]; // ASCII 문자 범위
    int len_txt = strlen(txt);
    int len_pat = strlen(pat);

    for(pt=0; pt <= UCHAR_MAX; pt++)
        skip[pt] = len_pat; // 기본값은 패턴 길이
    for(pt = 0; pt < len_pat - 1; pt++)
        skip[(unsigned char)pat[pt]] = len_pat - pt - 1; // 문자에 대한 스킵 값 설정

    while(pt < len_txt) {
        pp = len_pat - 1;
        while(txt[pt]==pat[pp]) { // 패턴의 끝에서부터 비교
            if (pp == 0) {
                return pt; // 패턴이 일치하면 시작 위치 반환
            }
            pt--; // txt 커서 이동
            pp--; // pat 커서 이동
        }
        if (pp < 0) {
            return pt; // 패턴이 일치하면 시작 위치 반환
        }
        pt += (skip[(unsigned char)txt[pt]]) ? skip[(unsigned char)txt[pt]]: len_pat - pp;
    }
    return -1; // 패턴이 없으면 -1 반환
}
int main(void) {
    char s1[256], s2[256];

    puts("보이어-무어법");
    printf("텍스트 입력: ");
    scanf("%s", s1);

    printf("패턴 입력: ");
    scanf("%s", s2);

    int idx = bm_match(s1, s2);

    if (idx != -1)
        printf("패턴은 텍스트의 %d번째 위치에서 시작합니다.\n", idx + 1); // 1-based index
    else
        printf("패턴이 텍스트에 없습니다.\n");

    return 0;
}