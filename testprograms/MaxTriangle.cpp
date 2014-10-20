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

#define pb push_back
#define X first
#define Y second

typedef long long ll;

#define pll pair<long long,long long>

class MaxTriangle 
{
public:

map<ll,ll> perf;

double area( ll x1, ll y1 , ll x2 , ll y2 )
{
   ll temp=x1*y2 - x2*y1;
      
   if( temp==0 )
     return -1;
     
    return (double)temp/2;
}     
   

double  calculateArea(int A, int B) 
{


  ll a=A,b=B;

  for(ll i=0;i*i<=2000000000;i++)
    perf[i*i]=i;
    
    vector< pll > op1;
    
    for(int x=0;x*x<=a;x++)
      {
         ll y2=a-x*x;
         
         if( perf.count(y2) )
           op1.pb( mp(x,  perf[y2] ) );
    }
    
    vector<pll> op2;
    
    for(int x=0;x*x<=b;x++)
     {
        ll y2=b-x*x;
   
        if( perf.count(y2) )
          op2.pb( mp(x,perf[y2]) );
     }
     
     double ans=-1;
     
     
     for(int i=0;i<op1.size();i++)
       for(int j=0;j<op2.size();j++)
         {
             vector<ll> in(4);
             
             in[0]=op1[i].X  ; 
             in[1]=op1[i].Y;
                    in[2]=op2[j].X ;
                    in[3]=op2[j].Y;
             
             for(int mask=0;mask<=15;mask++)
              {
                       vector<ll> temp=in;
                        
                       for(int k=0;k<4;k++)
                          if( mask & (1<<k) )
                            temp[k]=-temp[k];
                             
                         ans=max( ans , area( temp[0] , temp[1] , temp[2] ,temp[3]) );
                }
          }                

    return ans;                                          
                       
                                                                                                                          
  
	
}

};


#include<ctime>
double test0() {
	int p0 = 1;
	int p1 = 1;
	MaxTriangle * obj = new MaxTriangle();
	clock_t start = clock();
	double my_answer = obj->calculateArea(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 0.5;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int p0 = 3;
	int p1 = 7;
	MaxTriangle * obj = new MaxTriangle();
	clock_t start = clock();
	double my_answer = obj->calculateArea(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = -1.0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int p0 = 41;
	int p1 = 85;
	MaxTriangle * obj = new MaxTriangle();
	clock_t start = clock();
	double my_answer = obj->calculateArea(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 29.5;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
