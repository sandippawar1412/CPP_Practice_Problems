/* O(log(n))
*/
#include <iostream>
using namespace std;

long long m_sqrt_r(long long inp, long long l, long long h)
{
    if (l > h)
        return h;
    long long mid = (l + h) / 2;
    long long sqr = mid * mid;
    //if (sqr == inp)
    //    return mid;
    if (sqr <= inp)
        return m_sqrt_r(inp, mid + 1, h);
    return m_sqrt_r(inp, l, mid - 1);
}

long long m_sqrt(long long inp)
{
    return m_sqrt_r(inp, 1, inp / 2);
}

int main()
{
    long long inp;
    cin >> inp;
    cout << m_sqrt(inp) << endl;
}
