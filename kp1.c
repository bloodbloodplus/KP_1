#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h>
double Q(double x);
int check_control(double q);
int main() {
    setlocale(LC_ALL, "RUS");
    double x;
    double q_val;
    int status;
    printf("Введите X: ");
    scanf("%lf", &x);
    q_val = Q(x);
    printf("Q(%.4lf) = %.4lf\n", x, q_val);
    status = check_control(q_val);
    if (status == 1) {
        printf("Состояние: Норма\n");
    }
    else {
        printf("Состояние: Отклонение\n");
    }
    return 0;
}
double Q(double x) {
    if (x < 28) {
        return pow(x - 28, 2) / 3 + 10;
    }
    else if (x >= 28 && x <= 45) {
        return 3 * (x - 36.5) + 50;
    }
    else {
        return 2 * sqrt(x - 45 + 1) + 60;
    }
}
int check_control(double q) {
    double Q0 = 50.00;
    double dQ = 11.0;
    printf("Допустимый диапазон: [%.2lf; %.2lf]\n", Q0 - dQ, Q0 + dQ);
    if (fabs(q - Q0) > dQ) {
        return 0;
    }
    else {
        return 1;
    }
}