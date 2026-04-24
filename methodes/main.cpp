#include "Methodes.h"
#include <iostream>
int main()
{
  Methodes a(0.1,3,0.001);
  a.setFunction("log(x)");
  a.newton_raphson();
  std::cout <<std::endl;
  a.dichotomie();
  return 0;
}
