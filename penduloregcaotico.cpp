# include <iostream>
# include <cmath>
# include <fstream>

using namespace std;

int main(void){  
    double pi = 4*atan(1);
    double w0 = 1.0;
    double T = 2*pi/w0;
    double tiempo = 0.0;
    double tiempo_max = 10*T;
    double delta_tiempo = 0.01;
    double theta1_inicial = 0.1; 
    double theta2_inicial = 0.15;
    double w = 2.0;
    double omega1 = 0.2;
    double omega2 = 0.1;
    double F1 = 4.0;
    double F2 = 2.0;
    double gamma = 0.2;
    double delta = 1.0;
    int N = (tiempo_max/delta_tiempo) + 1;
    double theta1 [N];
    double theta2 [N];
    ofstream outfile; 
    int i;
    
    theta1 [0] = theta1_inicial;
    theta2 [0] = theta2_inicial;
    
    outfile.open("angulos.dat");
    
    while (tiempo < tiempo_max){
        for (i = 0 ; i < N; i++){
            omega1 = omega1 + delta_tiempo*(-(w0*w0)*sin(theta1[i]) + gamma*omega1 + F1*sin(w*i*delta_tiempo + delta));
            theta1 [i+1] = theta1[i] + omega1*delta_tiempo;
            omega2 = omega2 + delta_tiempo*(-(w0*w0)*sin(theta2[i]) + gamma*omega2 + F1*sin(w*i*delta_tiempo + delta));
            theta2 [i+1] = theta2[i] + omega2*delta_tiempo;  
            outfile << theta1[i] << " " << theta2[i] << " ";
            outfile << "\n";
        }
        
        tiempo = tiempo + delta_tiempo;
    }
    outfile.close();
   
    return 0;
}

////////////////////////////////////////////////

/*const double w0 =1.0; 
const double gamma =0.2;
const double h =0.1;
const double delta =1.0;
const double F =0.4;
const double w =0.2;
const int N =1000;
double g(double theta0 , double omega0 , double t);
double f(double theta0 , double omega0 , double t);
int main (void){
 double omega =1;
 double theta =0;
  for (int i =0; i < N; i ++){
  std::cout<<i*h<<"\t "<<theta<<"\ t "<<omega<<std::endl;
  omega = omega +h* f(theta , omega , i*h);
  theta = theta +h* g(theta , omega , i*h);
  }
 return 0;
}
double g( double theta0 , double omega0 , double t){
return omega0;
}
double f( double theta0 , double omega0 , double t){
return -w0 * w0 * sin ( theta0 )- gamma * omega0 + F* sin (w*t + delta );
}

*/