#include <cstdio>
#include <cstring>

int match1(char* P, char* T) {
    size_t n = strlen(T), i = 0;
    size_t m = strlen(P), j = 0;
    while (j < m && i < n) 
        if (T[i] == P[j]) { i++; j++; }
        else { i = i - j + 1; j = 0; }  //模式串j指针复位，文本串i指针指向下一个起始字符
    return i - j;   // 匹配失败时, j < m 且 i = n (i越界仍不能完整匹配模式串)  <=> i与j之差大于n - m
}


int main() {
    char pattern[] = "01";
    char text[] = "00000000000000000000";
    size_t n = strlen(text), m = strlen(pattern);
    int idx = match1(pattern, text);
    if (idx > (n - m)) 
        printf("No match found.\n");
    else 
        printf("Match found at index %d.\n", idx);
}
