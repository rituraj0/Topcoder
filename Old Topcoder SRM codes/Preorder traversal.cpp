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
    vector<int> preorderTraversal(TreeNode *root)
    {
        stack< TreeNode* > st;


        vector<int> ans;

        st.push(root);

       while( !st.empty() )
        {
                TreeNode* curr=st.top() ; st.pop();

                if( curr == NULL)
                  continue;

                ans.push_back( curr->val );
                //ans.push_back( (*curr).val );  // both are fine

                if( curr->right!= NULL)
                {
                    st.push( curr->right);
                }

                if( curr->left!=NULL)
                {
                    st.push( curr->left);
                }

        }

        return ans;


    }
};


int main()
{
    return 0;
}
