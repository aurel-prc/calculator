#include <stdio.h>

typedef enum {
    SUCCESS,
    DIVISION_BY_ZERO,
    INVALID_OPERATOR,
} CalculatorError;

CalculatorError calculate(float x, float y, char operator, float* out) {
    switch (operator) {
        case '+':
            *out = x + y;
            return SUCCESS;
        case '-':
            *out = x - y;
            return SUCCESS;
        case '*':
            *out = x * y;
            return SUCCESS;
        case '/':
            if (y == 0) {
                return DIVISION_BY_ZERO;
            }

            *out = x / y;
            return SUCCESS;
        default:
            return INVALID_OPERATOR;
    }
}

int main(void) {
    float x, y;
    char operator;
    printf("Enter a number, an operator (+,-,*,/), and another number. Format: n o n\n");
    scanf("%f %c %f", &x, &operator, &y);

    float result;

    switch (calculate(x, y, operator, &result)) {
        case SUCCESS:
            printf("Result: %f\n", result);
            return 0;
        case DIVISION_BY_ZERO:
            fprintf(stderr, "Division by zero\n");
            return -1;
        case INVALID_OPERATOR:
            fprintf(stderr, "Invalid operator\n");
            return -1;
    }
}
