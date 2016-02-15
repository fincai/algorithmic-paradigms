#include <cstdio>
#include <cstring>

int* buildNext(char* P) {
    size_t m = strlen(P), j = 0;
    int *next = new int[m];
    int t = next[0] = -1;
    while (j < m-1) 
      if (t < 0 || P[j] == P[t]) {
          j++; t++;
          next[j] = (P[j] == P[t]) ? next[t] : t; //P[j]失配后前移得到的字符P[t]与P[j]相同, 即仍然失配
      }                                           //故下一个对齐位置应该与P[t]失配时的对齐位置next[t]相同
      else t = next[t];                           //依此类推，连续重复子串中每个字符的next都相同(等于第一个重复字符的next)
    return next;
}

int KMP_match(char* P, char* T) {
    int *next = buildNext(P);   
    int n = (int)strlen(T), i = 0;
    int m = (int)strlen(P), j = 0;
    while (j < m && i < n) 
      if (j < 0 || T[i] == P[j])
      { i++; j++; }
      else j = next[j];
    delete [ ] next;
    return i - j;
}

int main() {
    char text[ ] = "000100001";
    char pattern[ ] = "00001";
    size_t n = strlen(text), m = strlen(pattern);
    int i = KMP_match(pattern, text);
    if (i > (n-m))
      printf("Match not found.\n");
    else
      printf("Match found at index %d\n", i);
    return 0;
}
