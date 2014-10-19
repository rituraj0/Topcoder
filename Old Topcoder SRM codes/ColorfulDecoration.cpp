#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define bg begin()
#define en end()
#define Y second
#define X first
typedef long long ll;

#define fi freopen("input.txt","r",stdin)
#define fo freopen("output.txt","w",stdout)

const double pi     =   acos(-1.0);
const double eps    =   1e-8;

#define print(a) cout<<(#a)<<" = "<<a<<"\n";
#define fill(a,val) memset(a ,val, sizeof(a) );
#define sz(s) ((int)(s.size()))

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

class ColorfulDecoration
{
public:

int getMaximum(vector <int> xa, vector <int> ya, vector <int> xb, vector <int> yb)
{
    int n=sz(xa);

    ll lo=0,hi=(1LL<<60);

    ll ans=0;

    while(lo<=hi)
    {
        ll mid=(lo+hi)/2;

        bool dp[110][110]; fill(dp,0);
//      http://stackoverflow.com/questions/1663104/algorithm-for-2-satisfiability-problem
//        If you have n variables and m clauses:
//         Create a graph with 2n vertices: intuitively, each vertex resembles a true
//         or not true literal for each variable. For each clause (a v b), where a and
//         b are literals, create an edge from !a to b and from !b to a. These edges mean
//         that if a is not true, then b must be true and vica-versa.
//         Once this digraph is created, go through the graph and see if there
//         is a cycle that contains both a and !a for some variable a.
//         If there is, then the 2SAT is not satisfiable (because a implies !a and vica-versa).
//          Otherwise, it is satisfiable, and this can even give you a satisfying assumption
//          (pick some literal a so that a doesn't imply !a, force all implications from there, repeat).
//           You can do this part with any of your standard graph algorithms, ala Breadth-First Search ,
//           Floyd-Warshall, or any algorithm like these, depending on how sensitive you are to the time complexity of your algorithm.
//

        for(int i=0;i<2*n;i++)
          {
              int x1=(i>=n)?xb[i-n]:xa[i];
              int y1=(i>=n)?yb[i-n]:ya[i];

              for(int j=0;j<2*n;j++)
              {
                  if(i==j) continue;

                  int x2=(j>=n)?xb[j-n]:xa[j];
                  int y2=(j>=n)?yb[j-n]:ya[j];

                   if( (llabs(x1-x2)<mid)&&(llabs(y1-y2)<mid) )
                    dp[i][ (j>=n)?(j-n):j+n]=true;
              }
            }

          for(int k=0;k<2*n;k++)
            for(int i=0;i<2*n;i++)
              for(int j=0;j<2*n;j++)
                if( dp[i][k]&&dp[k][j])
                  dp[i][j]=true;

          bool cool=true;

          for(int i=0;i<n;i++)
             if( dp[i][i+n]&&dp[i+n][i])
               cool=false;

          if(cool)
          {
              lo=mid+1;
              ans=mid;
          }
         else
         {
            hi=mid-1;
         }
    }

   return ans;
}
};


double test0() {
	int t0[] = { 10,  0,  7 };
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {  0, 19,  6 };
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = { 20, 10, 25 };
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = { 20, 35, 25 };
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	ColorfulDecoration * obj = new ColorfulDecoration();
	clock_t start = clock();
	int my_answer = obj->getMaximum(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 19;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int t0[] = { 464, 20 };
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = { 464, 10 };
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = { 464,  3 };
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = { 464, 16 };
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	ColorfulDecoration * obj = new ColorfulDecoration();
	clock_t start = clock();
	int my_answer = obj->getMaximum(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 461;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int t0[] = { 0, 0, 1, 1 };
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = { 0, 0, 1, 1 };
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = { 1, 1, 0, 0 };
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = { 1, 1, 0, 0 };
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	ColorfulDecoration * obj = new ColorfulDecoration();
	clock_t start = clock();
	int my_answer = obj->getMaximum(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int t0[] = { 0, 3, 0, 5, 6 };
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = { 1, 6, 0, 8, 5 };
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = { 6, 1, 7, 4, 7 };
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = { 5, 9, 2, 8, 9 };
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	ColorfulDecoration * obj = new ColorfulDecoration();
	clock_t start = clock();
	int my_answer = obj->getMaximum(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 3;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	int t0[] = { 1000000000, 0 };
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = { 0, 1000000000 };
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = { 0, 1000000000 };
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = { 0, 1000000000 };
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	ColorfulDecoration * obj = new ColorfulDecoration();
	clock_t start = clock();
	int my_answer = obj->getMaximum(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 1000000000;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
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

	time = test4();
	if (time < 0)
		errors = true;

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
