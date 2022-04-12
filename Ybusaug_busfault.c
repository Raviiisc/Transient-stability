#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <math.h>
#define PI 3.141593

void Ybusaug_fault(int nbus,int nload,int ngen,double **loaddat,double **genedat,double **busdat,int busno)
{
    FILE *Yreal;
    FILE *Yimag;

    Yreal = fopen("yreal.txt","r");
    Yimag = fopen("yimag.txt","r");


   int i,j;
//   for(i=0;i<ngen;i++)
//   {
//
//       for(j=0;j<19;j++)
//       {
//
//           printf("%f \t",genedat[i][j]);
//       }
//       printf("\n");
//   }

// Form Y bus again

double *Ybus_real[nbus];
    for (int i=0;i<nbus;i++)
    {
        Ybus_real[i] = (double *)malloc(nbus*sizeof(double));
    }

  double *Ybus_imag[nbus];
    for (int i=0;i<nbus;i++)
    {
        Ybus_imag[i] = (double *)malloc(nbus*sizeof(double));
    }

    for (int i=0;i<nbus;i++)
    {
        for (int j=0;j<nbus;j++)
        {
            fscanf(Yreal,"%lf",&Ybus_real[i][j]);
        }
    }
 for (int i=0;i<nbus;i++)
    {
        for (int j=0;j<nbus;j++)
        {
            fscanf(Yimag,"%lf",&Ybus_imag[i][j]);
        }
    }

//    for(i=0;i<nbus;i++)
//    {
//
//        for(j=0;j<nbus;j++)
//        {
//
//            printf("%lf \t",Ybus_imag[i][j]);
//        }
//        printf("\n");
//    }

//
  double complex *Ybus_complex[nbus];
    for (int i=0;i<nbus;i++)
    {
        Ybus_complex[i] = (double complex *)malloc(nbus*sizeof(double complex));
    }
     for (int i=0;i<nbus;i++)
    {
        for (int j=0;j<nbus;j++)
        {
            Ybus_complex[i][j]=Ybus_real[i][j]+Ybus_imag[i][j]*I;
        }
    }

    int busfault=busno-1;

    for(int i=0;i<nbus;i++)
    {

        for(int j=0;j<nbus;j++)
        {
            if((i==busfault)||(j==busfault))
            {
                Ybus_complex[i][j]=pow(10,20)-pow(10,20)*I; // setting admittance to infinity
            }
        }
    }
//       for(i=0;i<nbus;i++)
//    {
//
//        for(j=0;j<nbus;j++)
//        {
//
//              printf("%lf+I*%lf \t",creal(Ybus_complex[i][j]),cimag(Ybus_complex[i][j]));
//        }
//        printf("\n");
//    }


//
  fclose(Yreal);
  fclose(Yimag);

  double *xd__=(double *)malloc(ngen*sizeof(double)); // Xd'' data

  for(i=0;i<ngen;i++)
  {

      xd__[i]=genedat[i][6];

  }

//  // load data

   double *voltage_mag=(double *)malloc(nbus*sizeof(double));
    for (int i=0;i<nbus;i++)
    {
        voltage_mag[i] = busdat[i][2];

    }
  double *Pl=(double *)malloc(nbus*sizeof(double));
    for (int i=0;i<nbus;i++)
    {
        Pl[i] = busdat[i][6];

    }

      double *Ql=(double *)malloc(nbus*sizeof(double));
    for (int i=0;i<nbus;i++)
    {
        Ql[i] = busdat[i][7];

    }

       double complex *Ybus_lg[nbus];

       for(i=0;i<nbus;i++)
       {

           Ybus_lg[i]=(double complex *)malloc(nbus*sizeof(double complex));
       }



     for (int i=0;i<nbus;i++)
    {
        for (int j=0;j<nbus;j++)
        {
            if(i==j)
            {
                Ybus_lg[i][j] = ((Pl[i]-Ql[i]*I)/(voltage_mag[i]*(voltage_mag[i])));
            }
            else
            {
                Ybus_lg[i][j] = 0;//0.0+0*I;
            }
        }
    }


    for (int i=0;i<ngen;i++)
    {
        for (int j=0;j<ngen;j++)
        {
            if(i==j)
            {
                Ybus_lg[i][j] += 1/(0+xd__[i]*I);
            }
        }
    }


for(i=0;i<nbus;i++)
{
for(j=0;j<nbus;j++)
{

Ybus_lg[i][j]=Ybus_lg[i][j]+Ybus_complex[i][j];
    }

}

          for(i=0;i<nbus;i++)
   {

       for(j=0;j<nbus;j++)
       {

        // printf("%lf+I*%lf \t",creal(Ybus_lg[i][j]),cimag(Ybus_lg[i][j]));
       }
       //printf("\n");
   }


double complex *Ybuslg_A[ngen];

for(i=0;i<ngen;i++)
{

    Ybuslg_A[i]=(double complex *)malloc(ngen*sizeof(double complex));
}

for(i=0;i<ngen;i++)
{

    for(j=0;j<ngen;j++)
    {

        Ybuslg_A[i][j]=Ybus_lg[i][j];
    }
}

double complex *Ybuslg_B[ngen];

for(i=0;i<ngen;i++)
{

    Ybuslg_B[i]=(double complex *)malloc((nbus-ngen)*sizeof(double complex));
}

for(i=0;i<ngen;i++)
{

    for(j=0;j<(nbus-ngen);j++)
    {

        Ybuslg_B[i][j]=Ybus_lg[i][j+(ngen)];
      //  printf("(%lf)+(%lf*I) \t",creal(Ybuslg_B[i][j]),cimag(Ybuslg_B[i][j]));
    }
   // printf("\n");
}

double complex *Ybuslg_C[nbus-ngen];

for(i=0;i<(nbus-ngen);i++)
{

    Ybuslg_C[i]=(double complex *)malloc((ngen)*sizeof(double complex));
}

for(i=0;i<(nbus-ngen);i++)
{

    for(j=0;j<(ngen);j++)
    {

        Ybuslg_C[i][j]=Ybus_lg[i+ngen][j];
      //  printf("(%lf)+(%lf*I) \t",creal(Ybuslg_C[i][j]),cimag(Ybuslg_C[i][j]));
    }
 //   printf("\n");
}

double complex *Ybuslg_D[nbus-ngen];

for(i=0;i<(nbus-ngen);i++)
{

    Ybuslg_D[i]=(double complex *)malloc((nbus-ngen)*sizeof(double complex));
}

for(i=0;i<(nbus-ngen);i++)
{

    for(j=0;j<(nbus-ngen);j++)
    {

        Ybuslg_D[i][j]=Ybus_lg[i+ngen][j+ngen];
   //  printf("%f+%f*I \t",creal(Ybuslg_D[i][j]),cimag(Ybuslg_D[i][j]));
    }
   // printf("\n");
}

// Yred=YA-YB*(inv(YD))*YC

// YD inverse

double complex *Ybuslg_Dinv[nbus-ngen];

for(i=0;i<(nbus-ngen);i++)
{

    Ybuslg_Dinv[i]=(double complex *)malloc(2*(nbus-ngen)*sizeof(double complex));
}

 for (int i = 0; i < (nbus-ngen); i++)
    {

        for (int j = 0; j < 2 * (nbus-ngen); j++) {

            // Add '1' at the diagonal places of
            // the matrix to create a identity matrix
            if (j == (i + (nbus-ngen)))
            {


             Ybuslg_Dinv[i][j] = 1;
        }
        else if(j<(nbus-ngen))
        {
            Ybuslg_Dinv[i][j]=creal(Ybuslg_D[i][j])+cimag(Ybuslg_D[i][j])*I;

        }
        else{
            Ybuslg_Dinv[i][j]=0;

        }

    }
    }



int order=nbus-ngen;

 double complex temp;
    for (int i = 0; i < (order); i++)
    {
        for (int j = 0; j < (order); j++)
        {
            if (j != i)
            {
                temp = Ybuslg_Dinv[j][i] / Ybuslg_Dinv[i][i];
                for (int k = 0; k < (2 * (order)); k++)
                {
                    Ybuslg_Dinv[j][k] -= Ybuslg_Dinv[i][k] * temp;
                }
            }
        }
    }
    for (int i = 0; i < (order); i++)
    {
        temp =Ybuslg_Dinv[i][i];
        for (int j = 0; j < (2 * (order)); j++)
        {
            Ybuslg_Dinv[i][j] = Ybuslg_Dinv[i][j] / temp;
        }
    }

 double complex *YD_inv[(order)];

for (int i=0;i<(order);i++)
    {
        YD_inv[i] = (double complex *)malloc((order)*sizeof(double complex));
    }

    for (int i=0;i<(order);i++)
    {
        for (int j=0;j<(order);j++)
        {
            YD_inv[i][j] =  Ybuslg_Dinv[i][j+(nbus-ngen)];
          //  printf("%lf+%lf*I\t",creal(YD_inv[i][j]),cimag(YD_inv[i][j]));
        }
   // printf("\n");
    }

////YDinv*YC
//

 double complex *Y_1[(nbus-ngen)];
    for (int i=0;i<(nbus-ngen);i++)
    {
        Y_1[i] = (double complex *)malloc(ngen*sizeof(double complex));
    }

    for (int i=0;i<(nbus-ngen);i++)
    {
        for (int j=0;j<ngen;j++)
        {
            Y_1[i][j] = 0+0*I;
        }
    }

    for (int i=0;i<(nbus-ngen);i++)
    {
        for (int j=0;j<ngen;j++)
        {
            for(int k=0;k<(nbus-ngen);k++)
            {
                Y_1[i][j] += YD_inv[i][k]*Ybuslg_C[k][j];
            }
        }
    }

    double complex *Y_2[ngen];
    for (int i=0;i<ngen;i++)
    {
        Y_2[i] = (double complex *)malloc(ngen*sizeof(double complex));
    }

    for (int i=0;i<ngen;i++)
    {
        for (int j=0;j<ngen;j++)
        {
            Y_2[i][j] = 0+0*I;
        }
    }

    for (int i=0;i<ngen;i++)
    {
        for (int j=0;j<ngen;j++)
        {
            for(int k=0;k<(nbus-ngen);k++)
            {
                Y_2[i][j] += Ybuslg_B[i][k]*Y_1[k][j];
            }
        }
    }

    double complex *Y_red[ngen];
    for (int i=0;i<ngen;i++)
    {
        Y_red[i] = (double complex *)malloc(ngen*sizeof(double complex));
    }

    for (int i=0;i<ngen;i++)
    {
        for (int j=0;j<ngen;j++)
        {
            Y_red[i][j] = Ybuslg_A[i][j] - Y_2[i][j];
          // printf("(%lf)+(%lf*I) \t",creal(Y_red[i][j]),cimag(Y_red[i][j]));
        }
      // printf("\n");
    }
    Zbus(Y_red,ngen);

}
