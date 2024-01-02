#include <bits/stdc++.h>
using namespace std;
class Node
{
    public:
        int data;
        Node* left;
        Node* right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
void levelOrder(Node * root)
{
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        //first step --> line theke anoo
        Node * f = q.front();
        q.pop();

        //second step --> jabotiyo kajgulo koro
        cout << f->data << " ";

        //third step --> tar children gulo diye dao line e
        //! shortcut --> if(f->left)q.push(f->left);
        if(f->left != NULL)q.push(f->left);
        if(f->right != NULL)q.push(f->right);
    }
}
int main(){
    Node * root = new Node(10);
    Node * a = new Node(20);
    Node * b = new Node(30);
    Node * c = new Node(40);
    Node * d = new Node(50);
    Node * e = new Node(60);
    Node * f = new Node(70);
    Node * g = new Node(80);
    Node * h = new Node(90);
    Node * i = new Node(100);

    //connection
    root->left = a;
    root->right = b;
    a->left = c;
    a->right = h;
    b->right = d;
    c->right = e;
    d->left = f;
    d->right = g;
    h->right = i;

    levelOrder(root);
    return 0;
}