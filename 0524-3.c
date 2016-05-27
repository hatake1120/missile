#include <stdio.h>
#include <math.h>
#include <stdlib.h>
struct robo {
	double x;
	double y;
	double vx;
	double vy;
	double v;
	double dv;
	double dvx;
	double dvy;
	double angle;
	double omega;
	double domega;
	double zx;
	double zy;
	double z;
	double ramd;
	double ramd0;
};

double integ(double v, double dv, double h, double sum){
	return sum+(v+dv)*h*0.5;
}


main(){
	double pi,h,X,Y ;
	short a,i,n;
	a=0.0;
	n=2.0;
	pi=3.1415926535;
	struct robo drone[2];
	drone[0].x=1000.0; 
	drone[1].x=0.0;
	drone[0].y=0.0;
	drone[1].y=0.0;
	h=0.01;
	drone[0].angle=0.0;
	drone[0].v=30;
	drone[1].v=300;
	drone[0].omega=pi/2;	
	drone[0].dv=drone[0].v;
	drone[0].dvx=0;
	drone[0].dvy=0;
	drone[0].domega=0;
	drone[1].domega=0;
	drone[1].ramd0=0;
	drone[1].dvx=1;
	drone[1].dvy=1;
	

	
	for(i=0; i<400; i++){
		printf("%f %f %f %f %f\n",drone[0].x,drone[0].y,drone[1].x,drone[1].y,drone[1].ramd);
		drone[0].omega=pi/2.0;
		drone[0].angle=drone[0].angle+(drone[0].omega+drone[0].domega)*h*0.5;
		drone[0].vx=drone[0].v*cos(drone[0].angle);
		drone[0].vy=drone[0].v*sin(drone[0].angle);
		drone[0].x=drone[0].x+(drone[0].vx+drone[0].dvx)*h*0.5;
		drone[0].y=drone[0].y+(drone[0].vy+drone[0].dvy)*h*0.5;
		drone[0].dv=drone[0].v;


		if(i!=0){
			
		  if(drone[0].y-drone[1].y>=0){

                	drone[1].ramd=atan2(Y=drone[0].y-drone[1].y,X=drone[0].x-drone[1].x);
			drone[1].omega=n*((drone[1].ramd-drone[1].ramd0))/h;

       			drone[1].ramd=drone[1].ramd+(drone[1].omega+drone[1].domega)*h*0.5;
			drone[1].vx=drone[1].v*cos(drone[1].ramd);
        		drone[1].vy=drone[1].v*sin(drone[1].ramd);

        		drone[1].x=drone[1].x+(drone[1].vx+drone[1].dvx)*h*0.5;
        		drone[1].y=drone[1].y+(drone[1].vy+drone[1].dvy)*h*0.5;
			}
			
	          else{
                        drone[1].ramd=M_PI+(M_PI+atan2(Y=drone[0].y-drone[1].y,X=drone[0].x-drone[1].x));
                        drone[1].omega=n*((drone[1].ramd-drone[1].ramd0))/h;

                        drone[1].ramd=drone[1].ramd+(drone[1].omega+drone[1].domega)*h*0.5;
                        drone[1].vx=drone[1].v*cos(drone[1].ramd);
                        drone[1].vy=drone[1].v*sin(drone[1].ramd);

                        drone[1].x=drone[1].x+(drone[1].vx+drone[1].dvx)*h*0.5;
                        drone[1].y=drone[1].y+(drone[1].vy+drone[1].dvy)*h*0.5;
                        }
                
			
			}
			
			drone[1].zx=(drone[0].x-drone[1].x)*(drone[0].x-drone[1].x);
			drone[1].zy=(drone[0].y-drone[1].y)*(drone[0].y-drone[1].y);
			drone[1].z=sqrt(drone[1].zx+drone[1].zy);
				
			
			drone[0].dvx=drone[0].vx;
                	drone[0].dvy=drone[0].vy;
                	drone[0].domega=drone[0].omega;
			drone[1].dvx=drone[1].vx;
                	drone[1].dvy=drone[1].vy;
                	drone[1].ramd0=drone[1].ramd;
                	drone[1].domega=drone[1].omega;
			
			if(drone[1].z<=10) break;
	
	}

}
