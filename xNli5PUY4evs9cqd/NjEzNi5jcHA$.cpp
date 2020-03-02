#pragma GCC optimize(2)
#pragma GCC optimize(3)

#include "bits/stdc++.h"

#define mem(x) memset((x), 0, sizeof((x)))
#define il __attribute__((always_inline))

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

#if __cplusplus > 201403L
#define R
#else
#define R register
#endif

#if __cplusplus >= 201103L
#define C constexpr
#define H_V
#else
#define C const
#endif
#define for_each(con, it) for (__typeof(con.begin()) it = con.begin(); it != con.end(); it++)

namespace _c
{
C double pi = 3.141592653589793;
namespace min
{
C int i8 = -128;
C int i16 = -32768;
C int i = -2147483647 - 1;
C ll l = -9223372036854775807LL - 1;
} // namespace min
namespace max
{
C int i8 = 127;
C int i16 = 32767;
C int i = 2147483647;
C ll l = 9223372036854775807LL;
} // namespace max
} // namespace _c

namespace _f
{
template <typename Tp>
inline Tp gcd(Tp x, Tp y)
{
    while (y != 0)
    {
        Tp t = x % y;
        x = y;
        y = t;
    }
    return x;
}
template <typename Tp>
inline Tp abs(const Tp &a)
{
    return a > 0 ? a : -a;
}
template <typename Bp, typename Ep>
inline Bp pow(Bp a, Ep b)
{
    R Bp res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res *= a;
        }
        a *= a;
        b >>= 1;
    }
    return res;
}
template <typename Bp, typename Ep, typename Mp>
inline Mp pow(Bp a, Ep b, const Mp &m)
{
    a %= m;
    R Mp res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res = ((ll)res * a) % m;
        }
        a = ((ll)a * a) % m;
        b >>= 1;
    }
    return res % m;
}
} // namespace _f

namespace io
{
template <typename Tp>
inline void read(Tp &x)
{
    static bool neg;
    static char c;
    x = 0, neg = 0, c = getchar();
    for (; !isdigit(c); c = getchar())
    {
        if (c == '-')
        {
            neg = 1;
        }
    }
    for (; isdigit(c); c = getchar())
    {
        x = x * 10 + c - '0';
    }
    if (neg)
    {
        x = -x;
    }
}
template <typename Tp>
inline Tp read()
{
    R Tp res;
    read(res);
    return res;
}
template <typename Tp>
inline void readln(const Tp first, const Tp last)
{
    for (R Tp it = first; it != last; it++)
    {
        read(*it);
    }
}
template <typename Tp>
inline void _write(Tp x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    if (x > 9)
    {
        _write(x / 10);
    }
    putchar(x % 10 + '0');
}
template <typename Tp>
inline void write(const Tp &x, const char &sep = ' ')
{
    _write(x);
    putchar(sep);
}
template <typename Tp>
inline void writeln(const Tp &x)
{
    write(x, '\n');
}
template <typename Tp>
inline void writeln(const Tp first, const Tp last, const char &sep = ' ', const char &ends = '\n')
{
    for (R Tp it = first; it != last; it++)
    {
        write(*it, sep);
    }
    putchar(ends);
}
#ifdef H_V
template <typename Tp, typename... Args>
inline void read(Tp &x, Args &... args)
{
    read(x);
    read(args...);
}
#endif
} // namespace io

#include "bits/extc++.h"
using namespace __gnu_pbds;

C int OFFSET = 1e8;

tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> t;
unordered_map<int, int> mp;

int n;

int main()
{
    io::read(n);

    for (R int _ = 0, op, x, last; _ < n; _++)
    {
        io::read(op, x);
        x ^= last;
        printf("%d", x);
        return 0;

        switch (op)
        {
        case 1:
        {
            x += OFFSET;
            t.insert((ll)x << 32 | (mp[x]++));
            break;
        }

        case 2:
        {
            x += OFFSET;
            t.erase((ll)x << 32 | (--mp[x]));
            break;
        }

        case 3:
        {
            x += OFFSET;
            last = (int)t.order_of_key((ll)x << 32) + 1;
            io::writeln(last);
            break;
        }

        case 4:
        {
            R int ret = *t.find_by_order(x - 1) >> 32;
            last = ret - OFFSET;
            io::writeln(last);
            break;
        }

        case 5:
        {
            x += OFFSET;
            R int ret = *prev(t.lower_bound((ll)x << 32)) >> 32;
            last = ret - OFFSET;
            io::writeln(last);
            break;
        }

        case 6:
        {
            x += OFFSET + 1;
            R int ret = *t.lower_bound((ll)x << 32) >> 32;
            last = ret - OFFSET;
            io::writeln(last);
            break;
        }

        default:
        {
            break;
        }
        }
    }
}