#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int queue[n];
    int stack[n];
    int i, top = -1;

    // Input queue elements
    for(i = 0; i < n; i++)
    {
        scanf("%d", &queue[i]);
    }

    // Step 1: Push queue elements into stack
    for(i = 0; i < n; i++)
    {
        stack[++top] = queue[i];
    }

    // Step 2: Pop from stack back to queue (reversed)
    for(i = 0; i < n; i++)
    {
        queue[i] = stack[top--];
    }

    // Print reversed queue
    for(i = 0; i < n; i++)
    {
        printf("%d ", queue[i]);
    }

    return 0;
}