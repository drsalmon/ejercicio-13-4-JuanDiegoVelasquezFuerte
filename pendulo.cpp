#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

double f(double theta, double omega0, double w0, double t, double F, double delta);
double g(double theta, double omega0, double t);

int main(void){
    ofstream outfile;  
    double pi = 4*atan(1);
    double g = 9.8;
    double L = 5;
    double T = 2*pi/sqrt(g/L);
    double t = 0.0;
    double t_max = 10*T;
    double delta_t = 0.01;
    double theta1_init = 0; 
    double theta2_init = 0.2;
    double w0 = sqrt(g/L);
    double w = 1.0;
    double omega1 = 0.2;
    double omega2 = 0.1;
    double F1 = 4.3;
    double F2 = 1.2;
    double gamma = 0.2;
    double delta = 1.0;
    int N = (t_max/delta_t) + 1;
    double theta1 [N];
    double theta2 [N];
    int i;
    
    theta1 [0] = theta1_init;
    theta2 [0] = theta2_init;
    
    outfile.open("datos.dat");
    
    while (t < t_max){
        for (i = 0 ; i < N; i++){
            omega1 = omega1 + delta_t*(-(w0*w0)*sin(theta1[i]) + gamma*omega1 + F1*sin(w*i*delta_t + delta));
            theta1 [i+1] = theta1[i] + omega1*delta_t;
            omega2 = omega2 + delta_t*(-(w0*w0)*sin(theta2[i]) + gamma*omega2 + F1*sin(w*i*delta_t + delta));
            theta2 [i+1] = theta2[i] + omega2*delta_t;        
        }
        
        for (i = 0; i < N; i++){
            outfile << t << " " << theta1[i] << " " << theta2[i] << " ";
            outfile << "\n";
        }
        
        t = t + delta_t;
    }
    outfile.close();
   
    return 0;
}

