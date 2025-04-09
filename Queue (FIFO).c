// A C program to demonstrate linked list based implementation of pageFrame
#include <stdio.h>
#include <stdlib.h>

int pageFault, pageFrame_size, count = 0;

// A linked list (LL) node to store a pageFrame entry
typedef struct page
{
	int pageReference;
	struct page* nextPage;
}page;

page *front = NULL, *rear = NULL;

// A utility function to create a new linked list node.
struct page* newPage(int k)
{
	struct page* temp = (struct page*)malloc(sizeof(struct page));
	temp->pageReference = k;
	temp->nextPage = NULL;
	return temp;
}

// The function to add a pageReference k to pf
void enqueue(int k)
{
	// Create a new LL node
	struct page* temp = newPage(k);
	// If pageFrame is empty, then new node is front and rear both
	if (rear == NULL)
    {
		front = rear = temp;
		temp->nextPage = NULL;
		return;
	}

	// Add the new node at the end of pageFrame and change rear
	rear->nextPage = temp;
	rear = temp;
	temp->nextPage = NULL;
}

void display()
{
    page *temp;
    if(rear == NULL)
    {
        printf("Page frame is empty\n");
        return;
    }
    if(rear == front)
    {
        printf("%d", rear->pageReference);
        printf("\n");
        return;
    }
    temp = front;
    do
    {
        printf("%d ", temp->pageReference);
        temp = temp->nextPage;
    }while(temp != rear);
    printf("%d", temp->pageReference);
    printf("\n");
}

void fifo(int n)    //input n taken from user
{
    int i;
    page *temp;
    page *ptr = front;
    do
    {
        if(n == ptr->pageReference)
        {
            display();
            printf("HIT\n");
            return;
        }
        ptr = ptr->nextPage;
    }while(ptr != NULL);
    display();
    printf("MISS\n");
    if(count == 0)
    {
        front->pageReference = n;
    }
    else
    {
        for(i = 0, temp = front; i < count; i++, temp = temp->nextPage);
        temp->pageReference = n;
    }
    count++;
    if(count == pageFrame_size)
    {
        count = 0;
    }
    display();
    pageFault++;
    return;
}

// Driver Program to test above functions
int main()
{
    pageFault = pageFrame_size = 0;
    int n, i=0;
    printf("Enter the page frame size: ");
    scanf("%d", &pageFrame_size);
	while(1)
    {
        printf("Enter the reference number (-1 to terminate): ");
        scanf("%d", &n);
        if(n == -1)
           break;
        if(i < pageFrame_size)
        {
            printf("MISS \n");
            pageFault++;
            enqueue(n);
            display();
            i++;
        }
        else
        {
            fifo(n);
        }
    }
    printf("Total number of page faults = %d\n", pageFault);
    printf("\n");
    return 0;
}
