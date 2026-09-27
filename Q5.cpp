#include <iostream>
using namespace std;

class Stack
{
public:
    char arr[500];
    int top;

    Stack()
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
    if (op == '+')
        return 1;

    if (op == '-')
        return 1;

    if (op == '*')
        return 2;

    if (op == '/')
        return 2;

    return 0;
}

void addNumberToArray(int number, char arr[], int& index)
{
    if (number == 0)
    {
        arr[index++] = '0';
        return;
    }

    char digits[20];
    int count = 0;

    while (number > 0)
    {
        digits[count++] = (number % 10) + '0';
        number = number / 10;
    }

    for (int i = count - 1; i >= 0; i--)
    {
        arr[index++] = digits[i];
    }
}

void generateSeries(int n, char expression[])
{
    int index = 0;

    for (int i = 1; i <= n; i++)
    {
        int term = 3 * i - 2;

        addNumberToArray(term, expression, index);

        if (i != n)
        {
            expression[index++] = '+';
        }
    }

    expression[index] = '\0';
}

void infixToPostfix(char infix[], char postfix[])
{
    Stack s;

    int i = 0;
    int j = 0;

    while (infix[i] != '\0')
    {
        char c = infix[i];

        if (c >= '0' && c <= '9')
        {
            while (infix[i] >= '0' && infix[i] <= '9')
            {
                postfix[j++] = infix[i];
                i++;
            }

            postfix[j++] = ' ';
            continue;
        }

        if (c == '+')
        {
            while (!s.empty() && precedence(s.peek()) >= precedence(c))
            {
                postfix[j++] = s.pop();
                postfix[j++] = ' ';
            }

            s.push(c);
        }

        i++;
    }

    while (!s.empty())
    {
        postfix[j++] = s.pop();
        postfix[j++] = ' ';
    }

    postfix[j] = '\0';
}

void infixToPrefix(char infix[], char prefix[])
{
    Stack s;

    char temp[500];

    int i = 0;
    int j = 0;

    while (infix[i] != '\0')
    {
        if (infix[i] >= '0' && infix[i] <= '9')
        {
            while (infix[i] >= '0' && infix[i] <= '9')
            {
                temp[j++] = infix[i];
                i++;
            }

            temp[j++] = ' ';
            continue;
        }

        if (infix[i] == '+')
        {
            s.push('+');
        }

        i++;
    }

    int k = 0;
    int operators = 0;

    while (!s.empty())
    {
        s.pop();
        operators++;
    }

    for (int i = 0; i < operators; i++)
    {
        prefix[k++] = '+';
        prefix[k++] = ' ';
    }

    int p = 0;

    while (temp[p] != '\0')
    {
        prefix[k++] = temp[p++];
    }

    prefix[k] = '\0';
}

int main()
{
    int n;

    cout << "Enter number of terms: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Invalid number of terms." << endl;
        return 0;
    }

    char expression[500];
    char postfix[500];
    char prefix[500];

    generateSeries(n, expression);

    infixToPostfix(expression, postfix);
    infixToPrefix(expression, prefix);

    cout << endl;

    cout << "Series: ";

    int i = 0;

    while (expression[i] != '\0')
    {
        if (expression[i] == '+')
            cout << " + ";
        else
            cout << expression[i];

        i++;
    }

    cout << endl;

    cout << "Postfix: ";
    cout << postfix << endl;

    cout << "Prefix: ";
    cout << prefix << endl;

    return 0;
}