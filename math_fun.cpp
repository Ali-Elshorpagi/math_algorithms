#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <iomanip>
#include <vector>
#include <set>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<char> vc;

#define fast (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define cl(v) ((v).clear())
#define edl '\n'
#define clr(v, d) memset(v, d, sizeof(v))
#define fr(i, x, n) for (ll i = x; i < n; ++i)
#define fc(v) for (auto &it : (v))
#define MOD 1000000007

/*-----------------SUM----------------*/
ll clac_sum(ll a1, ll an, ll n)
{
    // sum all odd from 1 to n = ((n + 1) / 2) * ((n + 1) / 2);
    // sum all even from 1 to n -> (m = n / 2)   --> (sum = m * (m + 1));
    // an = a1 + (n - 1) * d;
    return (((a1 + an) * n) >> 1);
}

/*-----------------FACTORIAL----------------*/
ll factorial(ll n)
{
    if (n == 0)
        return 1;
    ll i(n), fact(1);
    while ((n / i) != n)
    {
        fact *= i;
        --i;
    }
    return fact;
}

/*-----------------COMBINATION----------------*/
ull nCr(int n, int r)
{
    if (r > n)
        return 0;
    r = max(r, n - r); // nCr(n,r) = nCr(n,n-r)
    ull ans(1), div(1), i(r + 1);
    while (i <= n)
    {
        ans *= i;
        ++i;
        ans /= div;
        ++div;
    }
    return ans;
}

/*-----------------PERMUTATION----------------*/
ull nPr(int n, int r)
{
    if (r > n)
        return 0;
    ull p(1), i(n - r + 1);
    while (i <= n)
        p *= i++;
    return p;
}

/*-----------------GCD----------------*/
ll gcd(ll A, ll B)
{
    if (B == 0)
        return A;
    return gcd(B, A % B);
}

/*-----------------LCM----------------*/
ll lcm(ll A, ll B)
{
    return A / gcd(A, B) * B;
}

/*-----------------MODUL MULTIPLICATION----------------*/
ll mul(ll a, ll b, ll c)
{
    // (a * b) % c;
    return ((a % c) * (b % c)) % c;
}

/*-----------------Fast Power----------------*/
ll fast_power(ll base, ll power) // There ara some errors
{
    ll result(1);
    while (power > 0)
    {
        if (power % 2 == 1)
            result = mul(result, base, MOD);
        base = mul(base, base, MOD);
        power >>= 1;
    }
    return result;
}

/*-----------------FACTORIZATION----------------*/
void factorization(ll n)
{
    for (int i = 1; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            cout << i << " ";
            if (i * i != n)
                cout << n / i;
            cout << endl;
        }
    }
}

/*-----------------PRIME FACTORIZATION----------------*/
void prime_factorization(ll n)
{
    vi p_factors;
    for (ll i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
            n /= i, p_factors.emplace_back(i);
    }
    if (n != 1)
        p_factors.emplace_back(n);

    fc(p_factors) cout << it << " ";
}

int main()
{
    fast;

    return 0;
}