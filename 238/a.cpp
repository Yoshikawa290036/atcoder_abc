// coding with UTF-8
#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <sstream>
#include <stdio.h>
#include <time.h>
#include <omp.h>

typedef long long ll;
using namespace std;

void mydo()
{
    ll i, j;
    ll size = 1000000;
    long long tmp, tmp2, tmp3, tmp4, tmp5, tmp6;

#ifdef _OPENMP
#pragma omp parallel for private(tmp,i,j)
#endif
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            tmp = i * j + i + j + 4 + (i + 1) * 2 - 11;
        }
    }
}

void test()
{
#ifdef _OPENMP
#pragma omp parallel for
#endif
    for (size_t i = 0; i < 15; i++)
    {
        cout <<  i << "aiueo" << endl;
        // sleep(1);
    }
}

int main(int argc, char const *argv[])
{
    clock_t start = clock();
    // test();
    mydo();
    clock_t end = clock();
    const double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    cout << time << endl;
    return 0;
}
