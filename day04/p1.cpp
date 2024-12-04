#include <bits/stdc++.h>

using namespace std;

/* clang-format off */

/* TYPES  */
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>

/* FUNCTIONS */
#define f(i,s,e) for(long long int i=s;i<e;i++)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)
#define pb push_back
#define eb emplace_back

/* PRINTS */
template <class T>
void print_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}"; }

/* UTILS */
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define read(type) readInt<type>()
ll min(ll a,int b) { if (a<b) return a; return b; }
ll min(int a,ll b) { if (a<b) return a; return b; }
ll max(ll a,int b) { if (a>b) return a; return b; }
ll max(int a,ll b) { if (a>b) return a; return b; }
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

/*  All Required define Pre-Processors and typedef Constants */
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

#define INPUT_FILE "input.txt"
#define INPUT_SAMPLE_FILE "input_sample.txt"

/* clang-format on */

/* Main()  function */
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ifstream file("../" INPUT_FILE);
    int res = 0;

    vector<vector<char>> puzzle;

    // extend map by 3 rows/columns on every direction to not hit index out-of-bound
    vector<char> tmp;
    for (int k=0; k<140; ++k) {
        tmp.push_back('.');
    }
    puzzle.push_back(tmp);
    puzzle.push_back(tmp);
    puzzle.push_back(tmp);


    if (file.is_open()) {
        char c;
        vector<char> row;
        row.push_back('.');
        row.push_back('.');
        row.push_back('.');

        while (file.get(c)) {
            if (c == '\n') {
                //std::cout << "newline" << std::endl;
                row.push_back('.');
                row.push_back('.');
                row.push_back('.');
                puzzle.push_back(row);
                row.clear();
                row.push_back('.');
                row.push_back('.');
                row.push_back('.');
            } else {
                //std::cout << "c: " << c << std::endl;
                row.push_back(c);
            }
        }
        file.close();
    }
    puzzle.push_back(tmp);
    puzzle.push_back(tmp);
    puzzle.push_back(tmp);

#if 1
    int i = 0;
    for (auto row : puzzle) {
        int j = 0;
        for (auto elem : row) {
            if(elem == 'X') {
                // right
                if (puzzle[i][j+1] == 'M' &&
                    puzzle[i][j+2] == 'A' &&
                    puzzle[i][j+3] == 'S')
                    res++;
                // left
                if (puzzle[i][j-1] == 'M' &&
                    puzzle[i][j-2] == 'A' &&
                    puzzle[i][j-3] == 'S')
                    res++;
                // up
                if (puzzle[i-1][j] == 'M' &&
                    puzzle[i-2][j] == 'A' &&
                    puzzle[i-3][j] == 'S')
                    res++;
                // down
                if (puzzle[i+1][j] == 'M' &&
                    puzzle[i+2][j] == 'A' &&
                    puzzle[i+3][j] == 'S')
                    res++;

                // right top
                if (puzzle[i-1][j+1] == 'M' &&
                    puzzle[i-2][j+2] == 'A' &&
                    puzzle[i-3][j+3] == 'S')
                    res++;
                // right bottom
                if (puzzle[i+1][j+1] == 'M' &&
                    puzzle[i+2][j+2] == 'A' &&
                    puzzle[i+3][j+3] == 'S')
                    res++;
                // left top
                if (puzzle[i-1][j-1] == 'M' &&
                    puzzle[i-2][j-2] == 'A' &&
                    puzzle[i-3][j-3] == 'S')
                    res++;
                // left bottom
                if (puzzle[i+1][j-1] == 'M' &&
                    puzzle[i+2][j-2] == 'A' &&
                    puzzle[i+3][j-3] == 'S')
                    res++;
            }
            //std::cout << " " << elem;
            ++j;
        }
        //std::cout << std::endl;
        ++i;
    }
    std::cout << "result:" << res << std::endl;
#endif

#if 1
    for (auto row : puzzle) {
        for (auto elem : row) {
            std::cout << " " << elem;
        }
        std::cout << std::endl;
    }
#endif

    return 0;
}
/* Main() Ends Here */
