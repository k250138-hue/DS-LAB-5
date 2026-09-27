#include <iostream>
using namespace std;

class Stack
{
public:
    int top;
    int arr[100];

    Stack()
    {
        top = -1;
    }

    void push(int data)
    {
        arr[++top] = data;
    }

    bool isEmpty()
    {
        return top == -1;
    }
};

class Node
{
public:
    int data;
    Node* next;

    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

class LinkStack
{
public:
    Node* head;

    LinkStack()
    {
        head = NULL;
    }

    void insertEnd(int data)
    {
        Node* newNode = new Node(data);

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node* temp = head;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }

    void display()
    {
        Node* temp = head;

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    void sort()
    {
        if (head == NULL)
        {
            return;
        }

        Node* current = head;

        while (current != NULL)
        {
            Node* minNode = current;
            Node* temp = current->next;

            while (temp != NULL)
            {
                if (temp->data < minNode->data)
                {
                    minNode = temp;
                }

                temp = temp->next;
            }

            int value = current->data;
            current->data = minNode->data;
            minNode->data = value;

            current = current->next;
        }
    }


    int copyToArray(int arr[])
    {
        Node* temp = head;
        int count = 0;

        while (temp != NULL)
        {
            arr[count] = temp->data;
            count++;

            temp = temp->next;
        }

        return count;
    }
};

class CircularQueue
{
public:
    int arr[100];
    int front;
    int rear;
    int size;

    CircularQueue()
    {
        front = -1;
        rear = -1;
        size = 0;
    }

    void enqueue(int data)
    {
        if (size == 100)
        {
            cout << "Queue is Full!" << endl;
            return;
        }

        if (front == -1)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear = (rear + 1) % 100;
        }

        arr[rear] = data;
        size++;
    }

    void display()
    {
        if (size == 0)
        {
            cout << "Queue is Empty!" << endl;
            return;
        }

        cout << "Circular Queue: ";

        int index = front;

        for (int i = 0; i < size; i++)
        {
            cout << arr[index] << " ";

            index = (index + 1) % 100;
        }

        cout << endl;
    }
};

int main()
{
    Stack s1;
    Stack s2;

    int n1, n2;

    cout << "Enter number of elements for Stack 1: ";
    cin >> n1;

    cout << "Enter elements of Stack 1 (bottom to top):" << endl;

    for (int i = 0; i < n1; i++)
    {
        int value;
        cin >> value;

        s1.push(value);
    }

    cout << "Enter number of elements for Stack 2: ";
    cin >> n2;

    cout << "Enter elements of Stack 2 (bottom to top):" << endl;

    for (int i = 0; i < n2; i++)
    {
        int value;
        cin >> value;

        s2.push(value);
    }

    cout << endl;

    cout << "Stack 1: ";

    for (int i = 0; i <= s1.top; i++)
    {
        cout << s1.arr[i] << " ";
    }

    cout << endl;


    cout << "Stack 2: ";

    for (int i = 0; i <= s2.top; i++)
    {
        cout << s2.arr[i] << " ";
    }

    cout << endl;


    LinkStack thirdStack;

    int index1 = 0;
    int index2 = 0;


    while (index1 <= s1.top && index2 <= s2.top)
    {
        // Take from Stack 1
        thirdStack.insertEnd(s1.arr[index1]);
        index1++;

        // Take from Stack 2
        thirdStack.insertEnd(s2.arr[index2]);
        index2++;
    }

    while (index1 <= s1.top)
    {
        thirdStack.insertEnd(s1.arr[index1]);
        index1++;
    }

    while (index2 <= s2.top)
    {
        thirdStack.insertEnd(s2.arr[index2]);
        index2++;
    }

    cout << endl;

    cout << "Third Stack before sorting: ";
    thirdStack.display();

    thirdStack.sort();

    cout << "Third Stack after sorting: ";
    thirdStack.display();

    CircularQueue queue;

    Node* temp = thirdStack.head;

    while (temp != NULL)
    {
        queue.enqueue(temp->data);
        temp = temp->next;
    }


    cout << endl;

    queue.display();


    return 0;
}