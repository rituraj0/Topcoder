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

#include<ctime>
//

string tost( long long in)
{
	 char ans[25];

	 sprintf(ans ,"%lld",in);

	 return ans;
}

typedef long long ll;

int off=200;

class NumbersAndMatches
{
public:

	string conf[10];

	void init()
	{
		conf[0]=" ------";
		conf[1]="  ---  ";
		conf[2]="--- -- ";
		conf[3]="-----  ";
		conf[4]="- --  -";
		conf[5]="-- -- -";
		conf[6]="-- ----";
		conf[7]=" ---   ";
		conf[8]="-------";
		conf[9]="----- -";
	}

    int more(int a, int b )
     {
     	 int ans=0;

     	 for(int i=0;i<7;i++)
     	   if( conf[a][i]=='-' && conf[b][i]==' ')
     	     ans++;

     	     return ans;
     }

    int less( int a, int b)//move requered to change a to b
     {
     	 int km=0;

     	 for(int i=0;i<7;i++)
     	   if(conf[a][i]==' ' && conf[b][i]=='-')
     	     km++;


          return km++;
     }

   ll memo[40][400][400];


   int allowed;

   string in;

   int n; //size of input

   ll solve( int curr, int mv , int bal )
    {
    	  if( mv > allowed)
    	    return 0;

    	   if( curr==n)
    	    {
    	    	 if( bal==0)
    	    	   return 1;

    	    	   return 0;
    	    }

    	   if( memo[curr][mv][off+bal] !=-1)
    	     return memo[curr][mv][off+bal];


    	     ll ans=0;

    	     for(int i=0;i<=9;i++)//for this pos tring this value
    	      {
    	      	 int m=more(in[curr]-'0' , i);// extra
    	      	 int l=less( in[curr]-'0' , i);//less

    	      	 int nbal=bal+m-l;

                 int nmv=mv+l;


    	      	 ans+=solve(curr+1, nmv , nbal);
    	      }

    	      return memo[curr][mv][off+bal]=ans;
    }


long long  differentNumbers(long long N, int K)
{
	 init();

	 memset( memo, -1, sizeof(memo));

	 in=tost(N);

	 n=in.size();

	 allowed=K;

	 return solve(0,0,0);


}

};


double test0() {
	long long p0 = 10LL;
	int p1 = 1;
	NumbersAndMatches * obj = new NumbersAndMatches();
	clock_t start = clock();
	long long my_answer = obj->differentNumbers(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 4LL;
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
	long long p0 = 23LL;
	int p1 = 1;
	NumbersAndMatches * obj = new NumbersAndMatches();
	clock_t start = clock();
	long long my_answer = obj->differentNumbers(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 4LL;
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
	long long p0 = 66LL;
	int p1 = 2;
	NumbersAndMatches * obj = new NumbersAndMatches();
	clock_t start = clock();
	long long my_answer = obj->differentNumbers(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 15LL;
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
double test3() {
	long long p0 = 888888888LL;
	int p1 = 100;
	NumbersAndMatches * obj = new NumbersAndMatches();
	clock_t start = clock();
	long long my_answer = obj->differentNumbers(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 1LL;
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
double test4() {
	long long p0 = 444444444444444444LL;
	int p1 = 2;
	NumbersAndMatches * obj = new NumbersAndMatches();
	clock_t start = clock();
	long long my_answer = obj->differentNumbers(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 1LL;
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
