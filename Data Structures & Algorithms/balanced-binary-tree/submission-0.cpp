/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    pair<int,bool> solve(TreeNode* root){
        if(root==NULL){
            return {0,true};
        }
        pair<int,bool> left=solve(root->left);
        pair<int,bool> right=solve(root->right);
        pair<int,bool> ans;
        ans.first=max(left.first,right.first)+1;
        bool temp=abs(left.first-right.first)<=1;
        if(left.second && right.second && temp){
            ans.second=true;
        }
        else{
            ans.second=false;
        }
        return ans;
    }
    bool isBalanced(TreeNode* root) {
        return solve(root).second;
    }
};
