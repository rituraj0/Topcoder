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

class TurnOnLamps 
{
public:
	
	int n;
	int state[50][50];
	bool imp[50][50];
	bool edge[50][50];
	
	int part[50];
	
	void dfs( int u , int p)
	 {
	 	 part[u]=p;
	 	 
		  for(int v=0;v<n;v++)
		     if( v!=p)
		     if( edge[u][v])
		      {
		      	 if( imp[u][v] && state[u][v]==1)
		      	  continue;
		      	  
		      	  dfs(v,u);
		      }
	 	   
	 }
	 
	 
	 vector<int> pathXY( int x  , int y)
	  {
	  	 memset( part , -1, sizeof(part) );
	  	 
	  	 dfs(x,-1);
	  	 
	  	 if( part[y]==-1)
	  	  return vector<int>(1,-1);
	  	 else
		    {
		    	vector<int> path(1,0);
		    	
		    	while( part[y]!=-1)
		    	 {
		    	 	if( imp[ part[y] ][y] )
		    	 	  path[0]++;
		    	 	  
		    	 	  path.pb(y);
		    	 	  y=part[y];
		    	 }
		    	 
		    	 path.pb(y);
		    	 return path;
		    } 
	  }
	

int  minimize(vector <int> roads, string init, string isImp) 
{
	n=roads.size()+1;
	
	memset( edge , 0, sizeof(edge));
	memset( imp , 0, sizeof(imp));
	
	for(int i=0;i<n-1;i++)
	 {
	 	int u=roads[i] , v=i+1;
	 	edge[u][v]=edge[v][u]=true;
	 	state[u][v]=state[v][u]=init[i]-'0';
	 	
	 	if( isImp[i]=='1')
	 	 {
	 	 	imp[u][v]=imp[v][u]=true;
	 	 }
	 	
	 }
	 
	 int ans=0;
	 
	 while(1)
	 {
	 	vector<int>  bpath=vector<int>(1,-1);
	 	
	 	for(int i=0;i<n;i++)
	 	  for(int j=i+1;j<n;j++)
	 	     bpath=max( bpath , pathXY(i,j) );
	 	     
	 	     
	 	  if( bpath[0] <=0)   
	 	   break;
	 	   
	 	   ans++;
	 	   
	 	   for(int i=1;i<bpath.size()-1;i++)
	 	    {
	 	    	int u=bpath[i] , v=bpath[i+1];
	 	    	
	 	    	state[u][v]=state[v][u]=1;
	 	    }
	 }
	 
	return ans;
}

};



double test0() {
	int t0[] = {0,0,1,1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	string p1 = "0001";
	string p2 = "0111";
	TurnOnLamps * obj = new TurnOnLamps();
	clock_t start = clock();
	int my_answer = obj->minimize(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 1;
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
	int t0[] = {0,0,1,1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	string p1 = "0000";
	string p2 = "0111";
	TurnOnLamps * obj = new TurnOnLamps();
	clock_t start = clock();
	int my_answer = obj->minimize(p0, p1, p2);
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
double test2() {
	int t0[] = {0,0,1,1,4,4};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	string p1 = "000100";
	string p2 = "111111";
	TurnOnLamps * obj = new TurnOnLamps();
	clock_t start = clock();
	int my_answer = obj->minimize(p0, p1, p2);
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
double test3() {
	int t0[] = {0,0,1,1,4,4};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	string p1 = "100100";
	string p2 = "011101";
	TurnOnLamps * obj = new TurnOnLamps();
	clock_t start = clock();
	int my_answer = obj->minimize(p0, p1, p2);
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
double test4() {
	int t0[] = {0,0,2,2,3,1,6,3,1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	string p1 = "010001110";
	string p2 = "000110100";
	TurnOnLamps * obj = new TurnOnLamps();
	clock_t start = clock();
	int my_answer = obj->minimize(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 1;
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
double test5() {
	int t0[] = {0,0,1,2,4,4,6,1,2,5,2,8,8,3,6,4,14,7,18,14,11,7,1,12,7,5,18,23,0,14,11,10,2,2,6,1,30,11,9,12,5,35,25,11,23,17,14,45,15};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	string p1 = "0000000000010000000000000010000010100000000000000";
	string p2 = "1010111111111011011111000110111111111111111110111";
	TurnOnLamps * obj = new TurnOnLamps();
	clock_t start = clock();
	int my_answer = obj->minimize(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 14;
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
