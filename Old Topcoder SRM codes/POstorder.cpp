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

  vector<int> postorderTraversal(TreeNode *root)
   {
        stack< TreeNode* > st;

        vector<int> ans;

        if( root == NULL)
             return ans;

        stack<int> rev;

        st.push(root);

        while( !st.empty() )
        {
            TreeNode* curr=st.top() ; st.pop();

            rev.push( curr->val);

            if( curr->right != NULL )
            {
                st.push(curr->right);
            }

            if( curr->left !=NULL )
            {
                st.push( curr->left );
            }

        }

        while( !rev.empty() )
        {
            ans.push_back( rev.top() );
            rev.pop();
        }

        return ans;


    }
};


int main()
{
    return 0;
}
