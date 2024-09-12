#include <stdio.h>

float calculate(float x, float y, char operator) {
    switch (operator) {
        case '+':
            return x + y;
        case '-':
            return x - y;
        case '*':
            return x * y;
        case '/':
            if (y == 0) {
                fprintf(stderr, "Division by zero\n");
                return -1;
            }

            return x / y;
        default:
            fprintf(stderr, "Invalid operation\n");
            return -1;
    }
}

int main(void) {
    float x;
    float y;
    char operator;
    printf("Enter a number, an operator (+,-,*,/), and another number. Format: n o n\n");
    scanf("%f %c %f", &x, &operator, &y);
    printf("Result: %f\n", calculate(x, y, operator));
    return 0;
}
