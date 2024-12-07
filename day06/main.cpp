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

// Directions for Up, Right, Down, Left
const vector<pair<int, int>> directions = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

// Helper function to print the grid
void printGrid(const vector<vector<char>>& grid) {
    std::cout << "----------------------" << std::endl;
    for (const auto& row : grid) {
        for (char c : row) {
            cout << c;
        }
        cout << endl;
    }
    std::cout << "----------------------" << std::endl;
}

// Function to simulate the guard's patrol
void part1(vector<vector<char>>& grid, int startX, int startY) {
    int x = startX, y = startY;  // Guard's current position
    int dir = 0;  // Start facing up (index 0 in directions)
    int n = grid.size(), m = grid[0].size();

    // Set to track visited positions
    set<pair<int, int>> visited;

    while (true) {
        // If the current position is valid and not visited yet, mark it as visited
        if (visited.find({x, y}) == visited.end()) {
            visited.insert({x, y});
            grid[x][y] = 'X';  // Mark the position as visited
        }

        // Try to move forward in the current direction
        int nx = x + directions[dir].first;
        int ny = y + directions[dir].second;

        // nx < 0 || ny < 0 || nx >= n || ny >= m
        // Check if the new position is out of bounds
        if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
            // it means we arrived
            std::cout << "we arrived" << std::endl;
            std::cout << "x: " << x << " y: " << y << std::endl;
            printGrid(grid);
            break;
        } else if (grid[nx][ny] == '#') {
            // Turn right (90 degrees)
            dir = (dir + 1) % 4;
        } else {
            // Move forward
            x = nx;
            y = ny;
        }

        // Check if the guard has left the grid
        if (x < 0 || y < 0 || x >= n || y >= m) {
            break;
        }
        //std::cout << "x: " << x << " y: " << y << std::endl;
        //printGrid(grid);
        //usleep(100000);
    }

    std::cout << "Total visited cell: " << visited.size() << std::endl;
}

/* Main()  function */

int main() {
    // Open the file
    //ifstream inputFile("../input_sample.txt");
    ifstream file("../input.txt");

    //Check if the file was opened successfully
    if (!file) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    // Read the grid from the file
    string line;
    vector<vector<char>> grid;

    int startX = -1, startY = -1;  // Variables to store the guard's starting position

    // Read the file line by line
    while (getline(file, line)) {
        vector<char> row(line.begin(), line.end());
        grid.push_back(row);

        // Find the guard's position (indicated by '^')
        for (int i = 0; i < row.size(); ++i) {
            if (row[i] == '^') {
                startX = grid.size() - 1;  // Current row number
                startY = i;                // Column number of the guard
                break;
            }
        }
    }

    // Close the file
    file.close();

    // Output the grid and the starting position
    cout << "Grid loaded from file:" << endl;
    for (const auto& row : grid) {
        for (char c : row) {
            cout << c;
        }
        cout << endl;
    }

    // Print the starting position of the guard
    if (startX != -1 && startY != -1) {
        cout << "Guard starting position: (" << startX << ", " << startY << ")" << endl;
    } else {
        cout << "Guard not found in the grid!" << endl;
    }

    part1(grid, startX, startY);

    return 0;
}

/* Main() Ends Here */
