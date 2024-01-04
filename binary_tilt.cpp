#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
    public:
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }

};
class Solution {
public:
    int sum = 0;
    int find(TreeNode* root)
    {
        if(root == NULL) return 0;

        int l = find(root->left);
        int r = find(root->right);

        sum += abs(l-r);
        return l+r+root->val;
    }
    int findTilt(TreeNode* root) {
       find(root);
       return sum;
    }
};
int main(){
    
    return 0;
}