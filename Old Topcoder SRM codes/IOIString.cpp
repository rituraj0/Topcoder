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

ll mod=(1e9)+7;
class IOIString
{
public:


int countIOIs(vector <string> mask)
{
    string in="";

    for(int i=0;i<sz(mask);i++)
        in+=mask[i];

    int n=sz(in);

     int icont=0;
     for(int i=0;i<n;i++)
         if( in[i]=='I')
           icont++;

     int no=(icont==0);//agar koe i nahi hai to 1 soln hua na

    for(int i=0;i<n;i++)//start index
         if( in[i]=='I' || in[i]=='?')
        {

            int x=(in[i]=='I');//

            if(x==icont)//if there is one only I in string and its here , then its a solution with only one I . not a IOI strriing
                 no++;  //else , if it is ? and there is no I, then convert this ? into  I ,and do nothing else and u get a non-ioi string

             for(int j=1;j+i<n;j+=2)//interval length ,, only ODD leght possible
             {
                 int y=x;
                 for(int k=i+j;k<n;k+=j)
                 {
                     y+=(in[k]=='I');//kitna I aaya is interval me

                     if(in[k]=='O')
                         break;

                     no+=(y==icont);//is interval ko chhor ke aur koe i to nahi hai na
                 }
             }
        }


        ll yes=1LL;

        for(int i=0;i<n;i++)
             if( in[i]=='?')
        {
            yes*=2;
            yes%=mod;
        }

        yes+=(mod-no);
        yes%=mod;

        return yes;


}

};


double test0() {
	string t0[] = {"IO?"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	IOIString * obj = new IOIString();
	clock_t start = clock();
	int my_answer = obj->countIOIs(p0);
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
double test1() {
	string t0[] = {"????"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	IOIString * obj = new IOIString();
	clock_t start = clock();
	int my_answer = obj->countIOIs(p0);
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
	string t0[] = {"?II"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	IOIString * obj = new IOIString();
	clock_t start = clock();
	int my_answer = obj->countIOIs(p0);
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
double test3() {
	string t0[] = {"I??O??I"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	IOIString * obj = new IOIString();
	clock_t start = clock();
	int my_answer = obj->countIOIs(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 16;
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
	string t0[] = {"???I???????O???","???????????O??IO????????I???"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	IOIString * obj = new IOIString();
	clock_t start = clock();
	int my_answer = obj->countIOIs(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 438952513;
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

//Powered by [KawigiEdit] 2.0!
