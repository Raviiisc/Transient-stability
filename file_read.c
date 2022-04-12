#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<complex.h>


void fileread()
{

FILE *file;

file=fopen("3g9b.txt","r");

int nbus,nlines,ntf,nsh,nload,ngen,basedetails;
int rowcol[6];

for(int i=0;i<6;i++)
{
fscanf(file,"%d",&rowcol[i]); // storing the 1st row
}
nbus=rowcol[0];
nlines=rowcol[1];
ntf=rowcol[2];
nsh=rowcol[3];
nload=rowcol[4];
ngen=rowcol[5];
//printf("%d %d",rowcol[0],ngen);
int i,j;

double *busdat[nbus];
double *linedat[nlines];
double *TFdata[ntf];
double *shuntdat[nsh];
double *loaddat[nload];
double *genedat[ngen];
double *baseval[1];
//
for(i=0;i<nbus;i++)
{

    busdat[i]=(double*)malloc(8*sizeof(double));

}
for(i=0;i<nlines;i++)
{

    linedat[i]=(double*)malloc(5*sizeof(double));

}

for(i=0;i<ntf;i++)
{

    TFdata[i]=(double*)malloc(6*sizeof(double));

}

for(i=0;i<nsh;i++)
{

    shuntdat[i]=(double*)malloc(3*sizeof(double));

}

for(i=0;i<nload;i++)
{

    loaddat[i]=(double*)malloc(7*sizeof(double));

}

for(i=0;i<ngen;i++)
{

    genedat[i]=(double*)malloc(19*sizeof(double));

}

for(i=0;i<1;i++)
{

    baseval[i]=(double*)malloc(4*sizeof(double));

}
//
//
//
for(i=0;i<nbus;i++)
{

    for(j=0;j<8;j++)
    {

       fscanf(file,"%lf",&busdat[i][j]);

    }
}
for(i=0;i<nlines;i++)
{

    for(j=0;j<5;j++)
    {

       fscanf(file,"%lf",&linedat[i][j]);

    }
}

for(i=0;i<ntf;i++)
{

    for(j=0;j<6;j++)
    {

       fscanf(file,"%lf",&TFdata[i][j]);

    }
}

for(i=0;i<nload;i++)
{

    for(j=0;j<7;j++)
    {

       fscanf(file,"%lf",&loaddat[i][j]);

    }
}

for(i=0;i<ngen;i++)
{

    for(j=0;j<19;j++)
    {

       fscanf(file,"%lf",&genedat[i][j]);

    }
}
int type;
printf("ENTER THE TYPE OF FAULT\n");
printf("TYPE0: NO FAULT:TYPE1: Change in generator input, TYPE2:Change in gen Vref, TYPE3: BUS FAULT, TYPE4: LINE FAULT \n");

scanf("%d",&type);


if(type==0)
{

  int busno;
printf("CASE0: NO FAULT \n");

double start_time=2.000;
double clear_time=2.050;
   FILE *excel_data1,*excel_data2,*excel_data3;
excel_data1=fopen("exceldat.txt","w");
excel_data2=fopen("exceldat2.txt","w");
excel_data3=fopen("exceldat3.txt","w");

//busdat(mat,nbus);
Ybus(linedat,TFdata,shuntdat,nlines,ntf,nsh,nbus);

Ybus_aug(nbus,nload,ngen,loaddat,genedat,busdat);



init_machine(busdat,genedat,nbus,ngen);


for(double time=0;time<0.004 ;time=time+0.001)
{


newtwork_eq(genedat,ngen,time,start_time,clear_time);


FILE *machine_initials;
machine_initials=fopen("duplicate.txt","r");

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


   for(i=0;i<1;i++)
{
    fprintf(excel_data1,"\n");
fprintf(excel_data1,"%lf   %lf    %lf     %f    %f    %f    %f   %f    %f    %f    %f    %f    %f   %f  %f  %f   %f",time,Efd[i],V_ref[i],Voltage_mag[i],Edc[i],Ed_[i],Eq_[i],Ed__[i],Eq__[i],creal(Vd[i]),creal(Vq[i]),creal(id[i]),creal(iq[i]),Torq_ele[i],Torque_mech[i],delta[i],Slip[i]);

}
 for(i=1;i<2;i++)
{
    fprintf(excel_data2,"\n");
fprintf(excel_data2,"%lf   %lf    %lf     %f    %f    %f    %f   %f    %f    %f    %f    %f    %f   %f  %f  %f   %f",time,Efd[i],V_ref[i],Voltage_mag[i],Edc[i],Ed_[i],Eq_[i],Ed__[i],Eq__[i],creal(Vd[i]),creal(Vq[i]),creal(id[i]),creal(iq[i]),Torq_ele[i],Torque_mech[i],delta[i],Slip[i]);

}
for(i=2;i<3;i++)
{
    fprintf(excel_data3,"\n");
fprintf(excel_data3,"%lf   %lf    %lf     %f    %f    %f    %f   %f    %f    %f    %f    %f    %f   %f  %f  %f   %f",time,Efd[i],V_ref[i],Voltage_mag[i],Edc[i],Ed_[i],Eq_[i],Ed__[i],Eq__[i],creal(Vd[i]),creal(Vq[i]),creal(id[i]),creal(iq[i]),Torq_ele[i],Torque_mech[i],delta[i],Slip[i]);

}

}



}

if(type==3)
{
    int busno;
    printf("CASE3: BUS FAULT. ENTER THE GENERATOR BUS NUMBER WHERE THE FAULT SHOULD OCCUR \n");
    scanf("%d",&busno);
double start_time=2.000;
double clear_time=2.050;
   FILE *excel_data1,*excel_data2,*excel_data3;
excel_data1=fopen("exceldat.txt","w");
excel_data2=fopen("exceldat2.txt","w");
excel_data3=fopen("exceldat3.txt","w");

//busdat(mat,nbus);
Ybus(linedat,TFdata,shuntdat,nlines,ntf,nsh,nbus);

Ybus_aug(nbus,nload,ngen,loaddat,genedat,busdat);



init_machine(busdat,genedat,nbus,ngen);


for(double time=0;time<40.00 ;time=time+0.001)
{
    if(time>start_time && time<clear_time)
    {
        // Ybus(linedat,TFdata,shuntdat,nlines,ntf,nsh);

Ybusaug_fault(nbus,nload,ngen,loaddat,genedat,busdat,busno);

newtwork_eq(genedat,ngen,time,start_time,clear_time);

    }
    else
    {
    //   Ybus(linedat,TFdata,shuntdat,nlines,ntf,nsh);

      Ybus_aug(nbus,nload,ngen,loaddat,genedat,busdat);

        newtwork_eq(genedat,ngen,time,start_time,clear_time);
    }



     FILE *machine_initials;
    machine_initials=fopen("duplicate.txt","r");

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


   for(i=0;i<1;i++)
{
    fprintf(excel_data1,"\n");
fprintf(excel_data1,"%lf   %lf    %lf     %f    %f    %f    %f   %f    %f    %f    %f    %f    %f   %f  %f  %f   %f",time,Efd[i],V_ref[i],Voltage_mag[i],Edc[i],Ed_[i],Eq_[i],Ed__[i],Eq__[i],creal(Vd[i]),creal(Vq[i]),creal(id[i]),creal(iq[i]),Torq_ele[i],Torque_mech[i],delta[i],Slip[i]);

}
 for(i=1;i<2;i++)
{
    fprintf(excel_data2,"\n");
fprintf(excel_data2,"%lf   %lf    %lf     %f    %f    %f    %f   %f    %f    %f    %f    %f    %f   %f  %f  %f   %f",time,Efd[i],V_ref[i],Voltage_mag[i],Edc[i],Ed_[i],Eq_[i],Ed__[i],Eq__[i],creal(Vd[i]),creal(Vq[i]),creal(id[i]),creal(iq[i]),Torq_ele[i],Torque_mech[i],delta[i],Slip[i]);

}
for(i=2;i<3;i++)
{
    fprintf(excel_data3,"\n");
fprintf(excel_data3,"%lf   %lf    %lf     %f    %f    %f    %f   %f    %f    %f    %f    %f    %f   %f  %f  %f   %f",time,Efd[i],V_ref[i],Voltage_mag[i],Edc[i],Ed_[i],Eq_[i],Ed__[i],Eq__[i],creal(Vd[i]),creal(Vq[i]),creal(id[i]),creal(iq[i]),Torq_ele[i],Torque_mech[i],delta[i],Slip[i]);

}

}


}
else if(type==1)
{
printf("TYPE1: Change in generator input\n");
printf("Enter the generator number(1,2 or 3)");
int genno;
double fac;
scanf("%d",&genno);
printf("Enter the factor(<1.05)");
scanf("%lf",&fac);
double start_time=2.000;
double clear_time=2.050;
    FILE *excel_data1,*excel_data2,*excel_data3;
excel_data1=fopen("exceldat.txt","w");
excel_data2=fopen("exceldat2.txt","w");
excel_data3=fopen("exceldat3.txt","w");
//busdat(mat,nbus);
Ybus(linedat,TFdata,shuntdat,nlines,ntf,nsh,nbus);

Ybus_aug(nbus,nload,ngen,loaddat,genedat,busdat);



init_machine(busdat,genedat,nbus,ngen);


//stability_function();
for(double time=0;time<40.00 ;time=time+0.001)
{
    if(time-start_time<=0.001 &&time-start_time>=0)// || time-clear_time<=0.001 && time-clear_time>=0)
    {


      change_genpower(ngen,genno,fac,time,start_time,clear_time);

        newtwork_eq(genedat,ngen,time,start_time,clear_time);

    }
    else
    {

        newtwork_eq(genedat,ngen,time,start_time,clear_time);
    }

     FILE *machine_initials;
    machine_initials=fopen("duplicate.txt","r");

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

   for(i=0;i<1;i++)
{
    fprintf(excel_data1,"\n");
fprintf(excel_data1,"%lf   %lf    %lf     %f    %f    %f    %f   %f    %f    %f    %f    %f    %f   %f  %f  %f   %f",time,Efd[i],V_ref[i],Voltage_mag[i],Edc[i],Ed_[i],Eq_[i],Ed__[i],Eq__[i],creal(Vd[i]),creal(Vq[i]),creal(id[i]),creal(iq[i]),Torq_ele[i],Torque_mech[i],delta[i],Slip[i]);

}
 for(i=1;i<2;i++)
{
    fprintf(excel_data2,"\n");
fprintf(excel_data2,"%lf   %lf    %lf     %f    %f    %f    %f   %f    %f    %f    %f    %f    %f   %f  %f  %f   %f",time,Efd[i],V_ref[i],Voltage_mag[i],Edc[i],Ed_[i],Eq_[i],Ed__[i],Eq__[i],creal(Vd[i]),creal(Vq[i]),creal(id[i]),creal(iq[i]),Torq_ele[i],Torque_mech[i],delta[i],Slip[i]);

}
for(i=2;i<3;i++)
{
    fprintf(excel_data3,"\n");
fprintf(excel_data3,"%lf   %lf    %lf     %f    %f    %f    %f   %f    %f    %f    %f    %f    %f   %f  %f  %f   %f",time,Efd[i],V_ref[i],Voltage_mag[i],Edc[i],Ed_[i],Eq_[i],Ed__[i],Eq__[i],creal(Vd[i]),creal(Vq[i]),creal(id[i]),creal(iq[i]),Torq_ele[i],Torque_mech[i],delta[i],Slip[i]);

}


}
}
else if(type==2)
{
    printf("TYPE2: Change in Vref of generator \n");
printf("Enter the generator number(1,2 or 3)");
int genno;
double fac;
scanf("%d",&genno);
printf("Enter the factor(<1.05)");
scanf("%lf",&fac);

  double start_time=2.000;
double clear_time=2.050;
   FILE *excel_data1,*excel_data2,*excel_data3;
excel_data1=fopen("exceldat.txt","w");
excel_data2=fopen("exceldat2.txt","w");
excel_data3=fopen("exceldat3.txt","w");
//busdat(mat,nbus);
Ybus(linedat,TFdata,shuntdat,nlines,ntf,nsh,nbus);

Ybus_aug(nbus,nload,ngen,loaddat,genedat,busdat);



init_machine(busdat,genedat,nbus,ngen);


//stability_function();
for(double time=0;time<40.00 ;time=time+0.001)
{
    if(time-start_time<=0.001 &&time-start_time>=0)// || time-clear_time<=0.001 && time-clear_time>=0)
    {


      change_genvref(ngen,genno,fac,time,start_time,clear_time);

        newtwork_eq(genedat,ngen,time,start_time,clear_time);

    }
    else
    {

        newtwork_eq(genedat,ngen,time,start_time,clear_time);
    }

     FILE *machine_initials;
    machine_initials=fopen("duplicate.txt","r");

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


   for(i=0;i<1;i++)
{
    fprintf(excel_data1,"\n");
fprintf(excel_data1,"%lf   %lf    %lf     %f    %f    %f    %f   %f    %f    %f    %f    %f    %f   %f  %f  %f   %f",time,Efd[i],V_ref[i],Voltage_mag[i],Edc[i],Ed_[i],Eq_[i],Ed__[i],Eq__[i],creal(Vd[i]),creal(Vq[i]),creal(id[i]),creal(iq[i]),Torq_ele[i],Torque_mech[i],delta[i],Slip[i]);

}
  for(i=1;i<2;i++)
{
    fprintf(excel_data2,"\n");
fprintf(excel_data2,"%lf   %lf    %lf     %f    %f    %f    %f   %f    %f    %f    %f    %f    %f   %f  %f  %f   %f",time,Efd[i],V_ref[i],Voltage_mag[i],Edc[i],Ed_[i],Eq_[i],Ed__[i],Eq__[i],creal(Vd[i]),creal(Vq[i]),creal(id[i]),creal(iq[i]),Torq_ele[i],Torque_mech[i],delta[i],Slip[i]);

}
  for(i=2;i<3;i++)
{
    fprintf(excel_data3,"\n");
fprintf(excel_data3,"%lf   %lf    %lf     %f    %f    %f    %f   %f    %f    %f    %f    %f    %f   %f  %f  %f   %f",time,Efd[i],V_ref[i],Voltage_mag[i],Edc[i],Ed_[i],Eq_[i],Ed__[i],Eq__[i],creal(Vd[i]),creal(Vq[i]),creal(id[i]),creal(iq[i]),Torq_ele[i],Torque_mech[i],delta[i],Slip[i]);

}



}

}

else if(type==4)
{
printf("TYPE4: LINE FAULT\n");
printf("Enter the BUS numbers that the line is connected to(1,2 or 3)");
int nbus1,nbus2;
double fac;
scanf("%d",&nbus1);
scanf("%d",&nbus2);
printf("Enter the factor(0<fac<1)");
scanf("%lf",&fac);
  double start_time=2.000;
double clear_time=2.050;
   FILE *excel_data1,*excel_data2,*excel_data3;
excel_data1=fopen("exceldat.txt","w");
excel_data2=fopen("exceldat2.txt","w");
excel_data3=fopen("exceldat3.txt","w");

//busdat(mat,nbus);
Ybus(linedat,TFdata,shuntdat,nlines,ntf,nsh,nbus);

Ybus_aug(nbus,nload,ngen,loaddat,genedat,busdat);



init_machine(busdat,genedat,nbus,ngen);


for(double time=0;time<40.00 ;time=time+0.001)
{
    if(time-start_time<=0.001 && time-start_time>=0) //&& time<clear_time)
    {
        // Ybus(linedat,TFdata,shuntdat,nlines,ntf,nsh);
Ybus_linefault(linedat,TFdata,shuntdat,nlines,ntf,nsh,nbus,nbus1,nbus2,fac,time,start_time,clear_time);
    }
    else if(time-clear_time<=0.001 && time-clear_time>=0)
    {
      Ybus(linedat,TFdata,shuntdat,nlines,ntf,nsh,nbus);
    }
 Ybus_aug(nbus,nload,ngen,loaddat,genedat,busdat);
newtwork_eq(genedat,ngen,time,start_time,clear_time);

    //}
  //  else
  //  {
    //   Ybus(linedat,TFdata,shuntdat,nlines,ntf,nsh);
   //Ybus(linedat,TFdata,shuntdat,nlines,ntf,nsh);
   //   Ybus_aug(nbus,nload,ngen,loaddat,genedat,busdat);

     //   newtwork_eq(genedat,ngen,time,start_time,clear_time);




     FILE *machine_initials;
    machine_initials=fopen("duplicate.txt","r");

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


  for(i=0;i<1;i++)
{
    fprintf(excel_data1,"\n");
fprintf(excel_data1,"%lf   %lf    %lf     %f    %f    %f    %f   %f    %f    %f    %f    %f    %f   %f  %f  %f   %f",time,Efd[i],V_ref[i],Voltage_mag[i],Edc[i],Ed_[i],Eq_[i],Ed__[i],Eq__[i],creal(Vd[i]),creal(Vq[i]),creal(id[i]),creal(iq[i]),Torq_ele[i],Torque_mech[i],delta[i],Slip[i]);

}
  for(i=1;i<2;i++)
{
    fprintf(excel_data2,"\n");
fprintf(excel_data2,"%lf   %lf    %lf     %f    %f    %f    %f   %f    %f    %f    %f    %f    %f   %f  %f  %f   %f",time,Efd[i],V_ref[i],Voltage_mag[i],Edc[i],Ed_[i],Eq_[i],Ed__[i],Eq__[i],creal(Vd[i]),creal(Vq[i]),creal(id[i]),creal(iq[i]),Torq_ele[i],Torque_mech[i],delta[i],Slip[i]);

}
  for(i=2;i<3;i++)
{
    fprintf(excel_data3,"\n");
fprintf(excel_data3,"%lf   %lf    %lf     %f    %f    %f    %f   %f    %f    %f    %f    %f    %f   %f  %f  %f   %f",time,Efd[i],V_ref[i],Voltage_mag[i],Edc[i],Ed_[i],Eq_[i],Ed__[i],Eq__[i],creal(Vd[i]),creal(Vq[i]),creal(id[i]),creal(iq[i]),Torq_ele[i],Torque_mech[i],delta[i],Slip[i]);

}

}

}


}


