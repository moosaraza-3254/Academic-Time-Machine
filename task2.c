#include <stdio.h>
#include <string.h>

void addRecord(const char* filename){

    FILE *fp;
    fp=fopen(filename, "a");

    char name[40];
    char rollNum[10];
    char email[50];

    printf("Enter Name: ");
    scanf("%39s", name);
    printf("Enter Roll Number: ");
    scanf("%9s", rollNum);
    printf("Enter Email: ");
    scanf("%49s", email);

    fputc('\n', fp);
    fputs("<New Entry>\n", fp);
    fputs(name, fp);
    fputc('\n', fp);
    fputs(rollNum, fp);
    fputc('\n', fp);
    fputs(email, fp);

    fclose(fp);

}
void readRecord(const char* filename){
    FILE *fp= fopen(filename, "r");
    int num=0;
    int count=0;
    char curStr[64];
    printf("Input number of record to read.\n");
    scanf("%d", &num);
    while (fgets(curStr, 63, fp)!=NULL){
        if (strcmp(curStr,"<New Entry>\n")==0){
            count++;
        }
        if (count==num){
            fgets(curStr, 63, fp);
            printf("Name: %s", curStr);
            fgets(curStr, 63, fp);
            printf("Roll Number: %s", curStr);
            fgets(curStr, 63, fp);
            printf("Email: %s", curStr);

            break;
        }
    }
    fclose(fp);

}
void deleteRecord(const char* filename){

}

int main(){
    const char* filename="StudentRecord.txt";
    
    char mode = 'x';
    while (1){
        printf("Press A to add student to record\nPress R to read student records\nPress D to to delete student record\nPress S to stop program\n");
        scanf("%c", &mode);
        if (mode == 'A'){
            addRecord(filename);
        }
        else if (mode == 'R'){
            readRecord(filename);
        }
        else if (mode == 'D'){
            deleteRecord(filename);
        }
        else if (mode == 'S'){
            break;
        }
        else {
            printf("Invalid input. Try Again\n");
        }    
    }
    return 0;
}