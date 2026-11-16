
#include <stdio.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

int is_empty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

int is_full()
{
    if (top == SIZE - 1)
        return 1;
    else
        return 0;
}

void push(char x)
{
    if (is_full() == 0)
    {
        top++;
        stack[top] = x;
    }
}

char pop()
{
    char x;

    if (is_empty() == 0)
    {
        x = stack[top];
        top--;
        return x;
    }

    return '\0';
}

char peek()
{
    if (is_empty() == 0)
        return stack[top];

    return '\0';
}

int priority(char x)
{
    if (x == '+' || x == '-')
        return 1;

    if (x == '*' || x == '/')
        return 2;

    return 0;
}

int main()
{
    char expression[SIZE];
    char result[SIZE * 2];

    int i = 0;
    int j = 0;
    int error = 0;

    printf("Enter expression: ");
    fgets(expression, SIZE, stdin);

    while (expression[i] != '\0' && expression[i] != '\n')
    {
        char x = expression[i];

        if (x == ' ' || x == '\t')
        {
            i++;
            continue;
        }

        if ((x >= 'A' && x <= 'Z') ||
            (x >= 'a' && x <= 'z') ||
            (x >= '0' && x <= '9'))
        {
            result[j] = x;
            j++;
        }
        else if (x == '(')
        {
            push(x);
        }
        else if (x == ')')
        {
            while (is_empty() == 0 && peek() != '(')
            {
                result[j] = pop();
                j++;
            }

            if (is_empty() == 1)
            {
                error = 1;
                break;
            }

            pop();
        }
        else if (x == '+' || x == '-' || x == '*' || x == '/')
        {
            while (is_empty() == 0 &&
                   peek() != '(' &&
                   priority(peek()) >= priority(x))
            {
                result[j] = pop();
                j++;
            }

            push(x);
        }
        else
        {
            error = 1;
            break;
        }

        i++;
    }

    while (is_empty() == 0)
    {
        if (peek() == '(')
        {
            error = 1;
            break;
        }

        result[j] = pop();
        j++;
    }

    result[j] = '\0';

    if (error == 1)
    {
        printf("Wrong expression!\n");
    }
    else
    {
        printf("Postfix expression: %s\n", result);
    }

    return 0;
}
