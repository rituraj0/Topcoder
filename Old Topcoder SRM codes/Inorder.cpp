#include<iostream>
using namespace std;
#include<vector>
#include<stack>


  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:

   vector<int> inorderTraversal(TreeNode *root)
   {
        stack< TreeNode* > st;
        TreeNode* temp=root;

        vector<int> ans;

        if( temp==NULL)
             return ans;

        while( ( !st.empty() ) || (temp!=NULL) )
         {
            if( temp==NULL)
            {
                temp=st.top(); st.pop();
                ans.push_back(temp->val);
                temp=temp->right;
            }
           else
           {
                st.push( temp );
                temp=temp->left;
           }

         }

        return ans;


    }
};


int main()
{
    return 0;
}
