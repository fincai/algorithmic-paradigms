#include <cstdio>
#include <cstring>

int * buildNext(char* P);

int KMP_match(char* T, char* P) {
    int *next = buildNext(P);
    size_t n = strlen(T), i = 0;
    size_t m = strlen(P), j = 0;
    while (j < m && i < n)
        if (j < 0 || T[i] == P[j])
        { i++; j++; }
        else j = next[j];
    return i - j;
}

int main() {

}
