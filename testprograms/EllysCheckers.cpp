#include<algorithm>
#include<iostream>
#include <sstream>
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


/*Solution code starts here */


class EllysCheckers {
public:

int  memo[1<<22][2];

int n;

int  solve( int mask , int  curr)
{

   mask=mask|1;
   mask=mask^1;
   
   
  if( mask==0)
    return (1-curr);
    
  if( memo[mask][curr]!=-1)  
    return memo[mask][curr];
    
  
    
    vector<int> op;
    
    for(int i=0;i<=n-2;i++) //last me to rahega hi nahi
     {
         if( mask & (1<<(n-1-i) ) )
              {  
                if( !(mask & (1<<(n-2-i) ) ) )
                  {   
                       int bit=mask;
                       bit=bit|( 1<<(n-2-i) );
                       bit=bit^(1<<(n-1-i) );
                       
                       op.pb(bit);
                       
                   }
              }      
             
             
             
             if( i <=n-4 )               
                     if( mask & (1<<(n-1-i) ) )
                          if( mask & (1<<(n-2-i) ) )
                               if( mask & (1<<(n-3-i) ) )
                                    if( ! (mask & (1<<(n-4-i) ) ) )
                                      {
                                          
                                           int bit=mask;
                                             bit=bit | ( 1<<(n-4-i) );
                                             bit=bit ^ ( 1<<(n-1-i) );
                                             
                                             op.pb(bit);
                                         }    
        }                                                   
           

  bool ans=false;
  
  sort(op.begin(), op.end() );
  
  for(int i=0;i<op.size();i++)
    if( solve( op[i] , 1-curr )==curr )
      { ans=true;
         break;
      }
      
   if(ans )
     return memo[mask][curr]=curr;
    else
      return memo[mask][curr]=1-curr;     
            
         
}                
                                         
                       

string  getWinner(string bord) 
{
 
 memset( memo , -1, sizeof(memo) );
   
 n=bord.size();
   
int mask=0;

for(int i=0;i<n;i++)
  if( bord[i]=='o' )
    mask=mask| (1<<(n-1-i) );
  
    
 if( solve(mask,0)==0 )
   return "YES";
   else
     return "NO";   

   
	
}

};

double test0() {
	string p0 = ".o...";
	EllysCheckers * obj = new EllysCheckers();
	clock_t start = clock();
	string my_answer = obj->getWinner(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "YES";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string p0 = "..o..o";
	EllysCheckers * obj = new EllysCheckers();
	clock_t start = clock();
	string my_answer = obj->getWinner(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "YES";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string p0 = ".o...ooo..oo..";
	EllysCheckers * obj = new EllysCheckers();
	clock_t start = clock();
	string my_answer = obj->getWinner(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "NO";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string p0 = "......o.ooo.o......";
	EllysCheckers * obj = new EllysCheckers();
	clock_t start = clock();
	string my_answer = obj->getWinner(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "YES";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	string p0 = ".o..o...o....o.....o";
	EllysCheckers * obj = new EllysCheckers();
	clock_t start = clock();
	string my_answer = obj->getWinner(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "NO";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	
	time = test4();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
