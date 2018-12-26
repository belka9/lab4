#include <stdio.h>
#include <string.h>
#define SIZE_NUMBER 10

void swap(char *a, char *b){
    char t = *a;
    *a = *b;
    *b = t;
}

int check(const char str[], int len) {
    int arr[SIZE_NUMBER] = {0};
    for (int i = 0; i < len; i++){
        if (str[i] > '9' || str[i] < '0')
            return 1;
        if (++arr[str[i] - '0'] > 1)
            return 1;
    }
    return 0;

}

void dijktraPerm(char str[], int len, int n) {
    int count = 0;
    while (count++ < n) {
        int i = len - 2;
        while (i != -1 && str[i] >= str[i + 1]) {
            --i;
            if (i == -1)
                return;//перестановок больше нет
        }
        int j = len - 1;

        while (str[i] >= str[j])
            --j;
        swap(&str[i], &str[j]);
        int pos = i + 1;//с этого момента пошла сортировка
        int end = len - 1;
        while (pos < end) {
            swap(&str[pos], &str[end]);
            ++pos;
            --end;
        }
        printf("%s\n", str);
    }
}

int main() {
    char a[SIZE_NUMBER] = {0};
    int n = 0, len = 0;
    scanf("%s", a);
    len = strlen(a);
    scanf("%d", &n);
    if (len == 1 || n <= 0)
        return 0;

    if (check(a, len) == 1) {
        printf("bad input");
        return 0;
    }
    dijktraPerm(a, len, n);
    return 0;

}