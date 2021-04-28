# include <cstdlib>
# include <iostream>
# include <cmath>
# include <ctime>
# include <iomanip>

using namespace std;

const int nTests = 4;
int N[nTests] = { 1000, 10000, 100000, 1000000 };

double cpu_time()
{
    double value;

    value = (double)clock()
        / (double)CLOCKS_PER_SEC;

    return value;
}

int prime_number(int n)
{
    int i;
    int j;
    int prime;
    int total;

    total = 0;

    for (i = 2; i <= n; i++)
    {
        prime = 1;
        for (j = 2; j < (i / 2 + 1); j++)
        {
            if ((i % j) == 0)
            {
                prime = 0;
                break;
            }
        }
        total = total + prime;
    }
    return total;
}

void tests() {
    int i;
    int n;
    int primes;
    double ctime;

    cout << "\n";
    cout << "TEST\n";
    cout << "         N        P          Time\n";

    for (int i = 0; i < nTests; i++) {
        n = N[i];

        ctime = cpu_time();
        primes = prime_number(n);
        ctime = cpu_time() - ctime;

        cout << "  " << setw(8) << n
            << "  " << setw(8) << primes
            << "  " << setw(14) << ctime << "\n";
    }
}

int main() {

    cout << "Primes serial program\n";

    tests();

    cout << "\nFinish.";

    system("pause");

    return 0;
}