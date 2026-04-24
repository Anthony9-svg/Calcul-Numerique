#include <cmath>
#include "Methodes.h"
#include <iostream>

float fonction(float x,std::string );
float fonction_p(float x,std::string);

Methodes::Methodes(){}
Methodes::~Methodes(){}

Methodes::Methodes(float a, float b,float eps)
{
  this->a=a;
  this->b=b;
  this->eps=eps;
}

void Methodes::setIntervalle(int a, int b)
{
  this->a=a;
  this->b=b;
}

int Methodes::dichotomie()
{
  float x{a};
  float y{b};
  float diff=fabs(x-y);
  float milieu;
  int iteration=0;
  if (fonction(x,function)*fonction(y,function) >0)
      return 0;
  while (eps<diff)
  {
      diff=fabs(x-y);
      milieu=fonction((x+y)/2,function);
      if (milieu>0)
        y=(x+y)/2;
      else
        x=(x+y)/2;
      iteration++;
  }
  std::cout <<"Solution: "<< x << std::endl; 
  std::cout<< "Dichotomie :" << iteration <<" iterations" <<std::endl; 
  return 1;
}

void Methodes::setFunction(std::string function)
{
  this->function=function;
}

void Methodes::newton_raphson()
{
  int iteration=0;
  float x_n=2;
  float x_n1=x_n-(fonction(x_n,function)/fonction_p(x_n,function));
  float diff=fabs(x_n1-x_n);
  while(true)
  {
    x_n1=x_n-(fonction(x_n,function)/fonction_p(x_n,function));
    if (fabs(x_n1-x_n)<eps)
    {
      break;
    }
    x_n=x_n1;
    iteration++;
  }
  std::cout << "Solution: "<< x_n1 <<std::endl;
  std::cout<< "Newton-Raphson :" << iteration <<" iterations" <<std::endl; 
}
    
float fonction_p(float x,std::string function)
{
  return (fonction(x+0.001,function)-fonction(x,function))/0.001;
}

float fonction(float arg,std::string function)
{
  mu::Parser p;
  double x;
  p.DefineVar("x", &x);
  p.SetExpr(function);
  x=arg;
  return p.Eval();
}
