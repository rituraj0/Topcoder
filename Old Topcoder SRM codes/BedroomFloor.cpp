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


vector<ll> add( vector<ll> a , vector<ll> b)
{
    vector<ll> c=a;

    for(int i=0;i<a.sz;i++)
        c[i]=a[i]+b[i];

    return c;
}

vector<long long> brute (int x1, int y1, int x2, int y2)
    {
        vector<long long> counts(6,0LL);

        char board[x2-x1][y2-y1];
        for (int i=x1; i<x2; i++)
            for (int j=y1; j<y2; j++)
                board[i-x1][j-y1] = ( ((i%10 < 5) == (j%10 < 5))? '-':'|');

        for (int j=y1; j<y2; j++)
        {
            int last= -1;
            for (int i = x1; i<x2; i++)
                if ( board[i-x1][j-y1] == '-')
                    last =  ((last==-1)?i: last);
                else if (last!=-1)
                    counts[ i-last ]++,
                    last = -1;
            if (last!=-1)
                counts[ x2-last ]++;
        }
        for (int i=x1; i<x2; i++)
        {
            int last= -1;
            for (int j = y1; j<y2; j++)
                if ( board[i-x1][j-y1] == '|')
                    last =  ((last==-1)?j: last);
                else if (last!=-1)
                    counts[ j-last ]++,
                    last = -1;
            if (last!=-1)
                counts[ y2-last ]++;
        }
        return counts;

}

 vector<long long> getCounts(int x1, int y1, int x2, int y2)
    {
        vector<long long> counts(6,0LL);

        if ( (x2-x1< 5) || (y2-y1<5) )       // Apply the O(n²) algorithm directly
             counts = brute(x1, y1, x2, y2); // if the input is too small.
        else
        {
             // these modulos help splitting the pattern
             int i1 = (5 - x1%5)%5, i2 = x2%5;
             int j1 = (5 - y1%5)%5, j2 = y2%5;

             // left portion:
             counts =add( counts ,  brute(x1, y1, x1 + i1,  y2) );
             // right portion:
             counts = add( counts , brute(x2-i2, y1, x2,  y2) );

             // bottom portion:
             counts = add( counts , brute(x1+i1, y1, x2-i2,  y1+j1) );

             // top portion:
             counts= add( counts , brute(x1+i1, y2-j2, x2-i2,  y2) );


             // the large rectangle:
             counts[5] += (long long)( y2-y1 - j1 - j2)*( x2-x1 - i1 - i2)/5;

        }

        return counts;
    }

/*Solution code starts here */

class BedroomFloor
{
public:


long long numberOfSticks(int x1, int y1, int x2, int y2)
{
      vector<long long> counts = getCounts(x1,y1,x2,y2);

        long long res =counts[5] + counts[4];

        counts[1] = std::max(0LL, counts[1] - counts[4] );

        long long min23 = std::min(counts[2], counts[3]);
        res+=min23;
        counts[2] -= min23;
        counts[3] -= min23;

        res+=counts[3];

        counts[1] = std::max(0LL, counts[1] - 2* counts[3]);

        long long cnt = counts[2] / 2;
        res += cnt;
        counts[2] -= 2*cnt;

        counts[1] = std::max(0LL, counts[1] - cnt);

        if ( counts[2] == 1)
        {
            res ++;
            counts[1] = std::max( 0LL, counts[1] - 3 * counts[2]);
        }


        res += (counts[1] /5 ) +  ( (counts[1]%5 != 0) ? 1 : 0);

        return res;
}

};


double test0() {
	int p0 = 0;
	int p1 = 0;
	int p2 = 5;
	int p3 = 5;
	BedroomFloor * obj = new BedroomFloor();
	clock_t start = clock();
	long long my_answer = obj->numberOfSticks(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p4 = 5LL;
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
	int p0 = 0;
	int p1 = 0;
	int p2 = 10;
	int p3 = 2;
	BedroomFloor * obj = new BedroomFloor();
	clock_t start = clock();
	long long my_answer = obj->numberOfSticks(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p4 = 5LL;
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
	int p1 = 2;
	int p2 = 8;
	int p3 = 8;
	BedroomFloor * obj = new BedroomFloor();
	clock_t start = clock();
	long long my_answer = obj->numberOfSticks(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p4 = 12LL;
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
	int p0 = 8;
	int p1 = 5;
	int p2 = 20;
	int p3 = 16;
	BedroomFloor * obj = new BedroomFloor();
	clock_t start = clock();
	long long my_answer = obj->numberOfSticks(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p4 = 27LL;
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
	int p0 = 0;
	int p1 = 0;
	int p2 = 1000000;
	int p3 = 1000000;
	BedroomFloor * obj = new BedroomFloor();
	clock_t start = clock();
	long long my_answer = obj->numberOfSticks(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p4 = 200000000000LL;
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
