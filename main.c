#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <math.h>
#define PI 3.141593
int maximum(int x,int y)
{

    if(x>y)
    {

        return x;
    }
    else
    {
        return y;
    }
}
int max(int *arr,int size)
{


  int temp=arr[0];
    for(int i=1;i<size;i++)
    {
        if(arr[i]>temp)
        {
            temp=arr[i];

        }
//        else{
//            temp=arr[i-1];
//        }

    }
    return temp;
}

int main()
{



    fileread();

}
