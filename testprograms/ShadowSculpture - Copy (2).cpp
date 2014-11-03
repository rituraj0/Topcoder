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

struct point
{
    int x,y,z;
    point(int a, int b , int c)
    {
        x=a;
        y=b;
        z=c;
    }

    point()
    {

    }
};

bool adja( point a, point b)
{
    int x=0;

     x+=abs( a.x -b.x);
     x+=abs( a.y -b.y);
     x+=abs( a.z -b.z);

     return (x <=1);//may be same
}

class ShadowSculpture
{
public:

vector<point> all[310];

vector<int> graf[310];

bool done[310];

void dfs( int x)
{
    if( done[x] )
         return ;

    done[x]=true;

    for(int i=0;i<sz( graf[x]);i++)
         dfs( graf[x][i] );
}
string possible(vector <string> XY, vector <string> YZ, vector <string> ZX)
{
    int n=sz(XY);
    int cont=0;

    //build for XY
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
          if( XY[i][j]=='Y')
            {
                for(int k=0;k<n;k++)
                     all[cont].pb ( point(i,j,k));

                     cont++;
            }

     //build for YZ
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
          if( YZ[i][j]=='Y')
           {
                for(int k=0;k<n;k++)
                     all[cont].pb( point(k,i,j) );

                     cont++;
            }

    //build for ZX

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
          if( ZX[i][j]=='Y')
           {
                for(int k=0;k<n;k++)
                     all[cont].pb( point(j,k,i));

                     cont++;
            }

     //Now building graf

     for(int i=0;i<cont;i++)
         for(int j=i+1;j<cont;j++)
                {

                    bool mila=false;

                    for(int a=0;a<sz( all[i] );a++)
                    {
                          if( mila)
                              break;

                         for(int b=0;b<sz( all[j]);b++)
                            if( adja( all[i][a] , all[j][b] ) )
                            {
                                mila=true;
                                break;
                            }
                    }

                    if(mila)
                     {
                          graf[i].pb(j);
                           graf[j].pb(i);

                           cout<<i<<"  "<<j<<endl;
                     }
                }

       // Now dfs

       fill( done ,0);

       dfs(0);

       for(int i=0;i<cont;i++)
         if( !done[i])
            return  "Impossible";


     return "Possible";
}

};


double test0() {
	string t0[] = {"YN","NN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"YN","NN"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"YN","NN"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	ShadowSculpture * obj = new ShadowSculpture();
	clock_t start = clock();
	string my_answer = obj->possible(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "Possible";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p3 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string t0[] = {"YN","NY"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"YN","NY"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"YN","NY"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	ShadowSculpture * obj = new ShadowSculpture();
	clock_t start = clock();
	string my_answer = obj->possible(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "Impossible";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p3 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string t0[] = {"YYY","YNY","YYY"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"YYY","YNY","YYY"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"YYY","YNY","YYY"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	ShadowSculpture * obj = new ShadowSculpture();
	clock_t start = clock();
	string my_answer = obj->possible(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "Possible";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p3 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string t0[] = {"YYY","YNY","YYY"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"NYY","YNY","YYY"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"YYY","YNY","YYN"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	ShadowSculpture * obj = new ShadowSculpture();
	clock_t start = clock();
	string my_answer = obj->possible(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "Impossible";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p3 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string t0[] = {"N"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"N"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"N"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	ShadowSculpture * obj = new ShadowSculpture();
	clock_t start = clock();
	string my_answer = obj->possible(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "Possible";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p3 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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

//	time = test2();
//	if (time < 0)
//		errors = true;
//
//	time = test3();
//	if (time < 0)
//		errors = true;
//
//	time = test4();
//	if (time < 0)
//		errors = true;

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
