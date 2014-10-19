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

#define mod 1234567891

string tost(int in)
{
    char ans[20];
    sprintf(ans,"%d",in);
    return ans;
}

bool cool(string in)
{
     for(int i=0;i<in.sz;i++)
         if( in[i]=='4' || in[i]=='7')
           continue;
         else
            return false;

         return true;
}

class TheLuckySequence
{
public:


ll all[5][5],rm[5][5],C[5][5];

void multiply( ll c[5][5] , ll a[5][5] , ll b[5][5])
    {
        fill(rm,0);

        for(int i=0;i<4;i++)
             for(int j=0;j<4;j++)
             {
               ll tp=0;

                for(int k=0;k<4;k++)
                     tp=(tp+a[i][k]*b[k][j])%mod;

                rm[i][j]=tp;
             }

             memcpy(c,rm,sizeof(rm));
  }




  void power(int ex)
    {
         if(ex==0)
         {
            fill(C,0);
            for(int i=0;i<4;i++)
                 C[i][i]=1;
            return;
         }

         if( ex&1)
         {
            power(ex-1);
            multiply(C,C,all);
         }
         else
         {
             power(ex/2);
             multiply(C,C,C);
         }
    }



int count(vector <int> numb, int length)
{
     ll c44=0,c47=0,c74=0,c77=0;

     map<string,bool> done;

     for(int i=0;i<numb.sz;i++)
     {

         string tp=tost( numb[i] );


         if( cool( tp) && (done.find(tp)==done.end() ) )
         {
              done[tp]=true;

             cout<<tp<<endl;

             if( tp[0]=='4')
             {
                   if( tp[ tp.sz-1]=='4' )
                      c44++;
                   else
                       c47++;
             }
            else
            {
                   if( tp[ tp.sz-1]=='4' )
                      c74++;
                   else
                       c77++;
            }
         }
     }


     fill(all,0);

     all[0][0]=c44; all[0][2]=c44;
     all[1][0]=c47; all[1][2]=c47;

     all[2][1]=c74; all[2][3]=c74;
     all[3][1]=c77; all[3][3]=c77;

     power(length-1);

     ll cont[]={c44,c47,c74,c77};

//     for(int i=0;i<4;i++)
//         cout<<cont[i]<<"  ";
//
//         cout<<"\n\n";
//
//         for(int i=0;i<4;i++,cout<<endl)
//             for(int j=0;j<4;j++)
//              cout<<C[i][j]<<"  ";

     ll ans=0;

     for(int i=0;i<4;i++)
     {
           ll tp=0;

             for(int j=0;j<4;j++)
                 tp=(tp + C[i][j]*cont[j])%mod;

             ans=(ans+tp)%mod;
     }

     return ans;


}

};



double test0() {
	int t0[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 1;
	TheLuckySequence * obj = new TheLuckySequence();
	clock_t start = clock();
	int my_answer = obj->count(p0, p1);
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
	int t0[] = {47, 74, 47};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 3;
	TheLuckySequence * obj = new TheLuckySequence();
	clock_t start = clock();
	int my_answer = obj->count(p0, p1);
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
double test2() {
	int t0[] = {100, 4774, 200, 747, 300};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 47;
	TheLuckySequence * obj = new TheLuckySequence();
	clock_t start = clock();
	int my_answer = obj->count(p0, p1);
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
double test3() {
	int t0[] = {44, 47, 74, 77};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 2;
	TheLuckySequence * obj = new TheLuckySequence();
	clock_t start = clock();
	int my_answer = obj->count(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 8;
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
