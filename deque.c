#include <stdio.h>

#define SIZE 5

int data[SIZE];
int left = -1, right = -1;

int fullDeque()
{
    return ((left == 0 && right == SIZE - 1) || (left == right + 1));
}

int emptyDeque()
{
    return (left == -1);
}

void addFront(int item)
{
    if (fullDeque())
    {
        printf("Deque is Full!\n");
        return;
    }

    if (left == -1)
        left = right = 0;
    else if (left == 0)
        left = SIZE - 1;
    else
        left--;

    data[left] = item;
    printf("%d inserted at front.\n", item);
}

void addRear(int item)
{
    if (fullDeque())
    {
        printf("Deque is Full!\n");
        return;
    }

    if (left == -1)
        left = right = 0;
    else if (right == SIZE - 1)
        right = 0;
    else
        right++;

    data[right] = item;
    printf("%d inserted at rear.\n", item);
}

void removeFront()
{
    if (emptyDeque())
    {
        printf("Deque is Empty!\n");
        return;
    }

    printf("%d removed from front.\n", data[left]);

    if (left == right)
        left = right = -1;
    else if (left == SIZE - 1)
        left = 0;
    else
        left++;
}

void removeRear()
{
    if (emptyDeque())
    {
        printf("Deque is Empty!\n");
        return;
    }

    printf("%d removed from rear.\n", data[right]);

    if (left == right)
        left = right = -1;
    else if (right == 0)
        right = SIZE - 1;
    else
        right--;
}

void showDeque()
{
    if (emptyDeque())
    {
        printf("Deque is Empty!\n");
        return;
    }

    int pos = left;
    printf("Deque: ");

    while (1)
    {
        printf("%d ", data[pos]);

        if (pos == right)
            break;

        pos = (pos + 1) % SIZE;
    }

    printf("\n");
}

int main()
{
    int option, num;

    while (1)
    {
        printf("\n1.Insert Front\n");
        printf("2.Insert Rear\n");
        printf("3.Delete Front\n");
        printf("4.Delete Rear\n");
        printf("5.Display\n");
        printf("6.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &num);
            addFront(num);
            break;

        case 2:
            printf("Enter value: ");
            scanf("%d", &num);
            addRear(num);
            break;

        case 3:
            removeFront();
            break;

        case 4:
            removeRear();
            break;

        case 5:
            showDeque();
            break;

        case 6:
            return 0;

        default:
            printf("Invalid Choice!\n");
        }
    }

    return 0;
}
