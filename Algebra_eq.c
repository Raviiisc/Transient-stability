#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <math.h>
#define PI 3.141593

void newtwork_eq(double **genedat,int ngen,double time,double start_time,double clear_time)//double time,double fault_time,double clear_time)
{


// Machine initial state data

FILE *machine_initials;
//if(time>start_time && time<clear_time)
//{

machine_initials=fopen("init_machine.txt","r");
//}
//else{
//
//    machine_initials=fopen("original_init.txt","r");
//}

//int ngen=3;
int i,j;
double *machine_initialdat[ngen];
for(i=0;i<ngen;i++)
{

    machine_initialdat[i]=(double *)malloc(16*sizeof(double));
}
for(i=0;i<ngen;i++)
{
    for(j=0;j<16;j++)
    {
        fscanf(machine_initials,"%lf",&machine_initialdat[i][j]);

    }
}

//for(i=0;i<3;i++)
//{
//
//    for(j=0;j<16;j++)
//    {
//
//        printf("%lf \t",machine_initialdat[i][j]);
//    }
//    printf("\n");
//}

 double *Eq__=(double *)malloc(ngen*sizeof(double));
 for(i=0;i<ngen;i++)
 {
         Eq__[i]=machine_initialdat[i][7];
 }

 double *Ed__=(double *)malloc(ngen*sizeof(double));
 for(i=0;i<ngen;i++)
 {
         Ed__[i]=machine_initialdat[i][4];
 }
 double *Edc=(double *)malloc(ngen*sizeof(double));
 for(i=0;i<ngen;i++)
 {
         Edc[i]=machine_initialdat[i][3];
 }
 double *delta=(double *)malloc(ngen*sizeof(double));
 for(i=0;i<ngen;i++)
 {
         delta[i]=machine_initialdat[i][14];
 }

 fclose(machine_initials);


 // Xd__data from machine data

  double *Xd__=(double *)malloc(ngen*sizeof(double));
    for (int i=0;i<ngen;i++)
    {
        Xd__[i] = genedat[i][6];
       //printf("%f \n",Xd__[i]);
    }



 // Zbus data

 FILE *real_Z;
 FILE *imag_Z;



 real_Z=fopen("Zreal.txt","r");
 imag_Z=fopen("Zimag.txt","r");
 double *Z_real[ngen];
 double *Z_imag[ngen];
 double complex *Zbus[ngen];

 for(i=0;i<ngen;i++)
{
  Z_real[i]=(double *)malloc(ngen*sizeof(double));
}

 for(i=0;i<ngen;i++)
{
  Z_imag[i]=(double *)malloc(ngen*sizeof(double));
}

 for(i=0;i<ngen;i++)
{
  Zbus[i]=(double complex *)malloc(ngen*sizeof(double complex));
}



 for(i=0;i<ngen;i++)
{

    for(j=0;j<ngen;j++)
    {
        fscanf(real_Z,"%lf",&Z_real[i][j]);
    }
}

 for(i=0;i<ngen;i++)
{

    for(j=0;j<ngen;j++)
    {
        fscanf(imag_Z,"%lf",&Z_imag[i][j]);
    }
}

 for(i=0;i<ngen;i++)
{

    for(j=0;j<ngen;j++)
    {
        Zbus[i][j]=Z_real[i][j]+Z_imag[i][j]*I;
       //  printf("%f+%f*I \t",Z_real[i][j],Z_imag[i][j]);
    }
    //printf("\n");
}
//printf("\n");



// Main code

    double complex *I_gen = (double complex*)malloc(ngen*sizeof(double complex));

    for (int i=0;i<ngen;i++)
    {
        I_gen[i] = ((Eq__[i] + (Ed__[i]+Edc[i])*I)/(0+Xd__[i]*I))*cexp(I*delta[i]); // Kron's frame
    }

    double complex *V_gen = (double complex*)malloc(ngen*sizeof(double complex));
    for (int i=0;i<ngen;i++)
    {
        V_gen[i] = 0+0*I;
    }

    for (int i=0;i<ngen;i++)
    {
        for (int j=0;j<ngen;j++)
        {
                V_gen[i] += Zbus[i][j]*I_gen[j];
        }
    }

    double *Vgen_mag = (double *)malloc(ngen*sizeof(double));
    for (int i=0;i<ngen;i++)
    {
        Vgen_mag[i] = cabs(V_gen[i]);
        printf("%f \t",cabs(I_gen[i]));
    }
   // printf("\n");


// Call differential equation
fclose(real_Z);
fclose(imag_Z);

  diff_eq(ngen,V_gen,Vgen_mag,genedat,time,start_time,clear_time);

}


