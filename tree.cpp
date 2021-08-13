#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

#define ln "\n"
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define f(i, a, b) for (int i = a; i < b; i++)

class node
{

public:
    int data;
    node *left;
    node *right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
node *takeInput()
{
    queue<node *> q;
    int n;
    cin >> n;
    node *root = new node(n);
    q.push(root);
    while (!q.empty())
    {
        node *frnt = q.front();
        q.pop();
        int n1;
        cin >> n1;
        if (n1 == -1)
        {
            frnt->left = NULL;
        }
        else
        {
            frnt->left = new node(n1);
            q.push(frnt->left);
        }
        int n2;
        cin >> n2;
        if (n2 == -1)
        {
            frnt->right = NULL;
        }
        else
        {
            frnt->right = new node(n2);
            q.push(frnt->right);
        }
    }
    return root;
}
void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void deleteLeafNode(node *&root)
{
    if(root == NULL) return;
    if ((root->left == NULL) && (root->right == NULL))
    {
        root = NULL;
        return;
    }

    deleteLeafNode(root->left);
    deleteLeafNode(root->right);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    node *root = takeInput();
    deleteLeafNode(root);
    inorder(root);
    return 0;
}