#include <cstdio>
#include <cstring>

int* buildNext(char* P) {
    size_t m = strlen(P), j = 0;
    int *next = new int[m];
    int t = next[0] = -1;
    while (j < m-1)
      if (t < 0 || P[j] == P[t]) 
        next[++j] = ++t;
      else t = next[t];
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
    char text[ ] = "acabaabaabcacaabc";
    char pattern[ ] = "abaabcac";
    size_t n = strlen(text), m = strlen(pattern);
    int i = KMP_match(pattern, text);
    if (i > (n-m)) 
        printf("No match found.\n");
    else
        printf("Match found at index %d.\n", i);
}
