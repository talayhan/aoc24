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


/* clang-format on */
#define INPUT_FILE "input.txt"
#define INPUT_SAMPLE_FILE "input_sample.txt"

/* Main()  function */
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    std::ifstream file("../" INPUT_SAMPLE_FILE);
    if (!file) {
        std::cout << "Could not open the file!" << std::endl;
        return -1;
    }

    long sol;
    std::string line;
    std::vi cpage_idx;
    std::unordered_map<int, vector<int>> rules;
    std::vector<unordered_map<int, int>> updates;

    // First, read the pairs separated by a pipe '|'
    while (std::getline(file, line) && !line.empty() && line.find('|') != std::string::npos) {
        std::istringstream ss(line);
        int first, second;
        char delimiter;
        ss >> first >> delimiter >> second;
        auto it = rules.find(first);
        // add a new elem
        if (it == rules.end()) {
            vi tmp = {second};
            rules.insert({first, tmp});
        } else {
            it->second.push_back(second);
        }
    }
    std::cout << "Rules size: " << rules.size() << std::endl;

    // Then, read the lists separated by commas
    do {
        int i = 0;
        std::istringstream ss(line);
        std::string num;
        std::unordered_map<int, int> clist;

        while (std::getline(ss, num, ',')) {
            //std::cout << " num: " << num;
            clist[std::stoi(num)] = i++;
        }
        updates.push_back(clist);

    } while (std::getline(file, line));

    // Display the Rules
    for (const auto& p : rules) {
        std::cout << "Key: " << p.first << " | ";
        std::cout << "Rules: ";
        for (const auto &rule : p.second) {
            std::cout << rule << " ";
        }
        std::cout << std::endl;
    }

    // Display the updates
    std::cout << "\nUpdates:" << std::endl;
    int idx = 0;
    for (unordered_map<int, int> update : updates) {
        bool isCorrect = true;
        for (pii num : update) {
            // rules exist
            auto it = rules.find(num.first);
            if (it == rules.end()) {
                continue;
            }

            // Rules: 29 13
            // num: 53 index 4
            for (int rule : it->second) {
                auto rit = update.find(rule);
                if (rit != update.end() && update.at(rule) < num.second) {
                    // this rule breaks this update
                    isCorrect = false;
                }
            }

#if 0
            auto it = rules.find(map.first);
            if (it != rules.end()) {
                for (int rule : it->second) {
                }
            } else {
            }
#endif
            //std::cout << "map.count: " << map.count() << std::endl;
            //std::cout << "key: " << num.first << " index: " << num.second << " | ";
            //std::cout << "map[0]" << map[0].key << std::endl;
        }
        if (isCorrect == true) {
            cpage_idx.push_back(idx);
            std::cout << "This page order is correct! idx: " << idx++ << std::endl;
        }
        //std::cout << std::endl;
    }

#if 0

    for (int i = 0; i < cpage_idx.size(); i++) {
        unordered_map<int, int> page = updates[i];
        int middle = page.size() / 2;
        std::cout << "middle: " << middle << std::endl;
        std::cout << "page.size(): " << page.size() << std::endl;
        //std::cout << "Correctly ordered page middle num: " << page.at(middle) << std::endl;
        for (int j=0; j < page.size(); ++j) {
            std::cout << " " << page[j] << std::endl;
        }
        std::cout << std::endl;
    }
#endif


    file.close();
    return 0;
}
/* Main() Ends Here */
