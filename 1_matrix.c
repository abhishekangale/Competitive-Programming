#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#define initial 1
#define waiting 2
#define visited 3
int n;
int adj[100][100];
int state[10];
int visit[100];
void BF_traversal();
void bfs(int);
void dfs(int);
int queue[MAX],front=-1,rear=-1;
void enqueue(int ver);
int dequeue();
int isEmpty_queue();
int main()
{
    int i,j,ch;
    printf("enter the no. of vertices\n");
    scanf("%d",&n);
    printf("enter adjacency matrix\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&adj[i][j]);
        }
    }
    printf("The adjacency matrix representation:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d",adj[i][j]);
        }
        printf("\n");
    }
    for(i=0;i<n;i++)
    {
        visit[i]=0;
    }

    do
    {

        printf("Traversing methods:\n1.Breadth first serach\n2.Depth first search\nenter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            BF_traversal();
            break;
        case 2:
             printf("enter the starting vertex\n");
             scanf("%d",&j);
             dfs(j);
        case 3:
            exit(0);
        }
    }while(ch<=2);

    return 0;
}
void enqueue(int ver)
{
    if(rear==MAX-1)
        printf("overflow\n");
    else
    {
        if(front==-1)
            front=0;
        rear=rear+1;
        queue[rear]=ver;
    }
}
int isEmpty_queue()
{
    if(front==-1 || front>rear)
      return 1;
    else
        return 0;
}
int dequeue()
{
    int item;
    if(front ==-1 ||front>rear)
    {
        printf("underflow\n");
        exit(1);
    }
    item=queue[front];
    front=front +1;
    return item;

}

void bfs(int v)
{
    int i;
    enqueue(v);
    state[v]=waiting;
    while(!isEmpty_queue())
    {
        v=dequeue();
        state[v]=visited;
        printf("visited vertex:%d\n",v);
        for(i=0;i<n;i++)
        {
            if(adj[v][i]==1 && state[i]==initial)
            {
                enqueue(i);
                state[i]=waiting;
            }
        }
    }
}
void BF_traversal()
{
    int v;
    for(v=0;v<n;v++)
        state[v]=initial;
    printf("enter the starting vertex\n");
    scanf("%d",&v);
    bfs(v);
}
void dfs(int v)
{
    int i;
    visit[v]=1;
    printf("visited node %d\n",v);
    for(i=0;i<n;i++)
    {
        if(visit[i]==0 && adj[v][i]==1)
        {
            dfs(i);
        }
    }
}
