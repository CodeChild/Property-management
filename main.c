#include<stdio.h>
#include"FileClient.h"
#include<windows.h>
void initTitle();
void initMenu();
void addRecord();
void modifyRecord();
void queryRecord();
void returnMenu();
int main()
{
    initTitle();
    initMenu();
    return 0;
}
void addRecord()
{
    system("cls");
    readFile();
    printf("\n\n��Ӽ�¼\n");
    printf("�����뷿���,ҵ����,�������,�ɷ�����,���˼�����,���\n");
    printf("(�м��Կո����)\n");
    printf(">");
    addFileContent();
    printf("\n��Ӻ�ļ�¼���£�\n");
    readFile();
    returnMenu();
}
void initTitle()
{
    int i;
    for(i=0; i<2; i++)
        printf("\n");
    for(i=0; i<32; i++)
        printf("=");
    printf("\n");
    for(i=0; i<8; i++)
    {
        printf(" ");
    }
    printf("С����ҵ�ɷ�ϵͳ");
    for(i=0; i<8; i++)
    {
        printf(" ");
    }
    printf("\n");
    for(i=0; i<32; i++)
        printf("=");
    printf("\n");
}
void initMenu()
{
    int tag=0,i;
    printf("1.��ӽɷѼ�¼\n");
    printf("2.�޸ĽɷѼ�¼\n");
    printf("3.��ѯ�ɷѼ�¼\n");
    printf("4.�˳�");
    for(i=0; i<2; i++)
        printf("\n");
    do
    {
        printf("��������ţ�");
        scanf("%d",&tag);
        switch(tag)
        {
        case 1:
            addRecord();
            break;
        case 2:
            modifyRecord();
            break;
        case 3:
            queryRecord();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("��Чѡ����������");
        }
    }
    while(!(tag>=1&&tag<=4));


}
void modifyRecord()
{
    char date[50];
    int roomId;
    int money;
    system("cls");
    readFile();
    printf("�����뷿��ţ�");
    scanf("%d",&roomId);
    printf("\n������ɷ�����:");
    scanf("%s",date);
    printf("\n�������շ�����Ľ��(�����շѣ���������)��");
    scanf("%d",&money);
    modifyFile(roomId,date,money);
    readFile();
    returnMenu();
}
void queryRecord()
{
    system("cls");
    //printf("����� ҵ���� ������� �ɷ����� ���˼����� ���\n");
    queryFile();
    //readFile();
    returnMenu();
}
void returnMenu()
{
    int tag;
    printf("\n\n1.����\n");
    printf("2.�˳�\n");
    do
    {
        printf("��������ţ�");
        scanf("%d",&tag);
        switch(tag)
        {
        case 1:
        {
            system("cls");
            initTitle();
            initMenu();
            break;
        }
        case 2:
            exit(0);
            break;
        default:
            printf("��Чѡ����������");
        }
    }
    while(!(tag>=1&&tag<=2));
}
