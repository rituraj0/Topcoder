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
#define Y second
#define X first

#define fi freopen("input.txt","r",stdin)
#define fo freopen("output.txt","w",stdout)

const double pi     =   acos(-1.0);
const double eps    =   1e-8;

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

class CsCourses
{
public:

    vector<int> theoreticalValue , practicalValue , expire;
    int skillBound,n;

    pair<bool,vector<int> > memo[55][55][55];
    bool done[55][55][55];

    bool less( int a, int b)
    {
        if( (theoreticalValue[a] < theoreticalValue[b]) || ( practicalValue[a] < practicalValue[b]) )
            return true;

            return false;
    }

    vector<int> mini( vector<int> a , vector<int> b)
    {
         if( a.size() < b.size())
             return a;

         if( a.size() > b.size())
             return b;

          for(int i=0;i<a.size();i++)
              if( a[i] < b[i])
                return a;
               else if( a[i] > b[i])
                 return b;

           return a;
    }

    pair<bool,vector<int> > solve( int cm , int thor , int prac)
    {

            vector<int> ret;

          if( (thor >=skillBound ) && (prac>=skillBound) )
               {
                   return mp(true,ret);
               }

            if( cm==n)
            {
               return mp(false,ret);
            }

        if( done[cm][thor][prac] )
            return memo[cm][thor][prac];

        vector<int> select;
        bool poss=false;

        for(int i=0;i<n;i++)
             if( cm < expire[i]  )
                if( (thor < theoreticalValue[i] ) || (prac < practicalValue[i]) )
                     if( (thor+1 >= theoreticalValue[i] ) && (prac+1 >=practicalValue[i]) )
                {
                     int nt=max( thor , theoreticalValue[i]);
                     int np=max( prac , practicalValue[i] );

                     pair<bool , vector<int> > temp=solve( cm+1,nt,np);

                      if( temp.X==true)
                      {
                          temp.Y.insert( temp.Y.begin() ,i);

                          if(! poss)
                          {
                                select=temp.Y;
                                poss=true;
                          }
                         else
                         {
                            select=mini(select,temp.Y);
                         }

                      }
                }

                done[cm][thor][prac]=true;

                return memo[cm][thor][prac]=mp( poss, select);
    }

vector <int>  getOrder(vector <int> theoreticalValue, vector <int> practicalValue, vector <int> expire, int skillBound)
{

    n=practicalValue.size();

    this->theoreticalValue=theoreticalValue;
    this->practicalValue= practicalValue;
    this->expire=expire;

        this->skillBound=skillBound;

    memset( done , 0 , sizeof(done));


    pair<bool , vector<int> >ans= solve(0,0,0);//n-1 selected


    if( ans.X)
        return ans.Y;

     vector<int> emp;
     return emp;


}

};


double test0() {
	int t0[] = {1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {1};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int p3 = 1;
	CsCourses * obj = new CsCourses();
	clock_t start = clock();
	vector <int> my_answer = obj->getOrder(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t4[] = {0 };
	vector <int> p4(t4, t4+sizeof(t4)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p4.size() > 0) {
		cout <<p4[0];
		for (int i=1; i<p4.size(); i++)
			cout <<", " <<p4[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p4) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int t0[] = {1, 2, 1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {2, 1, 1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {5, 5, 5};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int p3 = 2;
	CsCourses * obj = new CsCourses();
	clock_t start = clock();
	vector <int> my_answer = obj->getOrder(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t4[] = {2, 0, 1 };
	vector <int> p4(t4, t4+sizeof(t4)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p4.size() > 0) {
		cout <<p4[0];
		for (int i=1; i<p4.size(); i++)
			cout <<", " <<p4[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p4) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int t0[] = {1, 2, 1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {2, 1, 1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {1, 1, 1};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int p3 = 2;
	CsCourses * obj = new CsCourses();
	clock_t start = clock();
	vector <int> my_answer = obj->getOrder(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	vector <int> p4;
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p4.size() > 0) {
		cout <<p4[0];
		for (int i=1; i<p4.size(); i++)
			cout <<", " <<p4[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p4) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int t0[] = {1, 2, 1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {2, 1, 1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {3, 2, 1};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int p3 = 2;
	CsCourses * obj = new CsCourses();
	clock_t start = clock();
	vector <int> my_answer = obj->getOrder(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t4[] = {2, 1, 0 };
	vector <int> p4(t4, t4+sizeof(t4)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p4.size() > 0) {
		cout <<p4[0];
		for (int i=1; i<p4.size(); i++)
			cout <<", " <<p4[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p4) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	int t0[] = {1, 2, 3, 4, 5, 6, 7};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1, 2, 3, 4, 5, 6, 7};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {1, 2, 3, 4, 5, 6, 7};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int p3 = 7;
	CsCourses * obj = new CsCourses();
	clock_t start = clock();
	vector <int> my_answer = obj->getOrder(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t4[] = {0, 1, 2, 3, 4, 5, 6 };
	vector <int> p4(t4, t4+sizeof(t4)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p4.size() > 0) {
		cout <<p4[0];
		for (int i=1; i<p4.size(); i++)
			cout <<", " <<p4[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p4) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test5() {
	int t0[] = {0, 1, 2, 2, 1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {0, 0, 1, 2, 1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {9, 9, 9, 9, 9};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int p3 = 2;
	CsCourses * obj = new CsCourses();
	clock_t start = clock();
	vector <int> my_answer = obj->getOrder(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t4[] = {4, 3 };
	vector <int> p4(t4, t4+sizeof(t4)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p4.size() > 0) {
		cout <<p4[0];
		for (int i=1; i<p4.size(); i++)
			cout <<", " <<p4[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p4) {
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

	time = test5();
	if (time < 0)
		errors = true;

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
