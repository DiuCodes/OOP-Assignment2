#include <iostream>

using namespace std;
void binaryPrint(int n)
{
  if (n > 0)
  {
    binaryPrint(n >> 1); // Right shift n by 1
    cout << (n & 1);     // Print the least significant bit
  }
  else
  {
    cout << 0; // Base case: print a single zero when n is 0
  }
}

int main()
{
  int n = 0;
  binaryPrint(n);
  cout << endl;

  n = 4;
  binaryPrint(n);
  cout << endl;

  n = 27;
  binaryPrint(n);
  cout << endl;

  return 0;
}