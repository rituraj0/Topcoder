#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector
using namespace std;

bool myfunction (int i,int j) { return (i>j); }

int main () {

  vector<int> myvector ;               // 32 71 12 45 26 80 53 33

  sort (myvector.begin(), myvector.end(), myfunction); // 12 32 45 71(26 33 53 80)


  return 0;
}
