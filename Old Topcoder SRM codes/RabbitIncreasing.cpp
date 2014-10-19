#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define bg begin()
#define en end()
#define Y second
#define X first
typedef long long ll;

#define fi freopen("input.txt","r",stdin)
#define fo freopen("output.txt","w",stdout)

const double pi     =   acos(-1.0);
const double eps    =   1e-8;

#define print(a) cout<<(#a)<<" = "<<a<<"\n";
#define fill(a,val) memset(a ,val, sizeof(a) );
#define sz(s) ((int)(s.size()))

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

class RabbitIncreasing
{
public:

ll old[2],baby[2],mod[2];

int getNumber(vector <int> in, int k)
{
   int n=sz(in);

    mod[0]=1000000009LL; mod[1]=(1LL<<55);

    old[1]=old[0]=0;

    baby[0]=baby[1]=1;

    if(in[0]==1)
        return 0;

    int id=0;

    for(int y=2;y<=k;y++)
    {
        for(int i=0;i<2;i++)
        {
            ll bab=old[i];

            if( (id==n)||(in[id]!=y) )// NOT leaving
            {
                old[i]=(old[i]+baby[i])%mod[i];
            }
           else
           {
                if(i==0)
                {
                    if( baby[0]%2 != baby[1]%2)
                         baby[0]+=mod[0];
                }
                else
                    id++;

                  old[i]=(baby[i])/2;
           }

           baby[i]=bab;
        }

    }

    return (baby[0]+old[0])%mod[0];

}

};


double test0() {
	int t0[] = { 3 };
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 3;
	RabbitIncreasing * obj = new RabbitIncreasing();
	clock_t start = clock();
	int my_answer = obj->getNumber(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 1;
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
	int t0[] = { 5, 9 };
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 10;
	RabbitIncreasing * obj = new RabbitIncreasing();
	clock_t start = clock();
	int my_answer = obj->getNumber(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 6;
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
	int t0[] = { 5, 10, 15 };
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 19;
	RabbitIncreasing * obj = new RabbitIncreasing();
	clock_t start = clock();
	int my_answer = obj->getNumber(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 212;
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
	int t0[] = { 2 };
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 10000000;
	RabbitIncreasing * obj = new RabbitIncreasing();
	clock_t start = clock();
	int my_answer = obj->getNumber(p0, p1);
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
double test4() {
	int t0[] = { 195, 211, 227, 230, 260, 
  297, 346, 350, 403, 411, 
  428, 485, 594, 606, 876 }
;
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 1000;
	RabbitIncreasing * obj = new RabbitIncreasing();
	clock_t start = clock();
	int my_answer = obj->getNumber(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 975206486;
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
