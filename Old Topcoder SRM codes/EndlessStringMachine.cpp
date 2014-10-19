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

class EndlessStringMachine
{
public:

string in , pr;

ll len[55];


string onlyone( string in , string pr , int s, int from, int to)
{
     ll len=(ll)in.sz +  ( (ll)pr.size() )*(ll)s;

     ll is=in.sz,ps=pr.sz;

     string ans="";

     for(int i=from;i<=to;i++)
     {
         if( i < len)
         {
            if( i < is)
               {
                 ans+=in[i];
               }
            else
            {
                ans+=pr[ (i-is)%ps ];
            }
         }
        else
        {
            ans+="-";
        }
     }

     return ans;
}



char  solve( int it , int pos)
{
    if(it==0)
    {
        if( pos < in.sz )
            return in[pos];
        else
            return '-';
    }

    for(int i=0;i<pr.sz;i++)
         if( pr[i]=='$')
            {
                 if( len[it-1] > pos)
                     return solve(it-1,pos);
                 else
                      pos=pos-len[it-1];
             }
           else
           {
               if(pos==0)
                 return pr[i];
               else
                 pos--;
           }

        return '-';

}

string getFragment(string input, string program, int s, int mn, int mx)
{
    in=input; pr=program;

    ll dal=0;

    string pi="";

    for(int i=0;i<pr.sz;i++)
          if( program[i]=='$')
            dal++;
          else
            pi+=program[i];

     if(dal==1)
          return onlyone( input , pi ,  s, mn-1, mx-1);

     len[0]=input.sz;
     int i=0;

     for( i=1;i<min(s,40);i++)
     {
         len[i]=len[i-1]*( dal) +  ( (ll)pi.sz );

         if( len[i] > mx ) break;
     }

     print(i);

     s=i;

     string ans="";

     for(i=mn-1;i<mx;i++)
         ans+=solve(s,i);

     return ans;
}

};


double test0() {
	string p0 = "a";
	string p1 = "$meric$";
	int p2 = 6;
	int p3 = 1;
	int p4 = 35;
	EndlessStringMachine * obj = new EndlessStringMachine();
	clock_t start = clock();
	string my_answer = obj->getFragment(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p5 = "americamericamericamericamericameri";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p5 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	string p0 = "top";
	string p1 = "$coder";
	int p2 = 1;
	int p3 = 1;
	int p4 = 20;
	EndlessStringMachine * obj = new EndlessStringMachine();
	clock_t start = clock();
	string my_answer = obj->getFragment(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p5 = "topcoder------------";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p5 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	string p0 = "abc";
	string p1 = "$x$y$z$";
	int p2 = 10;
	int p3 = 30;
	int p4 = 50;
	EndlessStringMachine * obj = new EndlessStringMachine();
	clock_t start = clock();
	string my_answer = obj->getFragment(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p5 = "bcyabcxabcyabczabczab";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p5 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	string p0 = "xy";
	string p1 = "$a$bb";
	int p2 = 12;
	int p3 = 5000;
	int p4 = 5099;
	EndlessStringMachine * obj = new EndlessStringMachine();
	clock_t start = clock();
	string my_answer = obj->getFragment(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p5 = "xybbbbaxyaxybbaxyaxybbbbbbbbaxyaxybbaxyaxybbbbaxyaxybbaxyaxybbbbbbaxyaxybbaxyaxybbbbaxyaxybbaxyaxybb";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p5 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
//
//double test2() {
//	string p0 = "abc";
//	string p1 = "$x$y$z$";
//	int p2 = 10;
//	int p3 = 30;
//	int p4 = 50;
//	EndlessStringMachine * obj = new EndlessStringMachine();
//	clock_t start = clock();
//	string my_answer = obj->getFragment(p0, p1, p2, p3, p4);
//	clock_t end = clock();
//	delete obj;
//	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
//	string p5 = "bcyabcxabcyabczabczab";
//	cout <<"Desired answer: " <<endl;
//	cout <<"\t\"" << p5 <<"\"" <<endl;
//	cout <<"Your answer: " <<endl;
//	cout <<"\t\"" << my_answer<<"\"" <<endl;
//	if (p5 != my_answer) {
//		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
//		return -1;
//	}
//	else {
//		cout <<"Match :-)" <<endl <<endl;
//		return (double)(end-start)/CLOCKS_PER_SEC;
//	}
//}
double test4() {
	string p0 = "sxqcagqjcvcvjkifuhzxdrupvchpkhkmabcfbhpg";
	string p1 = "$acscb$b$xwd$pw$roxzjbqlacjy$smaij$cydxaicq";
	int p2 = 4;
	int p3 = 950460532;
	int p4 = 950460545;
	EndlessStringMachine * obj = new EndlessStringMachine();
	clock_t start = clock();
	string my_answer = obj->getFragment(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p5 = "--------------";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p5 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p5 != my_answer) {
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
