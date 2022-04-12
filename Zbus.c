#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<complex.h>

void **Zbus(double complex **Yred,int ngen)
{


double complex *Zinv[ngen];
int i,j;
//for(i=0;i<ngen;i++)
//{
//
//    for(j=0;j<ngen;j++)
//    {
//
//printf("%f+%f*I \t",creal(Yred[i][j]),cimag(Yred[i][j]));
//    }
//    printf("\n");
//}
 for(i=0;i<(ngen);i++)
{

    Zinv[i]=(double complex *)malloc(2*(ngen)*sizeof(double complex));
}

 for (int i = 0; i < (ngen); i++)
    {

        for (j = 0; j<2*(ngen); j++)
            {

            // Add '1' at the diagonal places of
            // the matrix to create a identity matrix
            if (j ==(i+(ngen)))
            {


             Zinv[i][j] = 1+0*I;
        }
        else if(j<(ngen))
        {
            Zinv[i][j]=Yred[i][j];//creal(Yred[i][j])+cimag(Yred[i][j])*I;

        }
        else{
            Zinv[i][j]=0+0*I;

        }
        }
    }

double complex temp;
    for (int i = 0; i < ngen; i++)
    {
        for (int j = 0; j < ngen; j++)
        {
            if (j!=i)
            {
                temp = Zinv[j][i] / Zinv[i][i];
                for (int k = 0; k < (2 * ngen); k++)
                {
                    Zinv[j][k] -= Zinv[i][k]*temp;
                }
            }
        }
    }
    for (int i = 0; i < ngen; i++)
    {
        temp = Zinv[i][i];
        for (int j = 0; j < (2*ngen); j++)
        {
            Zinv[i][j] = Zinv[i][j]/temp;
        }
    }

    FILE *zbusfile;
    FILE *Zreal;
    FILE *Zimag;
    Zreal=fopen("Zreal.txt","w");
    Zimag=fopen("Zimag.txt","w");
    zbusfile=fopen("Zbusfile.txt","w");

     double complex *Z_bus[(ngen)];
     double *Zbus_real[ngen];
       double *Zbus_imag[ngen];
for (int i=0;i<(ngen);i++)
    {
        Z_bus[i] = (double complex *)malloc((ngen)*sizeof(double complex));
    }
for (int i=0;i<(ngen);i++)
    {
        Zbus_real[i] = (double complex *)malloc((ngen)*sizeof(double complex));
    }
  for (int i=0;i<(ngen);i++)
    {
        Zbus_imag[i] = (double complex *)malloc((ngen)*sizeof(double complex));
    }

    for (int i=0;i<(ngen);i++)
    {
        for (int j=0;j<(ngen);j++)
        {
            Z_bus[i][j] =  Zinv[i][j+(ngen)];
        //    printf("%lf+%lf*I \t",creal(Z_bus[i][j]),cimag(Z_bus[i][j]));
   fprintf(zbusfile,"%lf+%lf*I \t",creal(Z_bus[i][j]),cimag(Z_bus[i][j]));
   fprintf(Zreal,"%lf \t",creal(Z_bus[i][j]));
   fprintf(Zimag,"%lf \t",cimag(Z_bus[i][j]));
        }
    //    printf("\n");
  fprintf(zbusfile,"\n");
  fprintf(Zreal,"\n");
  fprintf(Zimag,"\n");
    }
  //  printf("\n");
    fclose(Zreal);
    fclose(Zimag);
    fclose(zbusfile);

//return Zbus;
}
