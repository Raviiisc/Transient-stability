#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <math.h>
#define PI 3.141593

void change_genpower(int ngen,int gen_no,double new_val,double time,double start_time,double clear_time)
{
    FILE *machine_initials;
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
double *Efd=(double *)malloc(ngen*sizeof(double));

    for (int i=0;i<ngen;i++)
    {
        Efd[i] =machine_initialdat[i][0];

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
double *Edc=(double *)malloc(ngen*sizeof(double));
for(i=0;i<ngen;i++)
{

    Edc[i]=machine_initialdat[i][3];
}
double *Ed_=(double *)malloc(ngen*sizeof(double));
for(i=0;i<ngen;i++)
{

    Ed_[i]=machine_initialdat[i][4];
}
double *Eq_=(double *)malloc(ngen*sizeof(double));
for(i=0;i<ngen;i++)
{

    Eq_[i]=machine_initialdat[i][5];
}
double *Ed__=(double *)malloc(ngen*sizeof(double));
for(i=0;i<ngen;i++)
{

    Ed__[i]=machine_initialdat[i][6];
}
double *Eq__=(double *)malloc(ngen*sizeof(double));
for(i=0;i<ngen;i++)
{

    Eq__[i]=machine_initialdat[i][7];
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

  double *Torq_ele=(double *)malloc(ngen*sizeof(double));
for(i=0;i<ngen;i++)
{

    Torq_ele[i]=machine_initialdat[i][12];
}
  double *Torque_mech=(double *)malloc(ngen*sizeof(double));
for(i=0;i<ngen;i++)
{

    Torque_mech[i]=machine_initialdat[i][13];
 //   printf("%lf",Torque_mech[i]);
}

  double *delta=(double *)malloc(ngen*sizeof(double));
for(i=0;i<ngen;i++)
{

    delta[i]=machine_initialdat[i][14];
}

  double *Slip=(double *)malloc(ngen*sizeof(double));
for(i=0;i<ngen;i++)
{

    Slip[i]=machine_initialdat[i][15];
}


fclose(machine_initials);
FILE *mach_init;

    mach_init=fopen("init_machine.txt","w");
for(i=0;i<ngen;i++)
{
if(i==gen_no-1)
{
    if(time-start_time<=0.001&&time-start_time>=0)
    {


    Torque_mech[i]=(machine_initialdat[i][13])*new_val;
}
//else if(time-clear_time<=0.001&&time-clear_time>=0)
//{
//
////printf("Hello");
//     Torque_mech[i]=machine_initialdat[i][13]/new_val;
//}
}
}
for(i=0;i<ngen;i++)
{

fprintf(mach_init,"\n");
fprintf(mach_init,"%lf    %lf     %lf      %lf    %lf    %lf    %lf     %lf     %lf     %lf     %lf     %lf     %lf    %lf     %lf   %f",Efd[i],V_ref[i],Voltage_mag[i],Edc[i],Ed_[i],Eq_[i],Ed__[i],Eq__[i],creal(Vd[i]),creal(Vq[i]),creal(id[i]),creal(iq[i]),Torq_ele[i],Torque_mech[i],delta[i],Slip[i]);
}
fclose(mach_init);
}
