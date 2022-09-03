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
    return (A * B) / (gcd(A, B));
}

/*-----------------Fast Power----------------*/
ll mul(ll a, ll b, ll m)
{
    return ((a % m) * (b % m)) % m;
}

ll fast_power(ll base, ll power) // There ara some errors
{
    ll result = 1;
    while (power > 0)
    {
        if (power % 2 == 1)
            result = mul(result, base, MOD);
        base = mul(base, base, MOD);
        power >>= 1;
    }
    return result;
}

int main()
{
    fast;

    return 0;
}