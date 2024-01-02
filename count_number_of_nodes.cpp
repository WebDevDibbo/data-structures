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
int count(Node * root)
{
    if(root == NULL) return 0;
    int l = count(root->left);
    int r = count(root->right);
    return l+r+1;

}
int main(){
    Node * root = inputTree();
    cout << count(root) << endl;
    return 0;
}