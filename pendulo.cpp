#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

double f(double theta0, double omega0, double t);
double g(double theta0, double omega0, double t);

int main(void){
    return 0;
}

double f(double theta0, double omega0, double t, double F){
    return -(omega0*omega0*sin(theta0)) - (gamma*omega0) + (F*sin(omega1*t + delta));
}

double g(double theta0, double omega0, double t){
    return omega0;
}