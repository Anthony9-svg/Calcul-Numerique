#include <muParser.h>
class Methodes
{
  public:
    int dichotomie();
    void newton_raphson();
    void setIntervalle(int a, int b);
    Methodes();
    ~Methodes();
    void setFunction(std::string function);
    Methodes(float a,float b,float eps);
  private:
    float a;
    float b;    
    float eps;
    std::string function;
};

