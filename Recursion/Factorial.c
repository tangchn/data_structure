
#include <stdio.h>
#include <stdlib.h>

double fac(double i);

int main(void)
{
    double i;
    printf("请输入待求数：\n");
    scanf("%lf",&i);
    printf("%.lf!的结果是：%.lf\n",i,fac(i));

}

double fac(double i)
{
    if(i == 1)
    {
        return 1;
    }else
    {
        return i*fac(i-1);
    }
}
