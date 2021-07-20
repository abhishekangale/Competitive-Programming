#include <stdio.h>
#include <stdlib.h>
#define MAX_Q_SIZE 500
#define SIZE 40

struct queue {
  int items[SIZE];
  int front;
  int rear;
};
struct queue* createQueue();
void enqueue(struct queue* q, int);
int dequeue(struct queue* q);
void display(struct queue* q);
int isEmpty(struct queue* q);

struct queue* createQueue() {
  struct queue* q = malloc(sizeof(struct queue));
  q->front = -1;
  q->rear = -1;
  return q;
}

int isEmpty(struct queue* q) {
  if (q->rear == -1)
    return 1;
  else
    return 0;
}

void enqueue(struct queue* q, int value) {
  if (q->rear == SIZE - 1)
    printf("\nQueue is Full!!");
  else {
    if (q->front == -1)
      q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
  }
}

int dequeue(struct queue* q) {
  int item;
  if (isEmpty(q)) {
    //printf("Queue is empty");
    item = -1;
  } else {
    item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
      //printf("Resetting queue ");
      q->front = q->rear = -1;
    }
  }
  return item;
}

struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct node *ptr,*root=NULL,*t=NULL,*pre,*temp;

void create(int x)
{
    ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=x;
    ptr->left=NULL;
    ptr->right=NULL;
}

void printLevelOrder(struct node* root)
{
    struct queue* q = createQueue();
    struct node *temp_node = root;
    while (temp_node)
    {
        printf("%d ", temp_node->data);

        /*Enqueue left child */
        if (temp_node->left)
            enqueue(q, temp_node->left);

        /*Enqueue right child */
        if (temp_node->right)
            enqueue(q, temp_node->right);

        //Dequeue node and make it temp_node
        temp_node = dequeue(q);
    }
}

void insert(struct node *rt,struct node *t)
{
    if(t->data < rt->data)
    {
        if(rt->left==NULL)
            rt->left=t;
        else
             insert(rt->left,t);
    }
    else if(t->data > rt->data)
    {
        if(rt->right==NULL)
            rt->right=t;
        else
            insert(rt->right,t);
    }
    else
        printf("Duplicate element not allowed in Binary Search tree!");
}

int search(struct node *t,int item)
{
   if(t->data==item)
       {
          return 0;
       }
   else if(item < t->data)
   {
       pre=t;
       return search( t->left,item);
   }
   else if(item > t->data)
   {
       pre=t;
       return search( t->right,item);
   }
   else return -1;
}

struct node * minValueNode(struct node* node)
{
    struct node* current = node;

    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

struct node* deleteNode(struct node* root, int key)
{
    // base case
    if (root == NULL) return root;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
        else if (key > root->data)
        root->right = deleteNode(root->right, key);
        else
        {
            // node with only one child or no child
            if (root->left == NULL)
            {
                struct node *temp = root->right;
                free(root);
                return temp;
            }
            else if (root->right == NULL)
            {
                struct node *temp = root->left;
                free(root);
                return temp;
            }

            // node with two children: Get the inorder successor (smallest
            // in the right subtree)
            struct node* temp = minValueNode(root->right);

            // Copy the inorder successor's content to this node
            root->data = temp->data;

            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->data);
        }
    return root;
}

int main()
{
  int ch,val;
  do
  {
      printf("\nEnter your choice\n1.Insertion\n2.Deletion\n3.Searching\n4.Level order Treversal\n5.Exit\n");
      scanf("%d",&ch);
      switch(ch)
      {
          case 1: printf("Enter the element:");
          scanf("%d",&val);
          create(val);
          temp=ptr;
            if(root==NULL)
            root=temp;
            else
                insert(root,temp);

          break;
          case 2:   printf("Enter the Node to be Deleted : ");
                    scanf("%d",&val);
                    root=deleteNode(root,val);
                break;
          case 3: printf("Enter the item to be searched:");
          scanf("%d",&val);
          pre=root;
          if(root->data==val)
          {
              printf("Element is the root of tree.");
          }
          else
            if(search(root,val) ==0 && root->data!=val)
            printf("Element found and is the child of %d.",pre->data);

          else{
            printf("Element not found.");
          }
          break;
          case 4:printf("Levelorder Traversal:");
               printLevelOrder(root);
          break;
          case 5: exit(0);
          default: printf("Incorrect choice!");
          break;
      }
  }while(ch<6);

}
