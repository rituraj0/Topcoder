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

class SillySudoku 
{
public:
	
vector<string> bord;	

vector<int> temp[4],save[4];

bool match()
{
	for(int i=0;i<4;i++)
	  for(int j=0;j<4;j++)
	   {
	   	   if( bord[i][j]=='-')
	   	    continue;
	   	    
	   	    if( bord[i][j]-'0'!=temp[i][j]) 
	   	     return false;
	   }
	   
	   return true;
}

bool col(int a)
{
   int  sum=0;
   
   for(int i=0;i<4;i++)
     sum=sum|(1<<temp[i][a]);
     
     return (sum==30);	
}

bool subs()
{
  bool ans=true;
  
  for(int x=0;x<4;x+=2)
    for(int y=0;y<4;y+=2)
     {
     	 int sum=0;
     	 
     	   for(int i=x;i<x+2;i++)
     	     for(int j=y;j<y+2;j++)
     	       sum=sum|(1<<temp[i][j]);
     	       
     	     if(sum!=30)  
     	       ans=false;
     }
     
     return ans;
}

bool cool()
{
	 bool ans=true;
	 
	 ans=ans&&match();
	 
	 for(int i=0;i<4;i++)
	   ans=ans&col(i);
	   
	   ans=ans&subs();
	   
	   return ans;
	
}

int  countWays(vector <string> board) 
{
	 bord=board;

      for(int i=0;i<4;i++)
      {
       
         for(int j=1;j<=4;j++)
           temp[i].pb(j);
           
           save[i]=temp[i];
      }
	 
	 int ans=0;
	 
	 
	 do
	  {
	  	temp[2]=save[2];
	  	
	    do
	    {
	  	   temp[1]=save[1];
	  	   
	  	   	 do
	          {
	  	
	  	        temp[0]=save[0];
	  	       	 do
	  			  {
	  	
	  	             if( cool() )
	  	               ans++;
	  	
	  			 }while( next_permutation( temp[0].begin() , temp[0].end() ) );
	  	
	         }while( next_permutation( temp[1].begin() , temp[1].end() ) );
	  	
	    }while( next_permutation( temp[2].begin() , temp[2].end() ) );
	  	
	  }while( next_permutation( temp[3].begin() , temp[3].end() ) );
	  
	  
	  return ans;
	
}

};


double test0() {
	string t0[] = {"--21", 
 "--34", 
 "2143", 
 "3412"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	SillySudoku * obj = new SillySudoku();
	clock_t start = clock();
	int my_answer = obj->countWays(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 1;
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
	string t0[] = {"--1-", 
 "--1-", 
 "----", 
 "----"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	SillySudoku * obj = new SillySudoku();
	clock_t start = clock();
	int my_answer = obj->countWays(p0);
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
	string t0[] = {"1---", 
 "-42-", 
 "-3--", 
 "----"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	SillySudoku * obj = new SillySudoku();
	clock_t start = clock();
	int my_answer = obj->countWays(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 3;
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
	string t0[] = {"1---", 
 "--1-", 
 "-1--", 
 "---1"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	SillySudoku * obj = new SillySudoku();
	clock_t start = clock();
	int my_answer = obj->countWays(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 18;
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
double test4() {
	string t0[] = {"1---", 
 "----", 
 "----", 
 "----"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	SillySudoku * obj = new SillySudoku();
	clock_t start = clock();
	int my_answer = obj->countWays(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 72;
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
	
	time = test4();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
