#include<stdio.h>
#include<stdlib.h>

int pageFault, pageFrame_size;   //global variables


typedef struct page
{
    int pageReference;
    int visited;
    struct page *nextPage;
}page;

page *front = NULL, *rear = NULL;
int pageFault,pageFrame_Size;

struct page* newPage(int k)
{
	struct page* temp = (struct page*)malloc(sizeof(struct page));
	temp->pageReference = k;
	temp->visited = 0;
	temp->nextPage = NULL;
	return temp;
}

void insert(int k)
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

void lru(int n)
{
    page *ptr;
    int min = front->visited;
    for(ptr = front; ptr != NULL; ptr = ptr->nextPage)
    {
        if(n == ptr->pageReference)
        {
            display();
            printf("HIT\n");
            ptr->visited++;
            return;
        }
    }
    ptr = front;
    do
    {
        if(ptr->visited < min)
            min = ptr->visited;
        ptr = ptr->nextPage;
    }while(ptr != NULL);
    ptr = front;
    while(ptr->visited != min)
        ptr = ptr->nextPage;
    display();
    ptr->pageReference = n;
    printf("MISS\n");
    display();
    //display queue
    pageFault++;
}

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
            insert(n);
            display();
            i++;
        }
        else
        {
            lru(n);
        }
    }
    printf("\n");
    printf("Total number of page faults = %d\n", pageFault);
    return 0;
}
