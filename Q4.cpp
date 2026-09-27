#include <iostream>
using namespace std;

class Stack
{
public:
    double arr[100];
    int top;

    Stack()
    {
        top = -1;
    }

    void push(double value)
    {
        arr[++top] = value;
    }

    double pop()
    {
        return arr[top--];
    }

    double peek()
    {
        return arr[top];
    }

    bool empty()
    {
        return top == -1;
    }
};

class CharStack
{
public:
    char arr[100];
    int top;

    CharStack()
    {
        top = -1;
    }

    void push(char value)
    {
        arr[++top] = value;
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
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

void infixToPostfix(char infix[], char postfix[])
{
    CharStack s;

    int i = 0;
    int j = 0;

    while (infix[i] != '\0')
    {
        char c = infix[i];

        if (c == ' ')
        {
            i++;
            continue;
        }

        if ((c >= '0' && c <= '9') || c == 'x')
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

double power(double a, double b)
{
    double result = 1;

    for (int i = 0; i < (int)b; i++)
    {
        result = result * a;
    }

    return result;
}

double evaluatePostfix(char postfix[], double x)
{
    Stack s;

    int i = 0;

    while (postfix[i] != '\0')
    {
        char c = postfix[i];

        if (c == ' ')
        {
            i++;
            continue;
        }

        if (c == 'x')
        {
            s.push(x);
        }
        else if (c >= '0' && c <= '9')
        {
            double number = c - '0';
            s.push(number);
        }
        else if (isOperator(c))
        {
            double b = s.pop();
            double a = s.pop();

            double result;

            if (c == '+')
                result = a + b;

            else if (c == '-')
                result = a - b;

            else if (c == '*')
                result = a * b;

            else if (c == '/')
                result = a / b;

            else
                result = power(a, b);

            s.push(result);
        }

        i++;
    }

    return s.pop();
}

bool checkCondition(double x, int condition)
{
    if (condition == 1)
        return x >= 0;

    if (condition == 2)
        return x < 0;

    if (condition == 3)
        return x > 0;

    if (condition == 4)
        return x <= 0;

    if (condition == 5)
        return x == 0;

    if (condition == 6)
        return x != 0;

    return false;
}

void displayPostfix(char postfix[])
{
    int i = 0;

    while (postfix[i] != '\0')
    {
        cout << postfix[i] << " ";
        i++;
    }

    cout << endl;
}

int main()
{
    char expression1[100];
    char expression2[100];

    int condition1;
    int condition2;

    double x;

    cout << "Enter Expression 1: ";
    cin.getline(expression1, 100);

    cout << "Enter Condition 1:" << endl;
    cout << "1. x >= 0" << endl;
    cout << "2. x < 0" << endl;
    cout << "3. x > 0" << endl;
    cout << "4. x <= 0" << endl;
    cout << "5. x == 0" << endl;
    cout << "6. x != 0" << endl;
    cout << "Enter condition number: ";
    cin >> condition1;

    cin.ignore();

    cout << "Enter Expression 2: ";
    cin.getline(expression2, 100);

    cout << "Enter Condition 2:" << endl;
    cout << "1. x >= 0" << endl;
    cout << "2. x < 0" << endl;
    cout << "3. x > 0" << endl;
    cout << "4. x <= 0" << endl;
    cout << "5. x == 0" << endl;
    cout << "6. x != 0" << endl;
    cout << "Enter condition number: ";
    cin >> condition2;

    cout << "Enter x: ";
    cin >> x;

    char postfix[100];

    if (checkCondition(x, condition1))
    {
        infixToPostfix(expression1, postfix);

        cout << endl;
        cout << "The program selects:" << endl;

        if (condition1 == 1)
            cout << "Condition: x >= 0" << endl;
        else if (condition1 == 2)
            cout << "Condition: x < 0" << endl;
        else if (condition1 == 3)
            cout << "Condition: x > 0" << endl;
        else if (condition1 == 4)
            cout << "Condition: x <= 0" << endl;
        else if (condition1 == 5)
            cout << "Condition: x == 0" << endl;
        else
            cout << "Condition: x != 0" << endl;

        cout << "Expression: " << expression1 << endl;

        cout << "Postfix: ";
        displayPostfix(postfix);

        cout << "Calculated Value: ";
        cout << evaluatePostfix(postfix, x) << endl;
    }
    else if (checkCondition(x, condition2))
    {
        infixToPostfix(expression2, postfix);

        cout << endl;
        cout << "The program selects:" << endl;

        if (condition2 == 1)
            cout << "Condition: x >= 0" << endl;
        else if (condition2 == 2)
            cout << "Condition: x < 0" << endl;
        else if (condition2 == 3)
            cout << "Condition: x > 0" << endl;
        else if (condition2 == 4)
            cout << "Condition: x <= 0" << endl;
        else if (condition2 == 5)
            cout << "Condition: x == 0" << endl;
        else
            cout << "Condition: x != 0" << endl;

        cout << "Expression: " << expression2 << endl;

        cout << "Postfix: ";
        displayPostfix(postfix);

        cout << "Calculated Value: ";
        cout << evaluatePostfix(postfix, x) << endl;
    }
    else
    {
        cout << "No condition is satisfied." << endl;
    }

    return 0;
}