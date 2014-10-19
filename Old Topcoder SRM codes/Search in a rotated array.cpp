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
        int search(int A[], int n, int target)
        {
            int ans=-1;

             int lo=0,hi=n-1;

             while(lo <= hi)
             {
                 int mid=(lo+hi)/2;

                 if( A[mid]==target)
                 {
                     return mid;
                 }

                 if( A[lo] <= A[mid] )//left part is sorted
                 {
                    if( A[lo]<= target && target <= A[mid] )
                    {
                        hi=mid-1;
                    }
                    else
                    {
                        lo=mid+1;
                    }
                 }
               else//right part is sorted
                {

                    if( A[mid] <= target && target <= A[hi] )
                    {
                        lo=mid+1;
                    }
                    else
                    {
                        hi=mid-1;
                    }
                }

             }

             return -1;

        }
};

int main()
{
    return 0;
}
