#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <math.h>
#define PI 3.141593
//
void init_machine(double **busdat,double **gendat,int nbus,int ngen)
{
//    printf("%d",ngen);
//
//    for(int i=0;i<nbus;i++)
//    {
//
//        for(int j=0;j<8;j++)
//        {
//
//          printf("%f \t",busdat[i][j]);
//        }
//        printf("\n");
//    }
//
// for(int i=0;i<ngen;i++)
//    {
//
//        for(int j=0;j<19;j++)
//        {
//
//          printf("%f \t",gendat[i][j]);
//        }
//        printf("\n");
//    }

   int *bustype = (int *)malloc(nbus*sizeof(int));
    for (int i=0;i<nbus;i++)
    {
        bustype[i] = busdat[i][0];
    }
     double *voltage_rated=(double *)malloc(nbus*sizeof(double));
    for (int i=0;i<nbus;i++)
    {
        voltage_rated[i] = busdat[i][1];
    }
    double *voltage_mag=(double *)malloc(nbus*sizeof(double));
    for (int i=0;i<nbus;i++)
    {
        voltage_mag[i] = busdat[i][2];
    }
     double *voltage_ang=(double *)malloc(nbus*sizeof(double));
    for (int i=0;i<nbus;i++)
    {
        voltage_ang[i] = busdat[i][3];
    }
     double *Pg=(double *)malloc(nbus*sizeof(double));
    for (int i=0;i<nbus;i++)
    {
        Pg[i] = busdat[i][4];
    }

      double *Qg=(double *)malloc(nbus*sizeof(double));
    for (int i=0;i<nbus;i++)
    {
        Qg[i] = busdat[i][5];
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

      double *Pt=(double *)malloc(nbus*sizeof(double));
    for (int i=0;i<nbus;i++)
    {
        Pt[i] = Pg[i]-Pl[i];
    }
         double *Qt=(double *)malloc(nbus*sizeof(double));
    for (int i=0;i<nbus;i++)
    {
        Qt[i] = Qg[i]-Ql[i];
    }

     double complex *Voltage_init=(double complex *)malloc(nbus*sizeof(double complex));
    for (int i=0;i<nbus;i++)
    {
        Voltage_init[i] = voltage_mag[i]*cos(voltage_ang[i]*PI/180)+(voltage_mag[i]*sin(voltage_ang[i]*PI/180))*I;
    }


   double complex *Current_init=(double complex *)malloc(nbus*sizeof(double complex));
    for (int i=0;i<nbus;i++)
    {
        Current_init[i] = (Pt[i]-I*Qt[i])/(conj(Voltage_init[i]));
       // printf("%f  %f  %f  %f \n",creal(Current_init[i]),cimag(Current_init[i]),creal(Voltage_init[i]),cimag(Voltage_init[i]));
    }

//     Machine data

      double *H=(double *)malloc(ngen*sizeof(double));
    for (int i=0;i<ngen;i++)
    {
        H[i] = gendat[i][1];
    }

     double *D=(double *)malloc(ngen*sizeof(double));
    for (int i=0;i<ngen;i++)
    {
        D[i] = gendat[i][2];
    }
     double *Ra=(double *)malloc(ngen*sizeof(double));
    for (int i=0;i<ngen;i++)
    {
        Ra[i] = gendat[i][3];
    }
     double *Xd=(double *)malloc(ngen*sizeof(double));
    for (int i=0;i<ngen;i++)
    {
        Xd[i] = gendat[i][4];
    }
     double *Xd_=(double *)malloc(ngen*sizeof(double));
    for (int i=0;i<ngen;i++)
    {
        Xd_[i] = gendat[i][5];
    }
     double *Xd__=(double *)malloc(ngen*sizeof(double));
    for (int i=0;i<ngen;i++)
    {
        Xd__[i] = gendat[i][6];
       //printf("%f \n",Xd__[i]);
    }
     double *Xq=(double *)malloc(ngen*sizeof(double));
    for (int i=0;i<ngen;i++)
    {
        Xq[i] = gendat[i][7];
       // printf("%f \n",Xq[i]);
    }
     double *Xq_=(double *)malloc(ngen*sizeof(double));
    for (int i=0;i<ngen;i++)
    {
        Xq_[i] = gendat[i][8];
    }

     double *Xq__=(double *)malloc(ngen*sizeof(double));
    for (int i=0;i<ngen;i++)
    {
        Xq__[i] = gendat[i][9];
    }

     double *Tdo_=(double *)malloc(ngen*sizeof(double));
    for (int i=0;i<ngen;i++)
    {
        Tdo_[i] = gendat[i][10];
    }
     double *Tqo_=(double *)malloc(ngen*sizeof(double));
    for (int i=0;i<ngen;i++)
    {
        Tqo_[i] = gendat[i][11];
    }
     double *Tdo__=(double *)malloc(ngen*sizeof(double));
    for (int i=0;i<ngen;i++)
    {
        Tdo__[i] = gendat[i][12];
    }
     double *Tqo__=(double *)malloc(ngen*sizeof(double));
    for (int i=0;i<ngen;i++)
    {
        Tqo__[i] = gendat[i][13];
    }
     double *Tc=(double *)malloc(ngen*sizeof(double));
    for (int i=0;i<ngen;i++)
    {
        Tc[i] = gendat[i][14];
    }
     double *Ka=(double *)malloc(ngen*sizeof(double));
    for (int i=0;i<ngen;i++)
    {
        Ka[i] = gendat[i][15];
    }
     double *Ta=(double *)malloc(ngen*sizeof(double));
    for (int i=0;i<ngen;i++)
    {
        Ta[i] = gendat[i][16];
    }
     double *Efd_max=(double *)malloc(ngen*sizeof(double));
    for (int i=0;i<ngen;i++)
    {
        Efd_max[i] = gendat[i][17];
    }
     double *Efd_min=(double *)malloc(ngen*sizeof(double));
    for (int i=0;i<ngen;i++)
    {
        Efd_min[i] = gendat[i][18];
    }

     double complex *Eq_init=(double complex *)malloc(ngen*sizeof(double complex));
     double *Eq_init_mag=(double *)malloc(ngen*sizeof(double));
     double *delta_init=(double *)malloc(ngen*sizeof(double));

    for (int i=0;i<ngen;i++)
    {
        Eq_init[i] = Voltage_init[i]+(Current_init[i]*Xq[i])*I;
        delta_init[i]=carg(Eq_init[i]);
        Eq_init_mag[i]=cabs(Eq_init[i]);
    }


    //    id and iq shifted to synchronously rotating frame
       double complex *id_init=(double complex *)malloc(ngen*sizeof(double complex));
    for (int i=0;i<ngen;i++)
    {
        id_init[i] = cimag(Current_init[i]/(cexp(I*delta_init[i])));
    }

       double complex *iq_init=(double complex *)malloc(ngen*sizeof(double complex));
    for (int i=0;i<ngen;i++)
    {
        iq_init[i] = creal(Current_init[i]/(cexp(I*delta_init[i])));
    }

   //vd and vq shifted to synchronously rotating frame
       double complex *vd_init=(double complex *)malloc(ngen*sizeof(double complex));
    for (int i=0;i<ngen;i++)
    {
        vd_init[i] = cimag(Voltage_init[i]/(cexp(I*delta_init[i])));
        //printf("%f \n",vd_init[i]);
    }

       double complex *vq_init=(double complex *)malloc(ngen*sizeof(double complex));
    for (int i=0;i<ngen;i++)
    {
        vq_init[i] = creal(Voltage_init[i]/(cexp(I*delta_init[i])));
    }

double *Efdo_init=(double *)malloc(ngen*sizeof(double));
    for (int i=0;i<ngen;i++)
    {
        Efdo_init[i] = Eq_init_mag[i]-(Xd[i]-Xq[i])*id_init[i];
    }

double *Eqo_init=(double *)malloc(ngen*sizeof(double));
    for (int i=0;i<ngen;i++)
    {
        Eqo_init[i] = Efdo_init[i]+(Xd[i]-Xd_[i])*id_init[i];
    }
 double *Edo_init=(double *)malloc(ngen*sizeof(double));
    for (int i=0;i<ngen;i++)
    {
        Edo_init[i] = -(Xq[i]-Xq_[i])*iq_init[i];
    }
    double *Eqo__init=(double *)malloc(ngen*sizeof(double));
    for (int i=0;i<ngen;i++)
    {
        Eqo__init[i] = Eqo_init[i]+(Xd_[i]-Xd__[i])*id_init[i];
    }
 double *Edo__init=(double *)malloc(ngen*sizeof(double));
    for (int i=0;i<ngen;i++)
    {
        Edo__init[i] =Edo_init[i]-(Xq_[i]-Xq__[i])*iq_init[i];
    }

   double *Vref_init=(double *)malloc(ngen*sizeof(double));
    for (int i=0;i<ngen;i++)
    {
        Vref_init[i] = Efdo_init[i]/Ka[i]+cabs(Voltage_init[i]);
    }

double *Torq_ele_init=(double *)malloc(ngen*sizeof(double));
    for (int i=0;i<ngen;i++)
    {
        Torq_ele_init[i] = (Eqo__init[i])*iq_init[i]+(Edo__init[i])*id_init[i]+(Xd__[i]-Xq__[i])*iq_init[i]*id_init[i];
    }


    double *Torq_mech_init=(double *)malloc(ngen*sizeof(double));
    for (int i=0;i<ngen;i++)
    {
        Torq_mech_init[i] = Torq_ele_init[i];

    }

    double *Edc_init=(double *)malloc(ngen*sizeof(double));  //dummy coil
    for (int i=0;i<ngen;i++)
    {
        Edc_init[i] = -(Xq__[i]-Xd__[i])*iq_init[i];
     //  printf("%f %f\n",Torq_ele_init[i],Torq_mech_init[i]);
    }

    //Slip
    double *Slip_init=(double *)malloc(ngen*sizeof(double));  //dummy coil
    for (int i=0;i<ngen;i++)
    {
        Slip_init[i] = 0.00;
    }


   //printf("Eq   delta  id   iq   vd    vq   Vref_init  Efdo_init   Edo_init  Eqo_init  Edo__init  Eqo__init   Torque_ele_init  Edc_init  Slip_init  \n");
 FILE *mach_init;
mach_init=fopen("init_machine.txt","w");

 //fprintf(mach_init,"Efdo_init  Vref_init  Voltage_init   Edc_init  Edo_init   Eqo_init Ed_init  vd_init  vq_init  id_init  iq_init  Torq_ele_init  Torq_mech_init  delta_init  Slip_init");
int  ncol=0;
//  fprintf(mach_init,"%f   %c",0,0);

   for(int i=0;i<ngen;i++)
  {
fprintf(mach_init,"\n");
    //printf("%f \t",cabs(Edc_init[i]));



   fprintf(mach_init,"%f    %f     %f    %f    %f    %f   %f    %f    %f    %f    %f    %f   %f  %f  %f   %f",Efdo_init[i],Vref_init[i],cabs(Voltage_init[i]),Edc_init[i],Edo_init[i],Eqo_init[i],Edo__init[i],Eqo__init[i],creal(vd_init[i]),creal(vq_init[i]),creal(id_init[i]),creal(iq_init[i]),Torq_ele_init[i],Torq_mech_init[i],delta_init[i],Slip_init[i]);

  //         cabs(Eq_init[i]), delta_init[i],creal(id_init[i]),creal(iq_init[i]),creal(vd_init[i]),creal(vq_init[i]),Efdo_init[i],Edo_init[i],Eqo_init[i],Edo__init[i],Eqo__init[i],Vref_init[i],Torq_ele_init[i],Edc_init[i],Slip_init[i]);


  }
  fclose(mach_init);


//exciter_diff(Vref_init,Voltage_init,Efdo_init,Ka,Ta);
    }
