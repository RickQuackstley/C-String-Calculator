#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(void)
{
    char operatorLoc;
    char operator;

    bool foundOperator = false;

    const char equation[] = "10/5";
    //enter equation above
    const int equationLen = strlen(equation);

    const char operators[] = {'+', '-', '*', '/', '\0'};
    const int operatorsLen = strlen(operators);

    const char nums[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '\0'};
    const int numsLen = strlen(nums);

    for (int x = 0; x < equationLen; x++)
    {
        for (int y = 0; y < operatorsLen; y++)
        {
            if (equation[x] == operators[y])
            {
                printf("operator found\n");
                operatorLoc = x;
                operator = equation[x];
                foundOperator = true;
            }
        }
    }

    if (foundOperator)
    {
        printf("column: %i\n", operatorLoc + 1);

        char num1[100] = "";
        char num2[100] = "";

        for (int c = 0; c < operatorLoc; c++)
        {
            strncat(num1, &equation[c], 1);
        }

        for (int n = operatorLoc + 1; n < equationLen; n++)
        {
            strncat(num2, &equation[n], 1);
        }

        printf("first num: %s\n", num1);
        printf("last num: %s\n", num2);

        float result;

        switch (operator)
        {
            case '+':
                result = atof(num1) + atof(num2);
                break;

            case '-':
                result = atof(num1) - atof(num2);
                break;

            case '*':
                result = atof(num1) * atof(num2);
                break;

            case '/':
                result = atof(num1) / atof(num2);
                break;
        }

        printf("result: %f", result);
    }

    return 0;
}