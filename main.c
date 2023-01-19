#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#define N 20
double calc(int buff[20]);

struct mystruct{
    double typedouble ;
    char typechar[10];
};

int main(void){
    char c;
    struct mystruct x;
    srand(time(NULL));
    double is_calc;
    int randint,fint;
    int buff[N] = {0};
    for(int i = 0;i < N; i++){
        randint = rand() % 1000 + 1;
        if(randint % 2 == 0) buff[i] = rand() % 999 + 100;
        else buff[i] = rand() % -100 + -999;
    }
    calc(buff);
    FILE * fp;
    fp = fopen("C:/Users/mario/OneDrive/Desktop/numbers.txt","r");
    if(fp == NULL) exit(10);
    for(int i = 0; i < N; i++){
        fscanf(fp,"%d",&fint);
        buff[i] = fint;
    }
    for(int i = 0;i < N; i++) printf("buff is %d\n",buff[i]);
    x.typedouble = calc(buff);
    x.typechar[10] = "Random";

    FILE * fpout;
    fpout = fopen("results.dat","w");


    fprintf(fpout,"%s\n",x.typechar);
    fprintf(fpout,"%lf\n",x.typedouble);

}

double calc(int buff[20]){
    int i;
    double sum1,sum2;
    for(i = 0;i < N;i++){
        sum1 = sum1 + pow(buff[i],2);
        sum2 = sum2 + abs( buff[i]);
    }
    printf("result of calc is %lf\n",sum1 - 20 * sum2);
    return sum1 - 20 * sum2;
}