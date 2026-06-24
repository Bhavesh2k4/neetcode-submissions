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
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        int rightval;
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        int l=0;
        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
                TreeNode* top=q.front();
                q.pop();
                rightval=top->val;
                if(top->left){
                    q.push(top->left);
                }
                if(top->right){
                    q.push(top->right);
                }
            }
            ans.push_back(rightval);
            l++;
        }
        return ans;
    }
};
