#include<algorithm>
#include<iomanip> 
#include<iostream>
#include<sstream>
#include<cstring>
#include<cstdlib>
#include<climits>
#include<fstream>
#include<cctype>
#include<cstdio>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<map>
#include<set>
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

class BigFatInteger2 
{
public:
	
set<int> mapa[2];	
	
void solve(int n , int curr)
{
    
    while (n%2 == 0)
    {
        mapa[curr].insert(2);
        n = n/2;
        
    }
 
    
    for (int i = 3; i <= sqrt(n); i = i+2)
    {
        
        while (n%i == 0)
        {
            mapa[curr].insert(i);
            n = n/i;
            
      }
    }
 
 
   if( n > 1)
     mapa[curr].insert(n);
  

}


long long  calc( int n , int p)
{
	int ans=0;
	
	while(  n > 1)
	  {
	  	if( n%p==0)
	  	 {
	  	 	ans++;
	  	 	n=n/p;
	  	 }
	  	else
		   {
		   	break;
		   } 
	  }
	  
	  return ans;
	
}

string  isDivisible(int A, int B, int C, int D) 
{
	

	
	solve(A,0);
	solve(C,1);
	
	for (set<int>::iterator it=mapa[1].begin(); it!=mapa[1].end(); ++it)
	 {
	 	
	 cout<<*it<<" H  "<<calc(A,*it)*B<<"  I "<<calc(C,*it)*D<<endl;
	   
	   
	  if(*it!=1)
       if( calc(A,*it)*(long long )B < calc(C,*it)*(long long)D )
         {          
         return "not divisible";
         }
   
   
        
    }
         return "divisible";
	
	


	
}

};




double test0() {
	int p0 = 6;
	int p1 = 1;
	int p2 = 2;
	int p3 = 1;
	BigFatInteger2 * obj = new BigFatInteger2();
	clock_t start = clock();
	string my_answer = obj->isDivisible(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p4 = "divisible";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p4 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int p0 = 2;
	int p1 = 1;
	int p2 = 6;
	int p3 = 1;
	BigFatInteger2 * obj = new BigFatInteger2();
	clock_t start = clock();
	string my_answer = obj->isDivisible(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p4 = "not divisible";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p4 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int p0 = 1000000000;
	int p1 = 1000000000;
	int p2 = 1000000000;
	int p3 = 200000000;
	BigFatInteger2 * obj = new BigFatInteger2();
	clock_t start = clock();
	string my_answer = obj->isDivisible(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p4 = "divisible";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p4 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int p0 = 8;
	int p1 = 100;
	int p2 = 4;
	int p3 = 200;
	BigFatInteger2 * obj = new BigFatInteger2();
	clock_t start = clock();
	string my_answer = obj->isDivisible(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p4 = "not divisible";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p4 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int p0 = 999999937;
	int p1 = 1000000000;
	int p2 = 999999929;
	int p3 = 1;
	BigFatInteger2 * obj = new BigFatInteger2();
	clock_t start = clock();
	string my_answer = obj->isDivisible(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p4 = "not divisible";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p4 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test5() {
	int p0 = 2;
	int p1 = 2;
	int p2 = 4;
	int p3 = 1;
	BigFatInteger2 * obj = new BigFatInteger2();
	clock_t start = clock();
	string my_answer = obj->isDivisible(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p4 = "divisible";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p4 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	
	time = test5();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
