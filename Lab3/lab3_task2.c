
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char data;
    struct Node *next;
};

struct Node *top = NULL;

int is_empty()
{
    if (top == NULL)
        return 1;
    else
        return 0;
}

int is_full()
{
    return 0;
}

int push(char x)
{
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL)
        return 0;

    newNode->data = x;
    newNode->next = top;

    top = newNode;

    return 1;
}

char pop()
{
    struct Node *temp;
    char x;

    if (is_empty() == 1)
        return '\0';

    temp = top;
    x = top->data;

    top = top->next;

    free(temp);

    return x;
}

char peek()
{
    if (is_empty() == 0)
        return top->data;

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
    char expression[100];
    char result[200];

    int i = 0;
    int j = 0;
    int error = 0;

    printf("Enter expression: ");
    fgets(expression, 100, stdin);

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
            if (push(x) == 0)
            {
                error = 1;
                break;
            }
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

            if (push(x) == 0)
            {
                error = 1;
                break;
            }
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

    while (is_empty() == 0)
    {
        pop();
    }

    return 0;
}
