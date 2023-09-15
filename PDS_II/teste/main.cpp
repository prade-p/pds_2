#include <iostream>
#include <cmath>
#include <exception>
#include <stdexcept>

using namespace std;

class AproximarPiNegative : public exception
{
public:
  AproximarPiNegative() {}

  virtual const char *what() const noexcept override
  {
    return "OH MA GOD";
  }
};

class AproximarPi
{
public:
  double nilakantha_recursive(int n, int i = 0, double serie = 0)
  {
    if (n < 0)
    {
      throw AproximarPiNegative();
    }

    if (i == n)
    {
      return 3 + 4 * serie;
    }

    double formula = ((double)pow((-1), i)) / ((double)((2 * i + 2) * (2 * i + 3) * (2 * i + 4)));

    return nilakantha_recursive(n, i + 1, serie + formula);
  }
};

int main()
{
  int n;

  AproximarPi Seriepi;

  cin >> n;

  try
  {
    cout << Seriepi.nilakantha_recursive(n) << endl;
  }
  catch (AproximarPiNegative &e)
  {
    cerr << e.what() << endl;
  }

  return 0;
}