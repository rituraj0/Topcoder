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
#include<functional>
#include<numeric>

using namespace std;

#define pic pair<char,int>
#define mp make_pair
#define X first
#define Y second



class FoxAndHandle {
public:

string lexSmallestName(string S)
 {
     
        int req[256]={0};
       
       for(int i=0;i<S.size();i++)
         req[ S[i] ]++;
         
       for(int i='a';i<='z';i++)
          req[i]=req[i]/2;
          
        string ans="";
  
  
                 
      while( accumulate(req,req+256,0) > 0 ) 
      {
            
            pic best=make_pair('z'+1,-1);
            
            for(int i=0;i<S.size();i++)
               if( req[ S[i] ] )
                {
                       
                   int present[256]={0};
                   
                   for(int j=i;j<S.size();j++)
                     present[ S[j] ]++;
                     
                   bool good=true;
                   
                   for(int j='a';j<='z';j++)
                     if( present[j] < req[j] )
                       good=false;  
                       
                     if(good)
                       best=min( best , mp(S[i] , i) );
                               
              }
              
            int x=best.Y;
            req[ S[x] ]--;
            ans+=S[x];
            
            S=S.substr(x+1);
            
             
            }
                            

return ans;
	
}

};


double test0() {
	string p0 = "foxfox";
	FoxAndHandle * obj = new FoxAndHandle();
	clock_t start = clock();
	string my_answer = obj->lexSmallestName(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "fox";
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
	string p0 = "ccieliel";
	FoxAndHandle * obj = new FoxAndHandle();
	clock_t start = clock();
	string my_answer = obj->lexSmallestName(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "ceil";
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
	string p0 = "abaabbab";
	FoxAndHandle * obj = new FoxAndHandle();
	clock_t start = clock();
	string my_answer = obj->lexSmallestName(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "aabb";
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
	string p0 = "bbbbaaaa";
	FoxAndHandle * obj = new FoxAndHandle();
	clock_t start = clock();
	string my_answer = obj->lexSmallestName(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "bbaa";
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
	string p0 = "fedcbafedcba";
	FoxAndHandle * obj = new FoxAndHandle();
	clock_t start = clock();
	string my_answer = obj->lexSmallestName(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "afedcb";
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
double test5() {
	string p0 = "nodevillivedon";
	FoxAndHandle * obj = new FoxAndHandle();
	clock_t start = clock();
	string my_answer = obj->lexSmallestName(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "deilvon";
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
	
	time = test5();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
