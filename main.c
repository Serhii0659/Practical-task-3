#include <stdio.h>
#include <conio.h>

int count_valid_numbers(int p) {
    if (p == 1) {
        return 2;
    }

    // Масиви для збереження кількості чисел різних довжин
    int a[p + 1];
    int b[p + 1];

    // Ініціалізація початкових значень
    a[1] = 2; // 5, 9
    b[1] = 0;

    // Обчислення для довжин від 2 до p
    for (int i = 2; i <= p; i++) {
        a[i] = a[i-1] + b[i-1];
        b[i] = a[i-1];
    }

    // Повернення кількості чисел довжини p
    return a[p] + b[p];
}

int main () {
    int p;
    do {
        printf ("Enter the value of p: ");
        scanf("%d", &p);
        if (p < 1) {
            printf ("p should be more or equal to 1\n");
        }
        if (p > 30) {
            printf ("p should not be more than 30\n");
        }
    } while (p > 30 || p < 1);

    printf("Amount of numbers with %d didgits: %d\n", p, count_valid_numbers(p));

    printf ("Press any key to exit the program.");
    getch();
    return 0;
}