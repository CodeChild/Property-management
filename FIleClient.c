#include<stdio.h>
#include<stdlib.h>
char fileName[]="payment.data";
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
        printf("Ҫ����������¼��(y/n)");
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


