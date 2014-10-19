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
#include<ctime>
#include<cmath>
#include<map>
#include<set>
using namespace std;

#define pb push_back
#define mp make_pair


/*Solution code starts here */

class PlanarGraphShop 
{
public:
	
vector<int> op;	

int memo[50009];

int solve( int in)
{
	 if( in==0 )
	   return 0;
	   
	 if( memo[in]!=-1)  
	   return memo[in];
	   
	 int ans=(1<<20);
	 
	 for(int i=0;i<op.size();i++)  
	  {
	  	  if( op[i] > in)
	  	    break;
	  	    
	  	   int tp=solve(in-op[i])+1;
			 
			 ans=min( ans ,tp) ;
	  }
	  
	  return memo[in]=ans;
}

int  bestCount(int N) 
{
	 
	
     for(int i=1;i<=40;i++)
       {
       	   int tp=i*i*i;
       	   
       	   int mx=0;
       	   
       	   if( i==1)
       	      mx=0;
		    else if(i==2)		   
		        mx=1;
		     else
			     mx=3*i-6;   
       	   
       	     if( tp <=N)
       	       {
       	        op.pb(tp);
       	       }
       	     else
				 break;
				 
			   for(int j=1;j<=mx;j++)	   
			     {
			     	 int ad=j*j;
			     	 int curr=tp+ad;
			     	 
			     	 if( curr <=N)
			     	    {
			     	     op.pb(curr);
			     	    }
			     	 else
					     break;   
			     }       	          	   
       }
       
       sort(op.begin() , op.end() );
       
	  memset( memo , -1 , sizeof(memo)  );
	  
	  for(int i=1;i<=N;i++) 
	   solve(i);
	
	   return solve(N);
}

};


double test0() {
	int p0 = 36;
	PlanarGraphShop * obj = new PlanarGraphShop();
	clock_t start = clock();
	int my_answer = obj->bestCount(p0);
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
	int p0 = 7;
	PlanarGraphShop * obj = new PlanarGraphShop();
	clock_t start = clock();
	int my_answer = obj->bestCount(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 7;
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
	int p0 = 72;
	PlanarGraphShop * obj = new PlanarGraphShop();
	clock_t start = clock();
	int my_answer = obj->bestCount(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 2;
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
	int p0 = 46;
	PlanarGraphShop * obj = new PlanarGraphShop();
	clock_t start = clock();
	int my_answer = obj->bestCount(p0);
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
