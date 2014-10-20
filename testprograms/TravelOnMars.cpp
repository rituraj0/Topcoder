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
#include<map>
#include<set>
using namespace std;

class TravelOnMars {
public:

int minTimes(vector <int> in, int st, int ed) 
{
	  int dp[55][55];
	
      memset( dp , 63 ,sizeof(dp));
      
      int n=in.size();
      
    for(int i=0;i< n;i++)
     { 
        
      int r=in[i];
             
        for(int j=1;j<=r;j++)
            dp[i][(i+j)%n]=1;                    
               
        for(int j=1;j<=r;j++)
            dp[i][(i-j+n*100)%n]=1;
    }
    
    for(int k=0;k<n;k++)
      for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
          dp[i][j]=min( dp[i][j] , dp[i][k] + dp[k][j] );
          

    return dp[st][ed];                                                                                                                                                                                            
                                                                                  	
}

};



double test0() {
	int t0[] = {2,1,1,1,1,1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 1;
	int p2 = 4;
	TravelOnMars * obj = new TravelOnMars();
	clock_t start = clock();
	int my_answer = obj->minTimes(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 2;
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
	int t0[] = {2,1,1,1,1,1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 4;
	int p2 = 1;
	TravelOnMars * obj = new TravelOnMars();
	clock_t start = clock();
	int my_answer = obj->minTimes(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 3;
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
	int t0[] = {2,1,1,2,1,2,1,1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 2;
	int p2 = 6;
	TravelOnMars * obj = new TravelOnMars();
	clock_t start = clock();
	int my_answer = obj->minTimes(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 3;
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
	int t0[] = {3,2,1,1,3,1,2,2,1,1,2,2,2,2,3};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 6;
	int p2 = 13;
	TravelOnMars * obj = new TravelOnMars();
	clock_t start = clock();
	int my_answer = obj->minTimes(p0, p1, p2);
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
