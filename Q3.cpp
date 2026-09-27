#include <iostream>
using namespace std;

class Stack
{
public:
    char arr[100];
    int top;

    Stack()
    {
        top = -1;
    }

    void push(char x)
    {
        arr[++top] = x;
    }

    char pop()
    {
        return arr[top--];
    }

    char peek()
    {
        return arr[top];
    }

    bool empty()
    {
        return top == -1;
    }
};

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;

    if (op == '*' || op == '/')
        return 2;

    if (op == '^')
        return 3;

    return 0;
}

bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        return true;

    return false;
}

void infixToPostfix(char infix[], char postfix[])
{
    Stack s;
    int i = 0;
    int j = 0;

    while (infix[i] != '\0')
    {
        char c = infix[i];

        if ((c >= 'A' && c <= 'Z') ||
            (c >= 'a' && c <= 'z') ||
            (c >= '0' && c <= '9'))
        {
            postfix[j++] = c;
        }
        else if (c == '(')
        {
            s.push(c);
        }
        else if (c == ')')
        {
            while (!s.empty() && s.peek() != '(')
            {
                postfix[j++] = s.pop();
            }

            if (!s.empty())
                s.pop();
        }
        else if (isOperator(c))
        {
            while (!s.empty() &&
                   s.peek() != '(' &&
                   precedence(s.peek()) >= precedence(c))
            {
                postfix[j++] = s.pop();
            }

            s.push(c);
        }

        i++;
    }

    while (!s.empty())
    {
        postfix[j++] = s.pop();
    }

    postfix[j] = '\0';
}

void reverseExpression(char infix[], char reversed[])
{
    int length = 0;

    while (infix[length] != '\0')
    {
        length++;
    }

    int j = 0;

    for (int i = length - 1; i >= 0; i--)
    {
        if (infix[i] == '(')
            reversed[j++] = ')';
        else if (infix[i] == ')')
            reversed[j++] = '(';
        else
            reversed[j++] = infix[i];
    }

    reversed[j] = '\0';
}

void infixToPrefix(char infix[], char prefix[])
{
    char reversed[100];
    char postfix[100];

    reverseExpression(infix, reversed);
    infixToPostfix(reversed, postfix);

    int length = 0;

    while (postfix[length] != '\0')
    {
        length++;
    }

    int j = 0;

    for (int i = length - 1; i >= 0; i--)
    {
        prefix[j++] = postfix[i];
    }

    prefix[j] = '\0';
}

void display(char arr[])
{
    int i = 0;

    while (arr[i] != '\0')
    {
        cout << arr[i] << " ";
        i++;
    }

    cout << endl;
}

int main()
{
    char expression1[] = "(1-A)/(1+A)";
    char expression2[] = "1-A^2";
    char expression3[] = "(1/2)*(B-C)";

    char postfix[100];
    char prefix[100];

    cout << "Expression 1 RHS:" << endl;

    infixToPostfix(expression1, postfix);
    infixToPrefix(expression1, prefix);

    cout << "Postfix: ";
    display(postfix);

    cout << "Prefix: ";
    display(prefix);

    cout << endl;

    cout << "Expression 2 RHS:" << endl;

    infixToPostfix(expression2, postfix);
    infixToPrefix(expression2, prefix);

    cout << "Postfix: ";
    display(postfix);

    cout << "Prefix: ";
    display(prefix);

    cout << endl;

    cout << "Expression 3 RHS:" << endl;

    infixToPostfix(expression3, postfix);
    infixToPrefix(expression3, prefix);

    cout << "Postfix: ";
    display(postfix);

    cout << "Prefix: ";
    display(prefix);

    return 0;
}