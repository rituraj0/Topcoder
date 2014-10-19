#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
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

class DrawingLines
{
public:


double countLineCrossings(int n, vector <int> st, vector <int> en)
{
    int m=sz(st);

    double ans=0.0;

    //all  marked
    for(int i=0;i<m;i++)
         for(int j=i+1;j<m;j++)
          {
           if( (st[i]<st[j])&&(en[i]>en[j]) )
                ans+=1.0;

           if( (st[i]>st[j])&&(en[i]<en[j]) )
                ans+=1.0;

          }

       // two of unmarked has porb 0.5

           double rem=(n-m);
             ans+=rem*(rem-1.0)/4.0;

        // one marked and anothwr unmarked

     for(int i=0;i<m;i++)
     {
            int top_left=st[i]-1,top_right=n-st[i];
            int bot_left=en[i]-1,bot_right=n-en[i];

            for(int j=0;j<m;j++)
                 if(i!=j)
                  {
                   if( st[j] < st[i])
                      top_left--;
                   else
                       top_right--;

                   if( en[j] < en[i])
                       bot_left--;
                   else
                       bot_right--;

                 }

               double up=top_left*bot_right + top_right*bot_left;
               double down=bot_left+bot_right;

               // the expected number is : topLeft * (bottomRight / (bottomLeft + bottomRight)) + topRight *( bottomLeft / (bottomLeft + bottomRight)).

                //take cara of  division
               //if(down!=0)
               ans+=up/down;
     }

     return ans;

}

};


double test0() {
	int p0 = 3;
	int t1[] = {2};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {3};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	DrawingLines * obj = new DrawingLines();
	clock_t start = clock();
	double my_answer = obj->countLineCrossings(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p3 = 1.5;
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
	int p0 = 5;
	int t1[] = {1,4};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {3,1};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	DrawingLines * obj = new DrawingLines();
	clock_t start = clock();
	double my_answer = obj->countLineCrossings(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p3 = 5.5;
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
	int p0 = 4;
	int t1[] = {4,1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {4,1};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	DrawingLines * obj = new DrawingLines();
	clock_t start = clock();
	double my_answer = obj->countLineCrossings(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p3 = 0.5;
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
	int p0 = 8;
	int t1[] = {1,4,3,6,7};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {1,3,2,4,5};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	DrawingLines * obj = new DrawingLines();
	clock_t start = clock();
	double my_answer = obj->countLineCrossings(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p3 = 7.5;
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

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
