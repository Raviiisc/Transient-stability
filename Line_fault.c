//#include <stdio.h>
//#include <stdlib.h>
//#include <complex.h>
//#include <math.h>
//#define PI 3.141593
//
//void Ybus_linefault(double **linedat,double **TFdata,double **Shuntdat,int nlines,int ntf,int nsh,int nbus1,int nbus2,double alpha,double time,double start_time,double clear_time)
//{
// int i,j;
//
//int nrows=nlines+ntf;
//
//double **linetfdata=(double **)calloc(nrows,sizeof(double *));   //dynamically allocating the real part
//
//for(i=0;i<nrows;i++)
//{
//
//    linetfdata[i]=(double *)calloc(nrows,sizeof(double));
//
//}
//
//for(i=0;i<nrows;i++)
//{
//
//    for(j=0;j<6;j++)
//    {
//
//       linetfdata[i][j]=0.00;    // Initialization
//    }
//}
//
//for(i=0;i<nlines;i++)
//{
//
//    for(j=0;j<6;j++)
//    {
//
//       linetfdata[i][j]=linedat[i][j];    // Initialization
//    }
//}
//
//for(i=0;i<ntf;i++)
//{
//
//    for(j=0;j<6;j++)
//    {
//
//       linetfdata[i+nlines][j]=TFdata[i][j];    // Initialization
//    }
//}
//
//
//
//
//
//double **g_real;
//g_real=(double **)calloc(nrows,sizeof(double *));   //dynamically allocating the real part
//
//for(i=0;i<nrows;i++)
//{
//
//    g_real[i]=(double *)calloc(nrows,sizeof(double));
//
//}
//
//for(i=0;i<nrows;i++)
//{
//
//    for(j=0;j<nrows;j++)
//    {
//
//        g_real[i][j]=0.00;    // Initialization
//    }
//}
//
//double **g_imag;
//
//g_imag=(double **)calloc(nrows,sizeof(double *));    // Dynamically allocating imaginary part
//
//for(i=0;i<nrows;i++)
//{
//
//    g_imag[i]=(double *)calloc(nrows,sizeof(double));
//}
//
//for(i=0;i<nrows;i++)
//{
//
//    for(j=0;j<nrows;j++)
//    {
//
//        g_imag[i][j]=0.00;
//    }
//}
//
//
////  FROM BUS
//
//int *fb=(int *)malloc(nrows*sizeof(int));
//
//for(i=0;i<nrows;i++)
//{
//
//    fb[i]=linetfdata[i][0];
//
//}
//
//// TO BUS
//
//int *tb=(int *)malloc(nrows*sizeof(int));
//
//for(i=0;i<nrows;i++)
//{
//
//    tb[i]=(linetfdata[i][1]);
//
//}
//
//// Resistance values;
//
//double *R=(double *)malloc(nrows*sizeof(double));
//
//for(i=0;i<nrows;i++)
//{
//
//    R[i]=linetfdata[i][2];
//}
//
//// Reactance values
//
//double *X=(double *)malloc(nrows*sizeof(double));
//
//for(i=0;i<nrows;i++)
//{
//
//    X[i]=linetfdata[i][3];
//
//}
//
//// b values
//
//double *susceptance=(double *)malloc(nrows*sizeof(double));
//
//for(i=0;i<nrows;i++)
//{
//    if(i>=nlines)
//    {
//
//
//    susceptance[i]=0;
//}
//else{
//    susceptance[i]=linetfdata[i][4];
//}
//
//}
//
//// Type
////
////int *type=(int *)malloc(nrows*sizeof(int));
////
////for(i=0;i<nrows;i++)
////{
////
////    type[i]=linetfdata[i][5];
////}
//
//
////Tap
//double *tap=(double *)malloc(nrows*sizeof(double));
//
//for(i=0;i<nrows;i++)
//{
//    if(i>=nlines)
//    {
//
//    tap[i]=linetfdata[i][4];
//  //  printf("%lf",tap[i]);
//    }
//    else{
//        tap[i]=0;
//    }
//       //printf("%lf \t",tap[i]);
//}
//
////Off diagonal elements
//
//
//for(int k=0;k<nrows;k++)
//{
//    if(tap[k]!=0)
//    {
//    if(fb[k]!=nbus1 || fb[k]!=nbus2 ||tb[k]!=nbus1 || tb[k]!=nbus2)
//    {
//
//
//    g_real[fb[k]-1][tb[k]-1]=g_real[fb[k]-1][tb[k]-1]-R[k]/(tap[k])/(pow(R[k],2)+pow(X[k],2));
//    g_real[tb[k]-1][fb[k]-1]= g_real[fb[k]-1][tb[k]-1];
//    }
//    else if(fb[k]==nbus1 || fb[k]==nbus2 ||tb[k]==nbus1 || tb[k]==nbus2)
//    {
//    g_real[fb[k]-1][tb[k]-1]=0.00;    //g_real[fb[k]-1][tb[k]-1]-R[k]/(tap[k])/(pow(R[k],2)+pow(X[k],2));
//    g_real[tb[k]-1][fb[k]-1]= 0.00;            //g_real[fb[k]-1][tb[k]-1];
//    }
//    }
//    else if(tap[k]==0)
//    {
//        if(fb[k]!=nbus1 || fb[k]!=nbus2 ||tb[k]!=nbus1 || tb[k]!=nbus2)
//        {
//
//
//    g_real[fb[k]-1][tb[k]-1]=g_real[fb[k]-1][tb[k]-1]-R[k]/(pow(R[k],2)+pow(X[k],2));
//    g_real[tb[k]-1][fb[k]-1]= g_real[fb[k]-1][tb[k]-1];
//        }
//        else if(fb[k]==nbus1 || fb[k]==nbus2 ||tb[k]==nbus1 || tb[k]==nbus2)
//        {
//    g_real[fb[k]-1][tb[k]-1]=0.00;  //g_real[fb[k]-1][tb[k]-1]-R[k]/(pow(R[k],2)+pow(X[k],2));
//    g_real[tb[k]-1][fb[k]-1]=0.00;      // g_real[fb[k]-1][tb[k]-1];
//        }
//    }
//}
//
//
//for(int k=0;k<nrows;k++)
//{
//    if(tap[k]!=0)
//    {
//    if(fb[k]!=nbus1 || fb[k]!=nbus2 ||tb[k]!=nbus1 || tb[k]!=nbus2)
//    {
//    g_imag[fb[k]-1][tb[k]-1]=g_imag[fb[k]-1][tb[k]-1]-((-X[k])/(tap[k]))/(pow(R[k],2)+pow(X[k],2));
//    g_imag[tb[k]-1][fb[k]-1]= g_imag[fb[k]-1][tb[k]-1];
//    }
//    else if(fb[k]==nbus1 || fb[k]==nbus2 ||tb[k]==nbus1 || tb[k]==nbus2)
//    {
//    g_imag[fb[k]-1][tb[k]-1]=0.00; //g_imag[fb[k]-1][tb[k]-1]-((-X[k])/(tap[k]))/(pow(R[k],2)+pow(X[k],2));
//    g_imag[tb[k]-1][fb[k]-1]=0.00; // g_imag[fb[k]-1][tb[k]-1];
//    }
//    }
//    else
//    {
//    if(fb[k]!=nbus1 || fb[k]!=nbus2 ||tb[k]!=nbus1 || tb[k]!=nbus2)
//        {
//    g_imag[fb[k]-1][tb[k]-1]=g_imag[fb[k]-1][tb[k]-1]-(-X[k])/(pow(R[k],2)+pow(X[k],2));
//    g_imag[tb[k]-1][fb[k]-1]= g_imag[fb[k]-1][tb[k]-1];
//    }
//    else if(fb[k]==nbus1 || fb[k]==nbus2 ||tb[k]==nbus1 || tb[k]==nbus2)
//    {
//    g_imag[fb[k]-1][tb[k]-1]=0.00;  //g_imag[fb[k]-1][tb[k]-1]-(-X[k])/(pow(R[k],2)+pow(X[k],2));
//    g_imag[tb[k]-1][fb[k]-1]=0.00; //g_imag[fb[k]-1][tb[k]-1];
//    }
//}
//
//
//int m=max(tb,nrows);
//int n=max(fb,nrows);
//int nbus=maximum(m,n);
//int nbranch=nrows;
////printf("%d \t",nbus);
//
////Diagonal elements
//
//
//for(i=0;i<nbus;i++)
//{
//    for(j=0;j<nbranch;j++)
//    {
//   if(tap[j]!=0)
//   {
//     if(fb[j]==i+1)
//     {
//         if(fb[j]!=nbus1||fb[j]!=nbus2)
//         {
//         g_real[i][i]=g_real[i][i]+(R[j]/(pow(R[j],2)+pow(X[j],2)))/(tap[j]*tap[j]);
//         }
//         else if(fb[j]==nbus1 || fb[j]==nbus2)
//         {
//            g_real[i][i]=g_real[i][i]+(R[j]/(alpha*(pow(R[j],2)+pow(X[j],2))))/(tap[j]*tap[j]);
//         }
//     }
//     else if(tb[j]==i+1)
//     {
//         if(tb[j]!=nbus1||tb[j]!=nbus2)
//         {
//         g_real[i][i]=g_real[i][i]+R[j]/(pow(R[j],2)+pow(X[j],2));
//         }
//         else if(tb[j]==nbus1||tb[j]==nbus2)
//         {
//             g_real[i][i]=g_real[i][i]+R[j]/((1-alpha)*(pow(R[j],2)+pow(X[j],2)));
//         }
//     }
//
//    }
//
//    else
//    {
//         if(fb[j]==i+1)
//     {
//         if(fb[j]!=nbus1||fb[j]!=nbus2)
//         {
//         g_real[i][i]=g_real[i][i]+R[j]/(pow(R[j],2)+pow(X[j],2));
//         }
//         else if(fb[j]==nbus1||fb[j]==nbus2)
//         {
//         g_real[i][i]=g_real[i][i]+R[j]/(alpha*(pow(R[j],2)+pow(X[j],2)));
//         }
//     }
//     else if(tb[j]==i+1)
//     {
//         if(tb[j]!=nbus1||tb[j]!=nbus2)
//         {
//         g_real[i][i]=g_real[i][i]+R[j]/(pow(R[j],2)+pow(X[j],2));
//         }
//         else if(tb[j]==nbus1||tb[j]==nbus2)
//         {
//         g_real[i][i]=g_real[i][i]+R[j]/((1-alpha)*(pow(R[j],2)+pow(X[j],2)));
//         }
//     }
//
//
//
//    }
//
//    }
//
//}
//
//
//for(i=0;i<nbus;i++)
//{
//    for(j=0;j<nbranch;j++)
//    {
//        if(tap[j]!=0)
//        {
//
//     if(fb[j]==i+1)
//     {
//         if(fb[j]!=nbus1||fb[j]!=nbus2)
//         {
//         g_imag[i][i]=g_imag[i][i]+(-X[j]/(pow(R[j],2)+pow(X[j],2)))/(tap[j]*tap[j])+susceptance[j];
//         }
//         else if(fb[j]==nbus1||fb[j]==nbus2)
//         {
//        g_imag[i][i]=g_imag[i][i]+(-X[j]/(alpha*(pow(R[j],2)+pow(X[j],2))))/(tap[j]*tap[j])+alpha*susceptance[j];
//         }
//     }
//     else if(tb[j]==i+1)
//     {
//         if(tb[j]!=nbus1||tb[j]!=nbus2)
//         {
//         g_imag[i][i]=g_imag[i][i]+(-X[j])/(pow(R[j],2)+pow(X[j],2))+susceptance[j];
//         }
//         else if(tb[j]==nbus1||tb[j]==nbus2)
//         {
//         g_imag[i][i]=g_imag[i][i]+(-X[j])/((1-alpha)*(pow(R[j],2)+pow(X[j],2)))+(1-alpha)*susceptance[j];
//         }
//     }
//
//    }
//
//    else
//    {
//         if(fb[j]==i+1)
//     {
//         if(fb[j]!=nbus1||fb[j]!=nbus2)
//         {
//         g_imag[i][i]=g_imag[i][i]+(-X[j])/(pow(R[j],2)+pow(X[j],2))+susceptance[j];
//         }
//         else if(fb[j]==nbus1||fb[j]==nbus2)
//         {
//         g_imag[i][i]=g_imag[i][i]+(-X[j])/(alpha*(pow(R[j],2)+pow(X[j],2)))+alpha*susceptance[j];
//         }
//     }
//     else if(tb[j]==i+1)
//     {
//         if(tb[j]!=nbus1||tb[j]!=nbus2)
//         {
//         g_imag[i][i]=g_imag[i][i]+(-X[j]/(pow(R[j],2)+pow(X[j],2)))+susceptance[j];
//         }
//         else if(tb[j]==nbus1||tb[j]==nbus2)
//         {
//         g_imag[i][i]=g_imag[i][i]+(-X[j]/((1-alpha)*(pow(R[j],2)+pow(X[j],2))))+(1-alpha)*susceptance[j];
//         }
//     }
//
//
//    }
//
//    }
//
//}
//
//
//
//
//complex double **Y_bus;
//
//
//Y_bus=(complex double **)calloc(nrows,sizeof(complex double *));
//
//for(i=0;i<nrows;i++)
//{
//
//    Y_bus[i]=(complex double *)calloc(nrows,sizeof(complex double));
//}
//for(i=0;i<nrows;i++)
//{
//
//    for(j=0;j<nrows;j++)
//    {
//
//        Y_bus[i][j]=g_real[i][j]+I*(g_imag[i][j]);
//    }
//}
//FILE *filewrite,*Yreal,*Yimag;
//filewrite=fopen("ybus.txt","w"); // Write to the file
//Yreal=fopen("yreal.txt","w"); // Write to the file
//Yimag=fopen("Yimag.txt","w"); // Write to the file
//
//
//for(i=0;i<nrows;i++)
//{
//
//    for(j=0;j<nrows;j++)
//    {
// fprintf(Yreal,"%lf \t",creal(Y_bus[i][j]));
//
// fprintf(Yimag,"%1f \t",cimag(Y_bus[i][j]));
//
// fprintf(filewrite,"%lf+I*%lf",creal(Y_bus[i][j]),cimag(Y_bus[i][j]));
//       // printf("%lf+I*%lf \t",creal(Y_bus[i][j]),cimag(Y_bus[i][j]));
//       // printf("%lf",g_imag[i][j]);
//    }
//   // printf("\n");
//     fprintf(filewrite,"\n");
//     fprintf(Yreal,"\n");
//     fprintf(Yimag,"\n");
//}
//
//fclose(Yreal);
//fclose(Yimag);
//
//
//
//}
