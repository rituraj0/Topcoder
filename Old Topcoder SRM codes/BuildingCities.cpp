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

class BuildingCities
{
public:

double dist[55][55];
int cost[55][55];//
double  ans[55][2005];
int  n;
set< pair<double,pair<int,int> > > st;

int findMinimumCities(int maxDirect, int maxTravel, vector <int> cx, vector <int> cy)
{
  n=sz(cx);

  for(int i=0;i<n;i++)
     for(int j=0;j<n;j++)
     {
       dist[i][j]=sqrt( (cx[i]-cx[j])*(cx[i]-cx[j]) + (cy[i]-cy[j])*(cy[i]-cy[j]) );

       cost[i][j]=(int)( ( dist[i][j]-(1e-6) )/(double)maxDirect );
     }

  for(int i=0;i<55;i++)
    for(int j=0;j<2005;j++)
        ans[i][j]=(1e30);

  ans[0][0]=0;
  st.insert( mp(0,mp(0,0)) );

  while(!st.empty())
  {
      pair<double,pair<int,int> > curr=*st.begin(); st.erase( st.begin() );

      double d=curr.X;
      int node=curr.Y.X , cont=curr.Y.Y;

       for(int i=0;i<n;i++)
       {
           double newd=d+dist[node][i];
           int newcont=cont+cost[node][i];

           if( (newd < ans[i][newcont]-1e-7)&& ( newd<(double)maxTravel+1e-7) )
           {
               if( st.find( mp( ans[i][newcont],mp(i,newcont) ) )!=st.end() )
               {
                   st.erase( mp( ans[i][newcont],mp(i,newcont) ) );
               }

                ans[i][newcont]=newd;
                st.insert( mp( newd,mp(i,newcont) ) );
           }
       }

  }

  for(int i=0;i<=2000;i++)
    if( ans[n-1][i]<=maxTravel+1e6)
       return i;

  return -1;


}

};


double test0() {
	int p0 = 1;
	int p1 = 5;
	int t2[] = {0,0,0,1,2,2,3};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {0,1,2,2,2,1,1};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	BuildingCities * obj = new BuildingCities();
	clock_t start = clock();
	int my_answer = obj->findMinimumCities(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
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
	int p1 = 15;
	int t2[] = {2,6,10,14};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {2,6,2,6};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	BuildingCities * obj = new BuildingCities();
	clock_t start = clock();
	int my_answer = obj->findMinimumCities(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 3;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int p0 = 2;
	int p1 = 15;
	int t2[] = {0,5,2,3,1,8,6,4,7,9,10};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {0,5,2,3,1,8,6,4,7,9,10};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	BuildingCities * obj = new BuildingCities();
	clock_t start = clock();
	int my_answer = obj->findMinimumCities(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int p0 = 2;
	int p1 = 5;
	int t2[] = {0,5};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {0,5};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	BuildingCities * obj = new BuildingCities();
	clock_t start = clock();
	int my_answer = obj->findMinimumCities(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = -1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	int p0 = 5;
	int p1 = 1500;
	int t2[] = {0,1000};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {0,1000};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	BuildingCities * obj = new BuildingCities();
	clock_t start = clock();
	int my_answer = obj->findMinimumCities(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 282;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
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

//Powered by [KawigiEdit] 2.0!
