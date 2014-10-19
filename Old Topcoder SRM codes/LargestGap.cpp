#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <fstream>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <map>
#include <set>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz size()
#define bg begin()
#define en end()
#define Y second
#define X first
typedef long long ll;

#define fi freopen("input.txt","r",stdin)
#define fo freopen("output.txt","w",stdout)

const double pi     =   acos(-1.0);
const double eps    =   1e-8;

#define print(a) cout<<(#a)<<" = "<<a<<"  ";
#define println(a) cout<<(#a)<<" = "<<a<<"\n";
#define fill(a,val) memset(a ,val, sizeof(a) );

vector <string> parse(string s, string c)
{
  int len = c.length(), p = -len, np;
  vector <string> ans;

  do
    {
      np = s.find(c, p+len);
      ans.push_back(s.substr(p+len, np - p - len));
      p = np;
    }
  while (p != string::npos);

  return ans;
}


/*Solution code starts here */

class LargestGap
{
public:


int getLargest(vector <string> board)
{
	string in="";

	for(int i=0;i<board.sz;i++) in+=board[i];

    int n=in.sz;

	vector<int> S,G,temp;

	int i=0;

	while(i<n)
    {
           if( in[i]=='X')
           {
                S.pb(i);
                int curr=0;

                while(i<n && in[i]=='X')
                     {i++; curr++;
                     }

                     temp.pb(-curr);
           }
          else
          {
                int curr=0;
                while(i<n && in[i]=='.')
                {
                    i++; curr++;
                }
                temp.pb(curr);
                G.pb(curr);
          }
    }

    if( temp.front()<0 && temp.back()>0 )
    {
        rotate( G.bg,G.en -1 , G.en);
    }
   else if( temp.front()<0 && temp.back()<0)
   {
       S.pop_back();
       rotate( G.bg,G.en -1 , G.en);
   }
   else if(temp.front()>0 && temp.back()>0)
   {
        G.front()+=G.back();
        G.pop_back();
   }


   n=S.size();

   int ans=S[0];
   int ba=min( G[0],G[1]) , bb=max( G[0],G[1]);

   for(int i=1;i<n;i++)
   {
        int a=min( G[i] , G[ (i+1)%n ]);
        int b=max( G[i] , G[ (i+1)%n ]);

        if(a+b < ba + bb)  continue;

        if( a+b > ba+bb )
        {
            ba=a; bb=b; ans=S[i];
        }

        if(b>bb) continue;

        if( b < bb)
         {
            ba=a; bb=b; ans=S[i];
         }

        if( a > ba) continue;

         if(a < ba)
         {
            ba=a; bb=b; ans=S[i];
         }
   }

      return ans;

}

};


double test0() {
	string t0[] = {".....X.X......."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	LargestGap * obj = new LargestGap();
	clock_t start = clock();
	int my_answer = obj->getLargest(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 5;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	string t0[] = {"XXXX","....","XXXX","....","XXXX","...."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	LargestGap * obj = new LargestGap();
	clock_t start = clock();
	int my_answer = obj->getLargest(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	string t0[] = {"XXX.........XX...........XX..X"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	LargestGap * obj = new LargestGap();
	clock_t start = clock();
	int my_answer = obj->getLargest(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 12;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	string t0[] = {"XXX","X.....","....XX..XXXXXX","X........X..",".XXX."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	LargestGap * obj = new LargestGap();
	clock_t start = clock();
	int my_answer = obj->getLargest(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 32;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

int main() {
	int time;
	bool errors = false;
	
	time = test0();
	if (time < 0)
		errors = true;
	
	time = test1();
	if (time < 0)
		errors = true;
	
	time = test2();
	if (time < 0)
		errors = true;
	
	time = test3();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
