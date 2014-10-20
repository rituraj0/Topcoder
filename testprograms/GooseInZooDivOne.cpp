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


typedef long long ll;

#define mod  1000000007

ll ncr[2501][2501];

class GooseInZooDivOne 
{
public:

vector<string> grid;
bool done[55][55];
int cont[2555];
int dist,row,col;

void dfs(int x , int y  , int c)
{
   if( done[x][y] )
    return ;
    
    done[x][y]=true;
    
    cont[c]++;
    
    for(int i=0;i<row;i++)
      for(int j=0;j<col;j++)
        if( grid[i][j]=='v')
          if( abs(x-i)+abs(y-j) <= dist )
                dfs( i , j,  c);
 
 }
 

int  count(vector <string> field, int dist) 
{
    memset( done , 0, sizeof(done) );
    memset( cont , 0, sizeof(cont) );
    
    grid=field;
    this->dist=dist;
    
    row=grid.size() , col=grid[0].size();
    
    int cn=0;
    
    for(int i=0;i<row;i++)
      for(int j=0;j<col;j++)
        if( grid[i][j]=='v' )
        if( !done[i][j] )
         { dfs(i,j,cn);
           cn++;
          }
          
      int odd=0,even=0;
      
       for(int i=0;i<cn;i++)
         if( cont[i] &1 )
           odd++ ;
         else
           even++;     
  
    memset( ncr , 0, sizeof(ncr) );
    
       for(int i=1;i< 2501;i++)
           ncr[i][0]=1;
           
          ncr[1][1]=1;  
          ncr[0][0]=1;
       
      for(int i=2;i<2501;i++)
        for(int j=1;j<2501;j++)
          ncr[i][j]=( ncr[i-1][j] + ncr[i-1][j-1] )%mod;           

      
          ll oc=0;
          
           for(int i=0;i<=odd;i++)
               if( i%2==0 )
                  oc=(oc + ncr[odd][i])%mod;
                                                                                                                                                                                                                                                                                                                                                                                                           
            ll ec=1;  
            
            for(int i=1;i<=even;i++)
                  ec=(ec*2)%mod;
                  
              ll ans=( (oc*ec)%mod + mod -1 )%mod;
              
              
          return ans;  
  
    
	
}

};



double test0() {
	string t0[] = {"vvv"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 0;
	GooseInZooDivOne * obj = new GooseInZooDivOne();
	clock_t start = clock();
	int my_answer = obj->count(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 3;
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
	string t0[] = {"."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 100;
	GooseInZooDivOne * obj = new GooseInZooDivOne();
	clock_t start = clock();
	int my_answer = obj->count(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 0;
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
	string t0[] = {"vvv"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 1;
	GooseInZooDivOne * obj = new GooseInZooDivOne();
	clock_t start = clock();
	int my_answer = obj->count(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 0;
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
	string t0[] = {"v.v..................v............................"
,".v......v..................v.....................v"
,"..v.....v....v.........v...............v......v..."
,".........vvv...vv.v.........v.v..................v"
,".....v..........v......v..v...v.......v..........."
,"...................vv...............v.v..v.v..v..."
,".v.vv.................v..............v............"
,"..vv.......v...vv.v............vv.....v.....v....."
,"....v..........v....v........v.......v.v.v........"
,".v.......v.............v.v..........vv......v....."
,"....v.v.......v........v.....v.................v.."
,"....v..v..v.v..............v.v.v....v..........v.."
,"..........v...v...................v..............v"
,"..v........v..........................v....v..v..."
,"....................v..v.........vv........v......"
,"..v......v...............................v.v......"
,"..v.v..............v........v...............vv.vv."
,"...vv......v...............v.v..............v....."
,"............................v..v.................v"
,".v.............v.......v.........................."
,"......v...v........................v.............."
,".........v.....v..............vv.................."
,"................v..v..v.........v....v.......v...."
,"........v.....v.............v......v.v............"
,"...........v....................v.v....v.v.v...v.."
,"...........v......................v...v..........."
,"..........vv...........v.v.....................v.."
,".....................v......v............v...v...."
,".....vv..........................vv.v.....v.v....."
,".vv.......v...............v.......v..v.....v......"
,"............v................v..........v....v...."
,"................vv...v............................"
,"................v...........v........v...v....v..."
,"..v...v...v.............v...v........v....v..v...."
,"......v..v.......v........v..v....vv.............."
,"...........v..........v........v.v................"
,"v.v......v................v....................v.."
,".v........v................................v......"
,"............................v...v.......v........."
,"........................vv.v..............v...vv.."
,".......................vv........v.............v.."
,"...v.............v.........................v......"
,"....v......vv...........................v........."
,"....vv....v................v...vv..............v.."
,".................................................."
,"vv........v...v..v.....v..v..................v...."
,".........v..............v.vv.v.............v......"
,".......v.....v......v...............v............."
,"..v..................v................v....v......"
,".....v.....v.....................v.v......v......."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 3;
	GooseInZooDivOne * obj = new GooseInZooDivOne();
	clock_t start = clock();
	int my_answer = obj->count(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 898961330;
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
	
//	time = test1();
//	if (time < 0)
//		errors = true;
//	
//	time = test2();
//	if (time < 0)
//		errors = true;
//	
//	time = test3();
//	if (time < 0)
//		errors = true;
//	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
