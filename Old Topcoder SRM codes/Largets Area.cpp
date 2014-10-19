
#include<iostream>
using namespace std;
#include<vector>
#include<stack>

#define pb push_back

int largestRectArea(vector<int> h)
 {
    stack<int> p;
    int i = 0, m = 0;
    h.push_back(0);
    while(i < h.size()) {
        if(p.empty() || h[p.top()] <= h[i])
            p.push(i++);
        else {
            int t = p.top();
            p.pop();
            m = max(m, h[t] * (p.empty() ? i : i - p.top() - 1 ));
        }
    }
    return m;
}

int main()
{

   vector<int> tp;
   tp.pb(10); tp.pb(11); tp.pb(9) ; tp.pb(1) ; tp.pb(1);

   cout<<largestRectArea(tp)<<endl;

   return 0;

}
