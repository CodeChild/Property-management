#include<stdio.h>
#include<stdlib.h>

const char fileName[]="payment.data";
struct Payment
{
    int roomId;
    char name[20];
    int area;
    //�ɷ�����
    char date[50];
    //���˼�����
    int payMonth;

    int money;
};
void openFile(FILE* fp)
{

    if((fp=fopen(fileName,"r"))==NULL)
        if((fp=fopen(fileName,"w"))==NULL)
        {
            printf("���ܴ��ļ�\n");
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
        printf("Ҫ����������¼��(y\n)");
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
        printf("���ܴ��ļ�\n");
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
 printf("������Ų�ѯ�밴1����ҵ������ѯ�밴2,���������������˵�");
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
  printf("û���κμ�¼��\n");
  exit(0);
 }
 printf("������Ҫ��ѯ�ļ�¼�ķ����\n");
 scanf("%d",&fjh);
 printf("�����\tҵ����\t");
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
  printf("û���κμ�¼��\n");
  exit(0);
 }
 printf("������Ҫ��ѯ�ļ�¼��ҵ����\n");
 scanf("%s",&yzm);
 printf("�����\tҵ����\t���\t�ɷ�����\t��������\t���\n");
 while(fread(&mPayment,sizeof(mPayment),1,fp)==1)
 {
  if(strcmp(yzm,mPayment.name)==0)
  printf("\n%d\t%s\t%d\t%s\t%d\t%d",mPayment.roomId,mPayment.name,mPayment.area,mPayment.date,mPayment.payMonth,mPayment.money);


 }

}





