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
Node * inputTree()
{
    int val;
    cin >> val;
    Node * root;

    if(val == -1) 
        root = NULL;
    else 
        root = new Node(val);

    queue<Node*> q;
    if(root) q.push(root);

    while(!q.empty())
    {
      //1* ber kore ano
      Node * f = q.front();
      q.pop();

      //2*jabotiyo kaj   
      int l,r;
      cin >>l>>r;

      Node * myLeft;
      Node * myRight;
      if(l == -1) 
        myLeft = NULL;
      else 
        myLeft = new Node(l);
      if(r == -1) 
        myRight = NULL;
      else 
        myRight = new Node(r);

      f->left = myLeft;
      f->right = myRight;
    // 10 20 60 30 50 70 -1 -1 40 -1 -1 -1 -1 80 -1 -1 -1

      //3* children gulo ber kore ano
      if(f->left) q.push(f->left);
      if(f->right) q.push(f->right);
    }
    return root;

}
void levelOrder(Node * root)
{
    if(root == NULL)
    {
        cout << "tree nai" << endl;
        return;
    } 
    // int cnt = 1;
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
        if(f->left != NULL)
        {
            q.push(f->left);
            // cnt++;
        }
        if(f->right != NULL)
        {
            q.push(f->right);
            // cnt++;
        }
    }
    // cout << "total nodes = " << cnt << endl;
}
int main(){
    Node * root = inputTree();
    levelOrder(root);
    return 0;
}