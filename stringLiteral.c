#include <stdio.h>

int bf_match (const char txt[], const char pat[]) {
    int pt = 0; // txt의 커서
    int pp = 0; // pat의 커서

    while (txt[pt] != '\0' && pat[pp] != '\0') {
        if (txt[pt] == pat[pp]) { // 문자가 일치하면
            pt++;
            pp++;
        } else { // 문자가 일치하지 않으면
            pt = pt - pp + 1; // 다음 문자로 이동
            pp = 0; // 패턴의 시작으로 이동
        }
    }

    return (pat[pp] == '\0') ? pt - pp : -1; // 패턴이 끝까지 일치하면 시작 위치 반환, 아니면 -1 반환
}
int main(void) {
    char s1[256], s2[256];

    puts("브루트-포스법");
    printf("텍스트: ");
    scanf("%s", s1);
    printf("패턴: ");
    scanf("%s", s2);
    int idx = bf_match(s1, s2);
    if (idx == -1) {
        puts("패턴이 텍스트에 없습니다.");
    } else {
        printf("패턴은 텍스트의 %d번째 위치에서 시작합니다.\n", idx+1);
    }
    return 0;
}