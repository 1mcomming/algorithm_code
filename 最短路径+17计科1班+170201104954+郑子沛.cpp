#include <stdio.h> 

#define none 1000000          //  无限大为不通 
#define NUM 4      //d点数为4 
int a[NUM][NUM]={
        1,none,6,4,
        2,3,3,1,
        2,4,none,1,
        5,3,2,3
    };
#define OK 1
#define ERROR 0                 
typedef int status;

bool finish(bool *S,int n)          //是否完成 找寻 
{
    for(int i=0;i<n;i++)
    {
        if(!S[i])
        return false;
    }
    return true; 
}

status djs(int n,int t)//a 为数组 n 为点的个数，v为起始点 
{
    //初始化数组v
    int D[n];
    for(int i=0;i<n;i++)
    D[i]=a[t][i];
    D[t]=0;
    //初始化已访问数集S;
    bool S[n];

    for(int i=0;i<n;i++)
    S[i]=false;

    S[t]=true;

    int j=0;
        int min=none;

    while (!finish(S,n))
    {   j=0;
        min=none;

        for(int i=0;i<n;i++)        //找到观测域中最短路径（v,j） 
        {
            if(S[i]) continue;

            if(min>D[i]) 
            {min=D[i];j=i;}     
        }   

        S[j]=true;      //将j纳入点集S中 

        for(int i=0;i<n;i++)        //更新观测域 
        {
            if(S[i]) continue;
            if(D[i]>D[j]+a[j][i])
            D[i]=D[j]+a[j][i];      
        }


    }

    for(int i=0;i<n;i++)                //输出 
    {
        printf("最短路径是（v,%d）长度是%d\n",i,D[i]);
    }
    return OK; 
}
int main()
{

    djs(NUM,1);
    return 0;

} 

