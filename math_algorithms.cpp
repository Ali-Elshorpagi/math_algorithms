#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<pii> vpii;
typedef set<int> si;

#define fast (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define cl(v) ((v).clear())
#define edl '\n'
#define fr(i, x, n) for (ll i(x); i < n; ++i)
#define fl(i, x, n) for (ll i(x); i >= n; --i)
#define fc(it, v) for (auto &(it) : (v))
#define MOD 1000000007

/*-----------------MATH TIPS----------------*/
// ceil(a / b) a, b must be double;
// ceil(a / b) a, b are integers = ((a + b - 1) / b);

// a % b = a - (b * (floor(a / b)));

// (a + b) % c = ((a % c) + (b % c)) % c;
// (a * b) % c = ((a % c) * (b % c)) % c;
// (a - b) % c = ((a % c) - (b % c) + c) % c;
// (a / b) % c = ((a % c) * ((b ^ -1) % c)) % c;

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
    return ((n == 0 || n == 1) ? 1 : (n * factorial(n - 1)));
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
    return (B == 0 ? A : gcd(B, A % B));
}

/*-----------------LCM----------------*/
ll lcm(ll A, ll B)
{
    return A / gcd(A, B) * B;
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

/*-----------------FAST POWER ITERATIVE----------------*/
ll fast_power_iterative(ll b, ll p)
{
    ll ans(1);
    while (p)
    {
        if (p % 2)
            ans *= b;
        b *= b;
        p >>= 1;
    }
    return ans;
}

/*-----------------FAST POWER RECURSIVE----------------*/
ll fast_power_recursive(ll b, ll p)
{
    if (p == 0)
        return 1;
    ll sq(fast_power_recursive(b, p >> 1));
    sq *= sq;
    if (p % 2 == 1)
        sq *= b;
    return sq;
}

/*-----------------MODULUS MULTIPLICATION----------------*/
ll multiplication_mod(ll a, ll b, ll c)
{
    // (a * b) % c;
    return ((a % c) * (b % c)) % c;
}

/*-----------------MODULUS MULTIPLICATION BY ADDITION----------------*/
ll multiplication_mod_by_addition(ll a, ll b, ll m)
{
    // this func convert the multiplication operation to addition operation;
    ll res(0), y(a % m);
    while (b > 0)
    {
        if (b % 2 == 1)
            res = (res + y) % m;
        b >>= 1, y <<= 1, y %= m;
    }
    return res % m;
}

/*-----------------MODULUR EXPONENTIATION----------------*/
ll modular_exponentiation(ll base, ll power, ll m = MOD)
{
    // You can change MOD to any variable that you want and add it to the function parameters;
    ll result(1);
    while (power > 0)
    {
        if (power % 2 == 1)
            result = multiplication_mod_by_addition(result, base, m); // you can use multiplication_mod function;
        base = multiplication_mod_by_addition(base, base, m);         // but this is faster;
        power >>= 1;
    }
    return result;
}

/*-----------------PRIME CHECKING 0----------------*/
bool is_prime_0(ll n, ll k = 500) // Fermat Primality algorithm
{
    if (n <= 4)
        return n == 2 || n == 3;
    fr(i, 1, k + 1)
    {
        ll a(2 + rand() % (n - 3));
        ll res(modular_exponentiation(a, n - 1, n));
        if (res != 1)
            return false;
    }
    return true;
}

/*-----------------PRIME CHECKING 1----------------*/
bool is_prime_1(ll n)
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
    fc(it, p_factors) cout << it << " ";
}

/*-----------------CHECK PERFECT SQUARE----------------*/
bool perfect_square(ll n)
{
    double sqrt_n(sqrt(n));
    if (sqrt_n == int(sqrt_n))
        return true;
    else
        return false;
}

/*-----------------SIEVE OF ERATOSTHENES----------------*/
const ll sze = 1e6 + 10;
void sieve()
{
    bool composite[sze + 1];
    vll prime(sze);
    composite[0] = composite[1] = 1;
    for (ll i(2); i * i <= sze; ++i)
    {
        if (!composite[i])
        {
            for (ll j(i * i); j <= sze; j += i)
                composite[j] = 1;
        }
    }
}

/*-----------------LINEAR SIEVE OF ERATOSTHENES----------------*/
void linear_sieve()
{
    bool composite[sze + 1];
    vll prime(sze);
    composite[0] = composite[1] = 1;
    fr(i, 2, sze + 1)
    {
        if (!composite[i])
            prime.push_back(i);
        for (ll j(0); j < sz(prime) && i * prime[j] <= sze; ++j)
        {
            composite[i * prime[j]] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
}

/*-----------------SEGMENTED SIEVE----------------*/
vb segmented_sieve(ll L, ll R)
{
    ll lim(sqrt(R));
    vb mark(lim + 1, false);
    vll primes;
    fr(i, 2, lim + 1)
    {
        if (!mark[i])
        {
            primes.emplace_back(i);
            for (ll j(i * i); j <= lim; j += i)
                mark[j] = true;
        }
    }
    vb is_composite(R - L + 1, false);
    fc(it, primes)
    {
        for (ll i(max(it * it, (L + it - 1) / it * it)); i <= R; i += it)
            is_composite[i - L] = true;
    }
    if (L == 1)
        is_composite[0] = true;
    return is_composite;
}

/*-----------------PRINT SEGMENTED SIEVE----------------*/
void print_segmented_sieve(ll L, ll R)
{
    vb is_composite_print = segmented_sieve(L, R);
    fr(i, L, R + 1)
    {
        if (!is_composite_print[i - L])
            cout << i << edl;
    }
    cout << edl;
}

int main()
{
    fast;

    return 0;
}
