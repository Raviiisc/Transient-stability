#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<complex.h>
#define PI 3.141593
void diff_eq(int ngen,double complex *V_gen,double *V_t,double **gendat,double time,double start_time,double clear_time)//double *Efd,double *ka,double *ta)
{

 FILE *machine_initials;
// if(time>start_time && time<clear_time)
// {

machine_initials=fopen("init_machine.txt","r");
// }
// else
// {
//     machine_initials=fopen("original_init.txt","r");
// }

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
double *Efd_init=(double *)malloc(ngen*sizeof(double));

    for (int i=0;i<ngen;i++)
    {
        Efd_init[i] =machine_initialdat[i][0];

    }
double *V_ref=(double *)malloc(ngen*sizeof(double));
for(i=0;i<ngen;i++)
{

    V_ref[i]=machine_initialdat[i][1];
}
double *Voltage_mag=(double *)malloc(ngen*sizeof(double));
for(i=0;i<ngen;i++)
{

    Voltage_mag[i]=machine_initialdat[i][2];
}
double *Edc_init=(double *)malloc(ngen*sizeof(double));
for(i=0;i<ngen;i++)
{

    Edc_init[i]=machine_initialdat[i][3];
}
double *Ed_init=(double *)malloc(ngen*sizeof(double));
for(i=0;i<ngen;i++)
{

    Ed_init[i]=machine_initialdat[i][4];
}
double *Eq_init=(double *)malloc(ngen*sizeof(double));
for(i=0;i<ngen;i++)
{

    Eq_init[i]=machine_initialdat[i][5];
}
double *Ed__init=(double *)malloc(ngen*sizeof(double));
for(i=0;i<ngen;i++)
{

    Ed__init[i]=machine_initialdat[i][6];
}
double *Eq__init=(double *)malloc(ngen*sizeof(double));
for(i=0;i<ngen;i++)
{

    Eq__init[i]=machine_initialdat[i][7];
}
double *Vd=(double *)malloc(ngen*sizeof(double));
for(i=0;i<ngen;i++)
{

    Vd[i]=machine_initialdat[i][8];

}
double *Vq=(double *)malloc(ngen*sizeof(double));
for(i=0;i<ngen;i++)
{

    Vq[i]=machine_initialdat[i][9];
}

double *id=(double *)malloc(ngen*sizeof(double));
for(i=0;i<ngen;i++)
{

    id[i]=machine_initialdat[i][10];
}

 double *iq=(double *)malloc(ngen*sizeof(double));
for(i=0;i<ngen;i++)
{

    iq[i]=machine_initialdat[i][11];
}

  double *Torque_ele_init=(double *)malloc(ngen*sizeof(double));
for(i=0;i<ngen;i++)
{

    Torque_ele_init[i]=machine_initialdat[i][12];
}
  double *Torque_mech_init=(double *)malloc(ngen*sizeof(double));
for(i=0;i<ngen;i++)
{

    Torque_mech_init[i]=machine_initialdat[i][13];
}

  double *delta_init=(double *)malloc(ngen*sizeof(double));
for(i=0;i<ngen;i++)
{

    delta_init[i]=machine_initialdat[i][14];
}

  double *Slip_init=(double *)malloc(ngen*sizeof(double));
for(i=0;i<ngen;i++)
{

    Slip_init[i]=machine_initialdat[i][15];
}
fclose(machine_initials);

/////////
//Generator data
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
      //  printf("%f \n",Xq[i]);
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
     double *tc=(double *)malloc(ngen*sizeof(double));
    for (int i=0;i<ngen;i++)
    {
        tc[i] = gendat[i][14];
    }
     double *Ka=(double *)malloc(ngen*sizeof(double));
    for (int i=0;i<ngen;i++)
    {
        Ka[i] = gendat[i][15];
    }
     double *ta=(double *)malloc(ngen*sizeof(double));
    for (int i=0;i<ngen;i++)
    {
        ta[i] = gendat[i][16];
       // printf("%lf \t",ta[i]);
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


/////////////////

double h=0.001;
double *k_1=(double *)malloc(ngen*sizeof(double));
double *k_2=(double *)malloc(ngen* sizeof(double));
double *Efd =(double *)malloc(ngen*sizeof(double));

int t=ngen;
for (int i=0;i<t;i++)
    {
        k_1[i] = (-Efd_init[i] + Ka[i]*(V_ref[i]-V_t[i]))/ta[i];
        k_2[i] = (-(Efd_init[i] + h*k_1[i]) + Ka[i]*(V_ref[i]-V_t[i]))/ta[i];

        Efd[i] = Efd_init[i] + h*(k_1[i] + k_2[i])/2;
//printf("%lf \t",Efd[i]);
    }
   //printf("\n");
//////////////////////////////////



//////////Main code



   // double h=0.001;
    double *Eq_ = (double *)malloc(ngen*sizeof(double));
    double *Ed_ = (double *)malloc(ngen*sizeof(double));
    double *Eq__ = (double *)malloc(ngen*sizeof(double));
    double *Ed__ = (double *)malloc(ngen*sizeof(double));
    double *Edc = (double *)malloc(ngen*sizeof(double));
    double *Sm = (double *)malloc(ngen*sizeof(double));
    double *delta = (double *)malloc(ngen*sizeof(double));
     double *Slip = (double *)malloc(ngen*sizeof(double));



    for (int i=0;i<t;i++)
    {
        k_1[i] = (-Edc_init[i] - iq[i]*(Xq__[i]-Xd__[i]))/tc[i];
        k_2[i] = (-(Edc_init[i] + h*k_1[i]) - iq[i]*(Xq__[i]-Xd__[i]))/tc[i];
        Edc[i] = Edc_init[i] + h*(k_1[i] + k_2[i])/2;
 //       printf("%lf \t",Edc[i]);
    }
  //  printf("\n");

      for (int i=0;i<t;i++)
    {
       k_1[i] = (-Eq_init[i] + id[i]*(Xd[i]-Xd_[i]) + Efd_init[i])/Tdo_[i];
       k_2[i] = (-(Eq_init[i]+h*k_1[i]) + id[i]*(Xd[i]-Xd_[i]) + Efd_init[i])/Tdo_[i];;

        Eq_[i] = Eq_init[i] + h*(k_1[i] + k_2[i])/2;
 // printf("%lf \t",Eq_[i]);
    }
//printf("\n");
       for (int i=0;i<t;i++)
    {
       k_1[i] = (-Ed_init[i] - iq[i]*(Xq[i]-Xq_[i]))/Tqo_[i];
       k_2[i] = (-(Ed_init[i]+h*k_1[i]) - iq[i]*(Xq[i]-Xq_[i]))/Tqo_[i];

        Ed_[i] = Ed_init[i] + h*(k_1[i] + k_2[i])/2;

     //    printf("%lf \t",Ed_[i]);
    }
//printf("\n");
        for (int i=0;i<t;i++)
    {
       k_1[i] = (-Eq__init[i] +Eq_init[i]+ id[i]*(Xd_[i]-Xd__[i]))/Tdo__[i];
       k_2[i] = (-(Eq__init[i]+h*k_1[i]) +Eq_init[i]+ id[i]*(Xd_[i]-Xd__[i]))/Tdo__[i];
        Eq__[i] = Eq__init[i] + h*(k_1[i] + k_2[i])/2;
    }

     for (int i=0;i<t;i++)
    {
       k_1[i] = (-Ed__init[i] +Ed_init[i]- iq[i]*(Xq_[i]-Xq__[i]))/Tqo__[i];
       k_2[i] = (-(Ed__init[i]+h*k_1[i]) +Ed_init[i]- iq[i]*(Xq_[i]-Xq__[i]))/Tqo__[i];
        Ed__[i] = Ed__init[i] + h*(k_1[i] + k_2[i])/2;
    }

   for (int i=0;i<t;i++)
    {
       k_1[i] = (-D[i]*(Slip_init[i]) -Torque_ele_init[i]+Torque_mech_init[i])/(2*H[i]);
        k_2[i] = (-D[i]*(Slip_init[i]+h*k_1[i]) -Torque_ele_init[i]+Torque_mech_init[i])/(2*H[i]);
        Slip[i] = Slip_init[i] + h*(k_1[i] + k_2[i])/2;


    //    Slip[i] = (Slip_init[i]) * (1 - ((D[i]*step_size)/(2*H[i])) + ((D[i]*D[i]*step_size*step_size)/(8*H[i]*H[i]))) + (Tm_initial[i] - Te_initial[i]) * ((step_size/(2*H[i])) - ((D[i]*step_size*step_size)/(8*H[i]*H[i])));
       // printf("%lf \t",Slip[i]);
    }


       for (int i=0;i<t;i++)
    {
       k_1[i]= 2*PI*60*Slip_init[i];
       k_2[i]=2*PI*60*Slip_init[i];
       delta[i]=delta_init[i]+h*(k_1[i]+k_2[i])/2;
//printf("%lf \t",delta[i]);
    }

    // double *Vq = (double *)malloc(ngen*sizeof(double));
    for (int i=0;i<ngen;i++)
    {
        Vq[i] = creal(V_gen[i]/cexp(I*delta[i]));
    }

  //  double *Vd = (double *)malloc(ngen*sizeof(double));
    for (int i=0;i<ngen;i++)
    {
        Vd[i] = cimag(V_gen[i]/cexp(I*delta[i]));

    }

    for (int i=0;i<ngen;i++)
    {
        iq[i] = (Ed__[i] + Edc[i] -Vd[i])/Xd__[i];
//printf("%lf \t",iq[i]);
    }

    for (int i=0;i<ngen;i++)
    {
        id[i] = (Vq[i]-Eq__[i])/Xd__[i];
    }

    double *Torq_ele = (double *)malloc(ngen*sizeof(double));
    for (int i=0;i<ngen;i++)
    {
        Torq_ele[i] = Eq__[i]*iq[i] + Ed__[i]*id[i] + (Xd__[i]-Xq__[i])*id[i]*iq[i];
//    printf("%lf \t",Edc[i]);
    }
  //  printf("\n");
    FILE *mach_init;
    FILE *dup_init;
    mach_init=fopen("init_machine.txt","w");
    dup_init=fopen("duplicate.txt","w");

for(i=0;i<ngen;i++)
{

fprintf(mach_init,"\n");
fprintf(dup_init,"\n");
//printf("%lf    %lf     %f    %lf    %lf    %lf   %lf    %lf    %llf    %lf    %lf     %lf    %lf    %lf    %lf    %lf \n",Efd[i],V_ref[i],V_t[i],Edc[i],Ed_[i],Eq_[i],Ed__[i],Eq__[i],creal(Vd[i]),creal(Vq[i]),creal(id[i]),creal(iq[i]),Torq_ele[i],Torque_mech_init[i],delta[i],Slip[i]);
//printf("%lf",Slip[i]);
fprintf(mach_init,"%lf    %lf     %lf      %lf    %lf    %lf    %lf     %lf     %lf     %lf     %lf     %lf     %lf    %lf     %lf   %f",Efd[i],V_ref[i],V_t[i],Edc[i],Ed_[i],Eq_[i],Ed__[i],Eq__[i],creal(Vd[i]),creal(Vq[i]),creal(id[i]),creal(iq[i]),Torq_ele[i],Torque_mech_init[i],delta[i],Slip[i]);
fprintf(dup_init,"%lf    %lf     %lf      %lf    %lf    %lf    %lf     %lf     %lf     %lf     %lf     %lf     %lf    %lf     %lf   %f",Efd[i],V_ref[i],V_t[i],Edc[i],Ed_[i],Eq_[i],Ed__[i],Eq__[i],creal(Vd[i]),creal(Vq[i]),creal(id[i]),creal(iq[i]),Torq_ele[i],Torque_mech_init[i],delta[i],Slip[i]);

}

//for(i=0;i<ngen;i++)
//{
//    FILE *excel_data;
//excel_data=fopen("exceldat.txt","w");
//fprintf(excel_data,"%lf    %lf     %f    %f    %f    %f   %f    %f    %f    %f    %f    %f   %f  %f  %f   %f",Efd[i],V_ref[i],Voltage_mag[i],Edc[i],Ed_[i],Eq_[i],Ed__[i],Eq__[i],creal(Vd[i]),creal(Vq[i]),creal(id[i]),creal(iq[i]),Torq_ele[i],Torque_mech_init[i],delta[i],Slip[i]);
//
//}

//printf("\n");
fclose(mach_init);
fclose(dup_init);
}
