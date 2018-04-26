//
//  Onda.cpp
//  
//
//  Created by Nicolas Felipe Vergara Duran on 26/04/18.
//

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <math.h>
using namespace std;
#define PI (3.141592653589793)
double* linspace(double in, double end, int size){
    double* vector = new double[size];
    double h=(end-in)/(size-1);
    double point=in;
    for(int i=0;i<size;i++){
        vector[i]=point;
        point+=h;
    }
    return vector;
}
void EcuacionOnda(){
    double delta_t=0.01;
    double C=0.1;
    double T=5;
    double delta_x=0.01;
    double max_x=1;
    double min_x=0;
    double k=pow((C*delta_t)/delta_x,2);
    int size_x=((max_x-min_x)/delta_x)+1;
    int size_t=T/delta_t;
    double* x=linspace(min_x,max_x,size_x);
    double* t=linspace(0,T,size_t);
    double* Solucion_old = new double[size_x];
    double* Solucion_new = new double[size_x];
    double* Solucion_reallyOld = new double[size_x];
    //se crea la condición inicial
    
    for(int i=0; i<size_x;i++){
        Solucion_old[i]=sin(x[i]*(2*PI));
        Solucion_reallyOld[i]=sin(x[i]*(2*PI));
        cout<<t[0]<<" "<<x[i]<<" "<<Solucion_old[i]<<endl;
    }
    int i=1;
    while(Solucion_old[size_x/4]>-0.95){
        for(int j=0; j<size_x;j++){
            if(j!=0 && j!=size_x-1){
                Solucion_new[j]=2*Solucion_old[j]-Solucion_reallyOld[j]+(k*(Solucion_old[j+1]-2*Solucion_old[j]+Solucion_old[j-1]));
            }
            cout<<t[i]<<" "<<x[j]<<" "<<Solucion_new[j]<<endl;
        }
        for(int j=0; j<size_x;j++){
            Solucion_reallyOld[j]=Solucion_old[j];
            Solucion_old[j]=Solucion_new[j];
        }
        i++;
    }
    
}
int main(){
    EcuacionOnda();
    return 0;
}
