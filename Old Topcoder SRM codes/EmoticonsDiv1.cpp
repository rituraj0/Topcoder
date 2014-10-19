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
#define sz size()
#define bg begin()
#define en end()
#define Y second
#define X first
typedef long long ll;

#define fi freopen("input.txt","r",stdin)
#define fo freopen("output.txt","w",stdout)

const double pi     =   acos(-1.0);
const double eps    =   1e-8;

#define print(a) cout<<(#a)<<" = "<<a<<"  ";
#define println(a) cout<<(#a)<<" = "<<a<<"\n";
#define fill(a,val) memset(a ,val, sizeof(a) );

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

int dist[2005][2005];
int done[2005][2005];
#define pii  pair<int,int>

 queue<pii> Q;

class EmoticonsDiv1
{
public:

int printSmiles(int smiles)
{


    fill(dist,-1);
    fill(done,0);

    while(Q.size() )
      Q.pop();

    dist[1][0]=0;//1 in edit , 0 in clip

    Q.push( mp(1,0) );

    while(Q.size() > 0)
    {
        pii tp=Q.front() ;
         Q.pop();
        int i=tp.X; int c=tp.Y;

        if((i > 2001) || (c > 2001) )
             continue;

          if( done[i][c] )
             continue;
          done[i][c]=true;

          if(i>1000)
          {
              cout<<i<<"  "<<c<<"  "<<dist[i][c]<<endl;
          }

         if(i==smiles)
             return dist[i][c];

         //cpoy
           if( dist[i][i] ==-1 )
           {
               Q.push( mp(i,i));
               dist[i][i]=dist[i][c]+1;
           }
           //paste
            if( i+c < 2002 )
             if( dist[i+c][c]==-1)
             {
                 Q.push( mp(i+c,c));
                 dist[i+c][c]=dist[i][c]+1;
             }
             //delete
               if( i > 0)
                  if( dist[i-1][c]==-1)
               {
                   Q.push( mp(i-1,c));
                   dist[i-1][c]=dist[i][c]+1;
               }
    }

    return -1;


}

};


double test0() {
	int p0 = 1000;
	EmoticonsDiv1 * obj = new EmoticonsDiv1();
	clock_t start = clock();
	int my_answer = obj->printSmiles(p0);
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
double test1() {
	int p0 = 4;
	EmoticonsDiv1 * obj = new EmoticonsDiv1();
	clock_t start = clock();
	int my_answer = obj->printSmiles(p0);
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
double test2() {
	int p0 = 6;
	EmoticonsDiv1 * obj = new EmoticonsDiv1();
	clock_t start = clock();
	int my_answer = obj->printSmiles(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 5;
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
	int p0 = 18;
	EmoticonsDiv1 * obj = new EmoticonsDiv1();
	clock_t start = clock();
	int my_answer = obj->printSmiles(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 8;
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
	int p0 = 11;
	EmoticonsDiv1 * obj = new EmoticonsDiv1();
	clock_t start = clock();
	int my_answer = obj->printSmiles(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 8;
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


	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
