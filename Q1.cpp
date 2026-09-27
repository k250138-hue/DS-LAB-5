#include <iostream>
using namespace std;

class Stack
{
public:
    int arr[100];
    int top;

    Stack()
    {
        top = -1;
    }

    void push(int data)
    {
        if (top == 99)
        {
            cout << "Stack Overflow\n";
            return;
        }

        top++;
        arr[top] = data;
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow\n";
            return;
        }

        cout << arr[top] << " Is Eliminated\n";
        top--;
    }

    void maximum()
    {
        if (top == -1)
        {
            cout << "Stack is Empty\n";
            return;
        }
        int max = arr[top];
        for (int i = top - 1; i >= 0; i--)
        {
            if (max < arr[i])
            {
                max = arr[i];
            }
        }
        cout << max << " is the maximun Number\n";
    }

    void minimum()
    {
        if (top == -1)
        {
            cout << "No bottom...\nIt is Empty\n";
            return;
        }

        int min = arr[top];
        for (int i = top - 1; i >= 0; i--)
        {
            if (min > arr[i])
            {
                min = arr[i];
            }
        }
        cout << min << " is the minimum Number\n";
    }

    void middle()
    {
        int n = top + 1;
        int mid;

        if (n == 0)
        {
            cout << "Stack is Empty\n";
            return;
        }

        if (n % 2 == 0)
        {
            int mid1 = (n / 2) - 1;
            int mid2 = n / 2;

            cout << arr[mid1] << " and "
                 << arr[mid2]
                 << " are the middle elements\n";
        }
        else
        {
            mid = n / 2;

            cout << arr[mid]
                 << " is the middle element\n";
        }
    }
};

int main()
{
    Stack s;
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements from bottom to top:" << endl;

    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;

        s.push(value);
    }

    s.maximum();
    s.middle();
    s.minimum();

    return 0;
}