#include <bits/stdc++.h>
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

#define print(a) cout<<(#a)<<" = "<<a<<"\n";
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

class StrangeCountry
{
public:

vector<string> graf;

bool useful[55][55];
bool visited[55];

int n;

int extra_edge[55],num_nodes[55];
int noextra_edge;

void dfs( int curr  , int part , int comp)
{
    if( visited[curr]) return;

    visited[curr]=true;
    num_nodes[comp]++;

    for(int i=0;i<n;i++)
         if( i!=part)
           if( graf[curr][i]=='Y')
             if(!visited[i])
                {

                    useful[i][curr]=useful[curr][i]=true;
                                        dfs( i,curr,comp);
                }

    for(int i=curr+1;i<n;i++)
         if( graf[curr][i]=='Y')
            if( !useful[curr][i])
              extra_edge[comp]++;
}

int transform(vector <string> g)
{
   fill(visited,0);
   fill(useful,0);
   noextra_edge=0;

   graf=g;
   n=graf.sz;

   int comp=0;

   for(int i=0;i<n;i++)
     if( !visited[i])
     {
        extra_edge[comp]=num_nodes[comp]=0;

        dfs( i , -1 , comp);

        if( num_nodes[comp]==1)
          return -1;

        if( extra_edge[comp]==0)
          noextra_edge++;
        else
          comp++;
     }

     int ans=0;

     while( noextra_edge && comp)
     {
        ans++;

        if( extra_edge[comp-1]==1)
             comp--;
        else
           {
               extra_edge[comp-1]--;
               noextra_edge--;
           }
     }

     if( (noextra_edge==1)&&(comp==0) )
        return ans;

     if( noextra_edge > 0)
        return -1;

     ans+=comp-1;

     return ans;


}

};


double test0() {
	string t0[] = {"NY",
 "YN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	StrangeCountry * obj = new StrangeCountry();
	clock_t start = clock();
	int my_answer = obj->transform(p0);
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
double test1() {
	string t0[] = {"NYYNN",
 "YNYNN",
 "YYNNN",
 "NNNNY",
 "NNNYN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	StrangeCountry * obj = new StrangeCountry();
	clock_t start = clock();
	int my_answer = obj->transform(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 1;
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
	string t0[] = {"NYYNNNN",
 "YNYNNNN",
 "YYNNNNN",
 "NNNNYYN",
 "NNNYNYY",
 "NNNYYNY",
 "NNNNYYN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	StrangeCountry * obj = new StrangeCountry();
	clock_t start = clock();
	int my_answer = obj->transform(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 1;
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
	string t0[] = {"NYNYNNNNNNNN",
 "YNYNNNNNNNNN",
 "NYNYYNNNNNNN",
 "YNYNNNNNNNNN",
 "NNYNNYYNNNNN",
 "NNNNYNYNNNNN",
 "NNNNYYNNNNNN",
 "NNNNNNNNYYNN",
 "NNNNNNNYNYNN",
 "NNNNNNNYYNNN",
 "NNNNNNNNNNNY",
 "NNNNNNNNNNYN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	StrangeCountry * obj = new StrangeCountry();
	clock_t start = clock();
	int my_answer = obj->transform(p0);
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
double test4() {
	string t0[] = {"NYNNNN",
 "YNYNNN",
 "NYNYNN",
 "NNYNNN",
 "NNNNNY",
 "NNNNYN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	StrangeCountry * obj = new StrangeCountry();
	clock_t start = clock();
	int my_answer = obj->transform(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = -1;
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

	time = test4();
	if (time < 0)
		errors = true;

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
