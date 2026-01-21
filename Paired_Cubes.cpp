#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 1000100

/*
    spf[x] = smallest prime factor of x
    Used for fast prime factorization
*/
int spf[MAXN + 1];

/*
    Precompute smallest prime factor (SPF) for all numbers up to MAXN
    Time Complexity: O(N log log N)
*/
void pre()
{
    for (int i = 2; i <= MAXN; i++)
        spf[i] = i;

    spf[0] = 0;
    spf[1] = 1;

    for (int i = 2; i <= MAXN; i++)
    {
        if (spf[i] == i) // i is prime
        {
            for (int j = 2 * i; j <= MAXN; j += i)
            {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
}

/*
    Convert number x into its prime-exponent representation modulo 3

    Example:
        x = 72 = 2^3 * 3^2
        mod 3 => 2^0 * 3^2
        representation = {(3,2)}
*/
vector<pair<int, int>> divisors(int x)
{
    map<int, int> mp;

    // Factorization using SPF
    while (spf[x] != x)
    {
        mp[spf[x]]++;
        x /= spf[x];
    }
    mp[spf[x]]++;

    vector<pair<int, int>> res;

    // Reduce exponents mod 3
    for (auto &it : mp)
    {
        int exp = it.second % 3;
        if (exp != 0)
            res.push_back({it.first, exp});
    }

    return res;
}

/*
    Given reduced representation, compute its complement such that
    representation + complement ≡ 0 (mod 3)
*/
vector<pair<int, int>> getComplement(const vector<pair<int, int>> &v)
{
    vector<pair<int, int>> res;
    for (auto &it : v)
    {
        int need = (3 - it.second) % 3;
        res.push_back({it.first, need});
    }
    return res;
}

/*
    Checks if reduced representation corresponds to a perfect cube
    (i.e., all exponents are 0 mod 3)
*/
bool isPerfectCube(const vector<pair<int, int>> &v)
{
    return v.empty();
}

/*
    Optimized solution
    Time Complexity: O(n log A)
*/
int solve(int n, vector<int> &arr)
{
    /*
        Map:
        key   = reduced prime-exponent representation
        value = count of numbers seen so far with this representation
    */
    map<vector<pair<int, int>>, int> freq;

    int ans = 0;

    /*
        We normalize all perfect cubes and number 1
        to a single artificial key {{1,1}}
        so they can be paired together easily.
    */
    vector<pair<int, int>> cubeKey = {{1, 1}};

    for (int i = 0; i < n; i++)
    {
        int x = arr[i];

        auto rep = divisors(x);
        bool cube = isPerfectCube(rep);

        if (cube || x == 1)
        {
            // Pair current cube/1 with all previous cubes/1s
            ans += freq[cubeKey];
            freq[cubeKey]++;
        }
        else
        {
            auto comp = getComplement(rep);
            ans += freq[comp];
            freq[rep]++;
        }
    }

    return ans;
}

/*
    Brute force cube check
    Used only for stress testing
*/
bool isCube(long long x)
{
    long long r = round(cbrt((long double)x));
    return r * r * r == x;
}

/*
    Brute force O(n^2) solution for verification
*/
int brute(int n, vector<int> &arr)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (isCube(arr[i] * arr[j]))
                cnt++;
    return cnt;
}

/*
    Stress test generator
    Finds counterexample if optimized solution is wrong
*/
void generator()
{
    while (true)
    {
        int n = rand() % 6; // small size for brute force
        vector<int> arr(n);

        for (int i = 0; i < n; i++)
            arr[i] = rand() % 99 + 1;

        int fast = solve(n, arr);
        int slow = brute(n, arr);

        if (fast != slow)
        {
            cout << "Fast: " << fast << "  Slow: " << slow << "\n";
            cout << "Array: ";
            for (int x : arr)
                cout << x << " ";
            cout << "\n";
            return;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    pre();       // SPF preprocessing
    generator(); // Stress testing

    return 0;
}
