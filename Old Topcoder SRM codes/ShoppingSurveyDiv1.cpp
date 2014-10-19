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

class ShoppingSurveyDiv1
{
public:

    vector<int> s;
    int k,N;



    bool cool( int curr)
    {
        vector<int> tp=s;

        for(int i=0;i<curr;i++)
        {
            sort( tp.bg ,tp.end());
            reverse( tp.bg ,tp.end() );



              for(int j=0;j<k;j++)
                  if( tp[j]==0)
                     return  false;
                  else
                      tp[j]--;
        }

        //is point pe sabne k-k kharid lia

        return true;
    }


    bool exact( int curr)
    {
        vector< pair<int,int> >tp;
        for(int i=0;i<sz(s);i++)
             tp.pb( mp( s[i],s[i] ) );


        for(int i=0;i<curr;i++)
        {
            sort( tp.bg ,tp.end());
            reverse( tp.bg ,tp.end() );

              for(int j=0;j<k;j++)
                    tp[j].X--;
        }

        for(int i=0;i<sz(tp);i++)
             tp[i].X=max(0, tp[i].Y-curr);

        int rem=N-curr;

        for(int i=0;i<rem;i++)
        {
            sort( tp.bg ,tp.end());
            reverse( tp.bg ,tp.end() );

              for(int j=0;j<k-1;j++)
              {
                  if( tp[j].X>0)
                     tp[j].X--;
              }
        }


        cout<<endl;

        for(int i=0;i<sz(tp);i++)
             if( tp[i].X > 0)
               return false;

        return true;
    }


int minValue(int _N, int K, vector <int> _s)
{
    s=_s;

    N=_N;
    k=K;



    int lo=0,hi=N;

//    bool can[1000];
//
//    fill(can,0);
//
//    for(int i=0;i<=N;i++)
//     {  if( cool(i) )
//         return i;
//     }

    int mx=0;

    while(lo<=hi)
       {

           int mid=(lo+hi)/2;

           if( cool(mid))
           {
               mx=max(mx,mid);
               lo=mid+1;
           }
          else
          {
              hi=mid-1;
          }
       }

    print(mx);

    lo=0;hi=mx;
    int ans=-1;



    while( lo<=hi )
    {
        int mid=(lo+hi)/2;

        if( exact(mid) )
        {
            ans=mid;
            hi=mid-1;
        }
       else
       {
           lo=mid+1;
       }
    }



       return ans;



}

};


double test0() {
	int p0 = 10;
	int p1 = 2;
	int t2[] = {1, 2, 3};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	ShoppingSurveyDiv1 * obj = new ShoppingSurveyDiv1();
	clock_t start = clock();
	int my_answer = obj->minValue(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 0;
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
	int p1 = 2;
	int t2[] = {1, 2, 3};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	ShoppingSurveyDiv1 * obj = new ShoppingSurveyDiv1();
	clock_t start = clock();
	int my_answer = obj->minValue(p0, p1, p2);
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
double test2() {
	int p0 = 4;
	int p1 = 4;
	int t2[] = {4, 4, 4, 2};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	ShoppingSurveyDiv1 * obj = new ShoppingSurveyDiv1();
	clock_t start = clock();
	int my_answer = obj->minValue(p0, p1, p2);
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
	int p0 = 20;
	int p1 = 3;
	int t2[] = {1, 10, 3, 4, 8, 15, 3, 16, 18, 2, 7, 3};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	ShoppingSurveyDiv1 * obj = new ShoppingSurveyDiv1();
	clock_t start = clock();
	int my_answer = obj->minValue(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 10;
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
	int p0 = 4;
	int p1 = 2;
	int t2[] = {1, 2, 1, 1, 3, 1, 2, 2, 1, 2, 1};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	ShoppingSurveyDiv1 * obj = new ShoppingSurveyDiv1();
	clock_t start = clock();
	int my_answer = obj->minValue(p0, p1, p2);
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
double test5() {
	int p0 = 2;
	int p1 = 3;
	int t2[] = {1, 1, 1, 2};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	ShoppingSurveyDiv1 * obj = new ShoppingSurveyDiv1();
	clock_t start = clock();
	int my_answer = obj->minValue(p0, p1, p2);
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
