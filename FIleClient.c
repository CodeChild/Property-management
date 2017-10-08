#include<stdio.h>
#include<stdlib.h>

const char fileName[]="payment.data";
struct Payment
{
    int roomId;
    char name[20];
    int area;
    //缴费日期
    char date[50];
    //交了几个月
    int payMonth;

    int money;
};
void openFile(FILE* fp)
{

    if((fp=fopen(fileName,"r"))==NULL)
        if((fp=fopen(fileName,"w"))==NULL)
        {
            printf("不能打开文件\n");
            exit(0);
        }
}
void addFileContent()
{
    struct Payment mPayment;
    char ch;
    FILE *fp;
    if((fp=fopen(fileName,"a"))==NULL)
        openFile(fp);
    do
    {
        scanf("%d %s %d %s %d %d",&mPayment.roomId,mPayment.name,&mPayment.area,mPayment.date,&mPayment.payMonth,&mPayment.money);
        fwrite(&mPayment,sizeof(mPayment),1,fp);
        printf("要输入其它记录吗？(y\n)");
        getchar();
        ch=getchar();
    }
    while(ch=='y');
    fclose(fp);
}
void readFile()
{
    struct Payment mPayment;
    FILE *fp;
    if((fp=fopen(fileName,"r"))==NULL)
    {
        printf("不能打开文件\n");
        exit(0);
    }
    while(fread(&mPayment,sizeof(mPayment),1,fp)==1)
        printf("%d    %s    %d    %s    %d    %d\n",mPayment.roomId,mPayment.name,mPayment.area,mPayment.date,mPayment.payMonth,mPayment.money);
    fclose(fp);
}
void modifyFile(int roomId,int money)
{
    struct Payment mPayment;
    FILE *fp;
    openFile(fp);
    int index=0,i=0;
    while(fread(&mPayment,sizeof(mPayment),1,fp)==1)
    {
        index++;
        if(roomId==mPayment.roomId) break;
    }

}




void queryFile()
{
 int num;
 printf("按房间号查询请按1，按业主名查询请按2,按其他键返回主菜单");
 scanf("%d",&num);
 switch(num)
 {
  case 1:queryfjh();break;
  case 2:queryyzm();break;
  default:returnMenu();
 }
}
void queryfjh()
{
 struct Payment mPayment;
 int fjh;
 char yn;
 FILE *fp;
 if((fp=fopen(fileName,"r"))==NULL)
 {
  printf("没有任何记录！\n");
  exit(0);
 }
 printf("请输入要查询的记录的房间号\n");
 scanf("%d",&fjh);
 printf("房间号\t业主名\t");
 while(fread(&mPayment,sizeof(mPayment),1,fp)==1)
 {
  if(fjh==mPayment.roomId)
    printf("\n%d\t%s\t%d\t%s\t%d\t%d",mPayment.roomId,mPayment.name,mPayment.area,mPayment.date,mPayment.payMonth,mPayment.money);
 }
 fclose(fp);
}
void queryyzm()
{
 struct Payment mPayment;
 FILE *fp;
 char yzm[20];
 char yn;
 if((fp=fopen("Payment.data","r"))==NULL)
 {
  printf("没有任何记录！\n");
  exit(0);
 }
 printf("请输入要查询的记录的业主名\n");
 scanf("%s",&yzm);
 printf("房间号\t业主名\t面积\t缴费日期\t交费月数\t金额\n");
 while(fread(&mPayment,sizeof(mPayment),1,fp)==1)
 {
  if(strcmp(yzm,mPayment.name)==0)
  printf("\n%d\t%s\t%d\t%s\t%d\t%d",mPayment.roomId,mPayment.name,mPayment.area,mPayment.date,mPayment.payMonth,mPayment.money);


 }

}





