#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <utility>

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
#define fr(i, x, n) for (ll i(x); i < n; ++i)
#define fl(i, x, n) for (ll i(x); i >= n; --i)
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
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}

/*-----------------COMBINATION----------------*/
ull nCr(ll n, ll r)
{
    if (r > n)
        return 0;
    r = max(r, n - r); // nCr(n,r) = nCr(n,n-r)
    ull ans(1), div(1), i(r + 1);
    while (i <= n)
    {
        ans *= i, ++i;
        ans /= div, ++div;
    }
    return ans;
}

/*-----------------PERMUTATION----------------*/
ull nPr(ll n, ll r)
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

/*-----------------EXTENDED EUCLIDEAN ITERATIVE----------------*/
ll extended_euclidean_iterative(ll a, ll b, ll &x_prev, ll &y_prev)
{
    // a*x + b*y = gcd(a, b); // Bézout's Theorem
    // This algorithm return x, y and gcd(a, b);
    x_prev = 1, y_prev = 0;
    ll x(0), y(1);
    while (b)
    {
        ll q(a / b);
        tie(x, x_prev) = make_tuple(x_prev - q * x, x);
        tie(y, y_prev) = make_tuple(y_prev - q * y, y);
        tie(a, b) = make_tuple(b, a % b);
    }
    return a; // a = gcd(a, b);
}

/*-----------------EXTENDED EUCLIDEAN RECURSIVE----------------*/
ll extended_euclidean_recursive(ll a, ll b, ll &x, ll &y)
{
    // a*x + b*y = gcd(a, b); // Bézout's Theorem
    // This algorithm return x, y and gcd(a, b);
    if (b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    ll x1, y1;
    ll g = extended_euclidean_recursive(a, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b); // a % b = a - (b * (floor(a / b)));
    return g;              // g = gcd(a, b);
}

/*-----------------LCM----------------*/
ll lcm(ll A, ll B)
{
    return A / gcd(A, B) * B;
}

/*-----------------MODULUS MULTIPLICATION----------------*/
ll mul(ll a, ll b, ll c)
{
    // (a * b) % c;
    return ((a % c) * (b % c)) % c;
}

/*-----------------MODULUR EXPONENTIATION----------------*/
ll modular_exponentiation(ll base, ll power, ll m = MOD)
{
    // You can change MOD to any variable that you want and add it to the function parameters;
    ll result(1);
    while (power > 0)
    {
        if (power % 2 == 1)
            result = mul(result, base, m);
        base = mul(base, base, m);
        power >>= 1;
    }
    return result;
}

/*-----------------FAST POWER----------------*/
ll fast_power(ll b, ll p)
{
    ll ans(1);
    while (p)
    {
        if (p % 2)
            ans = (ans * b);
        b *= b;
        p >>= 1;
    }
    return ans;
}

/*-----------------REPOWER----------------*/
ll re_pow(ll b, ll p)
{
    if (p == 0)
        return 1;
    ll sq(re_pow(b, p / 2));
    sq *= sq;
    if (p % 2 == 1)
        sq *= b;
    return sq;
}


/*-----------------FACTORIZATION----------------*/
void factorization(ll n)
{
    for (ll i(1); i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            cout << i << " ";
            if (i * i != n)
                cout << n / i;
            cout << edl;
        }
    }
}

/*-----------------PRIME FACTORIZATION----------------*/
void prime_factorization(ll n)
{
    vi p_factors;
    for (ll i(2); i * i <= n; i++)
    {
        while (n % i == 0)
            n /= i, p_factors.emplace_back(i);
    }
    if (n != 1)
        p_factors.emplace_back(n);
    fc(p_factors) cout << it << " ";
}

/*-----------------PRIME CHECKING----------------*/
bool is_prime(ll n)
{
    if (n <= 1)
        return false;
    for (ll i(2); i * i <= n; ++i)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    fast;

    return 0;
}
