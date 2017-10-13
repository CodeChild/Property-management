#ifndef FILECLIENT_H_INCLUDED
#define FILECLIENT_H_INCLUDED

extern void openFile(FILE* fp);
extern void addFileContent();
extern void readFile();
extern void queryFile();
extern void modifyFile(int roomId,char* date,int money);
#endif // FILECLIENT_H_INCLUDED
