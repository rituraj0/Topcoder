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

class NetworkSecurity
{
public:

bool graf[101][101];

int secureNetwork(vector <string> cc, vector <string> sc)
{
    int n=sz(cc),m=sz(sc[0]);

    fill(graf,0);

    for(int i=0;i<n;i++)
         for(int j=0;j<n;j++)
            if( cc[i][j]=='Y')
               graf[i][j]=true;

    for(int i=0;i<n;i++)
         for(int j=0;j<m;j++)
            if( sc[i][j]=='Y')
              graf[i][j+n]=true;

    for(int k=0;k<n+m;k++)
         for(int i=0;i<n+m;i++)
           for(int j=0;j<n+m;j++)
             if( graf[i][k] && graf[k][j])
                graf[i][j]=true;

    int ans=0;

    for(int i=0;i<n;i++)
       for(int j=n;j<n+m;j++)
          if( graf[i][j])
            {
                 bool take=true;

                 for(int k=0;k<n;k++)
                      if( graf[i][k] && graf[k][j])
                       take=false;

                  ans+=take;
            }

   return ans;



}

};


double test0() {
	string t0[] = {"NYN"
,"NNN"
,"NYN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"YN"
,"YN"
,"NY"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	NetworkSecurity * obj = new NetworkSecurity();
	clock_t start = clock();
	int my_answer = obj->secureNetwork(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 2;
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
	string t0[] = {"NN"
,"NN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"NNN"
,"NNN"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	NetworkSecurity * obj = new NetworkSecurity();
	clock_t start = clock();
	int my_answer = obj->secureNetwork(p0, p1);
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
	string t0[] = {"NYNN"
,"NNNN"
,"NNNY"
,"NNNN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"YYN"
,"NNN"
,"NNY"
,"NNN"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	NetworkSecurity * obj = new NetworkSecurity();
	clock_t start = clock();
	int my_answer = obj->secureNetwork(p0, p1);
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
