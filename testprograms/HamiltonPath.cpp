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
#define mp make_pair
#define mod 1000000007

class HamiltonPath 
{
public:

 vector<string>  road;

  vector<int> comp[55];

  int part[55];

 bool visit[55];

  int n;

  bool cycle;

 void dfs( int u , int c)
  {

      if( visit[u] )
	return ;

       visit[u]=true;

       comp[c].pb( u );

       for(int i=0;i<n;i++)
         if( road[u][i]=='Y')
           {
               if( visit[i]==false )
 		 {     part[i]=u;
			dfs(i,c);
		 }
                else if( part[u]!=i)
		  cycle=true;
             }

   }        

              
                   
                 
	     

  

int  countPaths(vector <string> _road) 
{

   road=_road;

   n=road.size();


 //degree check ***********
     for(int i=0;i<n;i++)
     {
          int deg=0;

            for(int j=0;j<n;j++)
	     if( road[i][j]=='Y')
              deg++;

            if( deg > 2 )
	    return 0;
     }

  //degre *********** done

  memset( visit, 0, sizeof(visit) );
  
   int cn=0;

   cycle=false;

    for(int i=0;i<n;i++)
	if( visit[i]==false)
	  { 
              part[i]=-1;
              dfs(i,cn);
		       cn++;
     }

   if( cycle )
	return 0;
  
   //////^^^ DFS ************

   
   int chain=0, alone=0;

   for(int i=0;i<cn;i++)
     if( comp[i].size()==1)
     alone++;
      else if( comp[i].size() > 1 )
	chain++;

   long long fact[55];
    long long pow[55];

   fact[0]=1;
    pow[0]=1;

   for(int i=1;i<55;i++)
     {
          fact[i]=( fact[i-1]*i) %mod;

           pow[i]=(pow[i-1]*2)%mod;
      }         

  cout<<alone<<"   "<<chain<<endl;

   long long ans=(pow[chain]*fact[chain+alone] )%mod;

   return ans;

      
	
}

};


double test0() {
	string t0[] = {"NYN",
 "YNN",
 "NNN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	HamiltonPath * obj = new HamiltonPath();
	clock_t start = clock();
	int my_answer = obj->countPaths(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 4;
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
	string t0[] = {"NYYY",
 "YNNN",
 "YNNN",
 "YNNN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	HamiltonPath * obj = new HamiltonPath();
	clock_t start = clock();
	int my_answer = obj->countPaths(p0);
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
	string t0[] = {"NYY",
 "YNY",
 "YYN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	HamiltonPath * obj = new HamiltonPath();
	clock_t start = clock();
	int my_answer = obj->countPaths(p0);
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
double test3() {
	string t0[] = {"NNNNNY",
 "NNNNYN",
 "NNNNYN",
 "NNNNNN",
 "NYYNNN",
 "YNNNNN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	HamiltonPath * obj = new HamiltonPath();
	clock_t start = clock();
	int my_answer = obj->countPaths(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 24;
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
