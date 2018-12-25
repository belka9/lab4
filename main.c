#include <stdio.h>
#include <string.h>
#define swap(x,y) x ^= y;y ^= x;x ^= y;

int check(char str[10], int len) {
    for (int i = 0; i < len; i++) {
        if (str[i] > '9' || str[i] < '0')
            return 1;
    }
    int g = 1;
    for (int i = len - 2; i >= 0; --i) {
        if (str[i] == str[i + 1])
            ++g;
    }
    if (g == len)
        return 1;
    return 0;
}

int dijktraPerm(char str[10], int len) {
    int i = len - 2;
    while (i != -1 && str[i] >= str[i + 1]) {
        --i;
        if (i == -1)
            return 1;//перестановок больше нет
    }
    int j = len - 1;

    while (str[i] >= str[j])
        --j;
    swap(str[i], str[j]);
    int pos = i + 1;//с этого момента пошла сортировка
    int end = len - 1;
    while (pos < end) {
        swap(str[pos], str[end]);
        ++pos;
        --end;
    }
    printf("%s\n", str);

    return 0;
}

int main() {
    char a[10];
    int n, len;
    scanf("%s", a);
    len = strlen(a);
    scanf("%d", &n);
    if (len == 1)
        return 0;

    if (check(a, len) == 1) {
        printf("bad input");
        return 0;
    }

    while (n != 0 && dijktraPerm(a, len) == 0)
        --n;

    return 0;
}