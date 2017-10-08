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
    printf("\n\n添加记录\n");
    printf("请输入房间号,业主名,房间面积,缴费日期,交了几个月,金额\n");
    printf("(中间以空格隔开)\n");
    printf(">");
    addFileContent();
    printf("\n添加后的记录如下：\n");
    printf("房间号 业主名 房间面积 缴费日期 交了几个月 金额\n");
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
    printf("小区物业缴费系统");
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
    printf("1.添加缴费记录\n");
    printf("2.修改缴费记录\n");
    printf("3.查询缴费记录\n");
    printf("4.退出");
    for(i=0; i<2; i++)
        printf("\n");
    do
    {
        printf("请输入序号：");
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
            printf("无效选项，请从新输入");
        }
    }
    while(!(tag>=1&&tag<=4));


}
void modifyRecord()
{
    system("cls");
    returnMenu();
}
void queryRecord()
{
    system("cls");
    //printf("房间号 业主名 房间面积 缴费日期 交了几个月 金额\n");
    queryFile();
    //readFile();
    returnMenu();
}
void returnMenu()
{
    int tag;
    printf("\n\n1.返回\n");
    printf("2.退出\n");
    do
    {
        printf("请输入序号：");
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
            printf("无效选项，请从新输入");
        }
    }
    while(!(tag>=1&&tag<=2));
}
