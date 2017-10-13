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
static struct  Payment mPayments[100];
static int eofIndex=0;
void openFile(FILE* fp)
{

    if((fp=fopen(fileName,"rb"))==NULL)
        if((fp=fopen(fileName,"wb"))==NULL)
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
    int i=eofIndex;
     if((fp=fopen(fileName,"wb"))==NULL)
        {
            printf("不能打开文件\n");
            exit(0);
        }
    do
    {
        scanf("%d %s %d %s %d %d",&mPayment.roomId,mPayment.name,&mPayment.area,mPayment.date,&mPayment.payMonth,&mPayment.money);
        mPayments[i]=mPayment;
        printf("要输入其它记录吗？(y/n)");
        getchar();
        ch=getchar();
        i++;
    }
    while(ch=='y');
    eofIndex=i;
    for(i=0;i<=100;i++){
        fwrite(&mPayments[i],sizeof(mPayments[i]),1,fp);
    }

    fclose(fp);
}
void readFile()
{
    struct Payment mPayment;
    FILE *fp;
    int i=0;
    if((fp=fopen(fileName,"rb"))==NULL)
    {
        printf("不能打开文件\n");
        exit(0);
    }
    printf("房间号 业主名 房间面积 缴费日期 交了几个月 金额\n");
    while(fread(&mPayment,sizeof(mPayment),1,fp)==1){
        mPayments[i]=mPayment;
        if(mPayment.roomId!=0){
            printf("%d    %s    %d    %s    %d    %d\n",mPayment.roomId,mPayment.name,mPayment.area,mPayment.date,mPayment.payMonth,mPayment.money);
            i++;
        }
        else break;
    }
    eofIndex=i;
    fclose(fp);
}
void modifyFile(int roomId,char* date,int money)
{
    FILE *fp;
    if((fp=fopen(fileName,"wb"))==NULL)
    {
        printf("不能打开文件\n");
        exit(0);
    }
    int i,index;
    for(i=0;i<100;i++)
        if(roomId==mPayments[i].roomId&&!strcmp(date,mPayments[i].date))
        {
            mPayments[i].money+=money;
            index=i;
            break;
        }
    for(i=0;i<=100;i++)
         fwrite(&mPayments[i],sizeof(mPayments[i]),1,fp);

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
 if((fp=fopen(fileName,"rb"))==NULL)
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
 if((fp=fopen("Payment.data","rb"))==NULL)
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
  fclose(fp);

}





