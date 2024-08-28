#include <stdio.h>

void min_max();
void Guessing();
char *Reverse(char *str_in);
void swap(int pos1, int pos2, char *str);

int main() {
    // min_max();
    // Guessing();
    // char c[] = "Hello";
    // Reverse(c);
}

void min_max() {
    int min, max, number;
    int first = 1;
    while (scanf("%d", &number) != EOF) {
        if (first || number < min)
            min = number;
        if (first || number > max)
            max = number;
        first = 0;
    }
    printf("Minimum = %d\nMaximum = %d\n", min, max);
}

void Guessing() {
    int guess;
    int val = 42;
    printf("guess the number\n");
    while (scanf("%d", &guess) != EOF) {
        if (guess < 42)
            printf("Too low - guess again.\n");
        else if (guess > 42)
            printf("Too high - guess again.\n");
        else
            break;
    }
    printf("GG!\n");
}

int str_len(char *str) {
    char c;
    int i = 0;
    do {
        c = str[i];
        i++;
    } while (c != '\0');
    return i;
}

void swap(int pos1, int pos2, char *str) {
    if (pos1 == pos2)
        return;
    char buff;
    buff = str[pos1];
    str[pos1] = str[pos2];
    str[pos2] = buff;
}

char *Reverse(char *str_in) {
    int len = str_len(str_in);
    for (int i = 0; i < len / 2; i++) {
        swap(i, len - (i + 2), str_in);
    }
    return str_in;
}
