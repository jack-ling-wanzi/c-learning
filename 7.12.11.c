#include<stdio.h>
float ccl_num(float);
int main(void)
{
    _Bool f=1;
    char choice;
    float all_cost=0,all_weight=0,carrot=0,artichoke=0,beetroot=0,carrot_=0,artichoke_=0,beetroot_=0,
            save1=0,transport_fee=0,add=0;
    while(f)
    {
        printf("a:carrot,1.09$/kilo\nb:artichoke,2.05$/kilo\nc:beetroot,1.15$/kilo\n");
        scanf(" %c",&choice);
        switch (choice)
        {
            case 'a':carrot = ccl_num(carrot);carrot_ = carrot * 1.09;break;
            case 'b':artichoke = ccl_num(artichoke);artichoke_ = artichoke * 2.05;break;
            case 'c':beetroot = ccl_num(beetroot);beetroot_ = beetroot * 1.15;break;
            default:f = 0;
        }

    }

    all_cost = carrot_ + artichoke_ + beetroot_;
    all_weight = carrot + artichoke + beetroot;
    if (all_cost >=100){
        save1 = all_cost * 0.15;
        all_cost -= save1;
    }

    if (all_weight <=5)
    transport_fee = 6.5;
    else if (all_weight <= 20)
    transport_fee = 14;
    else 
    transport_fee = 14+0.5*(all_weight-20);
    
    printf("carrot:%f$,%fkilo.\nartichoke:%f$,%fkilo.\nbeetroot:%f$,%fkilo.\n"
        "all_cost:%f,zhekou:%f,\ntransport and package fee:%f,"
        ,carrot_,carrot,artichoke_,artichoke,beetroot_,beetroot,all_cost+transport_fee,save1,
        transport_fee);
}
float ccl_num(float num)
{
    float add;
    printf("hou many do you need?");
    scanf("%f",&add);
    num +=add;
    return num;
}
