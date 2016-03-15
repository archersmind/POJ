#include<cstdio>
#include<cstring>
#include<algorithm>
#define size 1005
using namespace std;
struct pix
{
    int pos;    //表示答案中这个点的位置
    int code;   //这个点上的答案值
}outmap[size*8];

int inmap[size][2];//inmap[][0]表示这个连续段的数值，inmap[][1]表示这个连续段的长度
int width,cntp,tot;

int cmp(pix x,pix y)//排序比较函数，最后以pos升序排序
{
    return x.pos<y.pos;
}
inline int abs(int x)//cmath库里其实有abs函数，这里无聊写了一个
{
    return x>0?x:-x;
}

int getnum(int pos)//返回原图中pos位置上的数值
{
    int p=0,i=0;
    while (p<pos)
        p+=inmap[i++][1];
       
    return inmap[i-1][0];
}
int getcode(int pos)//计算pos位置上的答案
{
    int num=getnum(pos),ret=0;
   
    int row=(pos-1)/width;//关于row和col的原理主程序中有
    int col=(pos-1)%width;
   
    for (int i=row-1;i<=row+1;i++)
        for (int j=col-1;j<=col+1;j++)
        {
            int tpos=i*width+j;
            if (i<0||j<0||j>=width||tpos>=tot || tpos==pos-1)
                continue;//这里计算差的绝对值时要排除pos自己
               
            int tmp=getnum(tpos+1);
            if (abs(tmp-num)>ret)ret=abs(tmp-num);//更新ret
        }
    return ret;
}
int main()
{
   
   
    while (scanf("%d",&width)&& width>0)
    {
       
       
        int num,len;
        cntp=tot=0;//必须得每次都赋0
        while (scanf("%d%d",&num,&len)&& len>0)
        {
            inmap[cntp][0]=num;
            inmap[cntp++][1]=len;
            tot+=len;//tot是map中像素的个数
        }
        printf("%d\n",width);//按照同样格式输出
       
       
       
        int pos=1,k=0;//pos从1开始标号
        for (int p=0;p<=cntp;p++)//枚举每一个连续段
        {   
           
            int row=(pos-1)/width;
            int col=(pos-1)%width;
           
           
            for (int i=row-1;i<=row+1;i++)
                for (int j=col-1;j<=col+1;j++)
                {
                    int tpos=i*width+j;//这里算出来的tpos其实是tpos的标号减一
                    if (i<0 || j<0 || j>=width || tpos>=tot)
                        continue;//tpos在map的外面了
                       
                    outmap[k].pos=tpos+1;
                    outmap[k++].code=getcode(tpos+1);//答案存入outmap   
                }
               
            pos+=inmap[p][1];//跳跃到下一个连续段的起始格
        }
       
       
        sort(outmap,outmap+k,cmp);
       
       
        pix tmp=outmap[0];
        for (int i=0;i<k;i++)
        {
            if (outmap[i].code==tmp.code) //表明连续，则跳过不输出
                continue;
            printf("%d %d\n",tmp.code,outmap[i].pos-tmp.pos);
            tmp=outmap[i];
        }
        printf("%d %d\n",tmp.code,tot-tmp.pos+1);//最后一部分
        printf("0 0\n");//按照格式输出
    }
    printf("0\n");//格式
    return 0;
}
