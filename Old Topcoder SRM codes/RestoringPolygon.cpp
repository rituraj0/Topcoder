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

#define pii pair<int,int>

class RestoringPolygon
{
public:

int  restore(vector <int> x1, vector <int> x2, vector <int> y)
{
     int n=x1.size();

    for(int i=0;i<n;i++)
          if( x1[i] > x2[i])
          swap(x1[i] , x2[i] );

    int ans=0;

    for(int mask=0;mask<(1<<n);mask++)
    {
        int cn=0;
        pair<pii,int> all[150];

         for(int j=0;j<n;j++)
              if( mask&(1<<j))
         {
             all[cn]=mp( mp(x1[j],y[j]) ,cn ) ;cn++;
             all[cn]=mp( mp(x2[j],y[j]) , cn); cn++;

         }

         bool cool=true;

         if( cn < 4)
            cool=false;

         sort( all , all+cn );

         int edge[150]; memset(edge,0,sizeof(edge));

         for(int j=0;j<cn;j+=2)
         {
                if( all[j].X.X!=all[j+1].X.X)
                    cool=false;

             for(int k=0;k<n;k++)
                if( mask&(1<<k) )
                {
                    if( x1[k] < all[j].X.X && all[j].X.X < x2[k] && all[j].X.Y < y[k] && y[k] < all[j+1].X.Y)
                        cool=false;
                }


                    edge[ all[j].Y ]=all[j+1].Y ;
                    edge[ all[j+1].Y ]= all[j].Y;
         }



             int temp=0,j;

             for(j=2; ;j+=2)
              {temp=edge[temp^1];
                if(temp==0)
                 break;
               }

               if(j!=cn)
                 cool=false;


        if(cool)
         ans=max( ans , cn);


    }

    return ans;

}

};


double test0() {
	int t0[] = {1,2,3,1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {2,3,5,5};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {1,4,2,0};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	RestoringPolygon * obj = new RestoringPolygon();
	clock_t start = clock();
	int my_answer = obj->restore(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 8;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int t0[] = {1,1,2,2};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {3,3,4,4};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {0,2,1,3};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	RestoringPolygon * obj = new RestoringPolygon();
	clock_t start = clock();
	int my_answer = obj->restore(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 4;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int t0[] = {1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {2};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {1};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	RestoringPolygon * obj = new RestoringPolygon();
	clock_t start = clock();
	int my_answer = obj->restore(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int t0[] = {0,0,0};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1000,1000,1000};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {0,1,2};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	RestoringPolygon * obj = new RestoringPolygon();
	clock_t start = clock();
	int my_answer = obj->restore(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 4;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
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
