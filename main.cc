#include "cJSON.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
static int getFileSize(FILE *fp){
    fseek(fp,0,SEEK_END);
    int fsize = ftell(fp);
    return fsize;
}
static void load_json_string(FILE *fp,char *data,int fsize)
{
    rewind(fp);
    fread(data,1,fsize,fp);
    data[fsize]='\0';
    return;

}
int main(int argc,char **argv){
    FILE *fp;
    fp = fopen("./test.json","rb");
    if(fp==NULL){
        printf("error \n");
    }
    int fsize = getFileSize(fp);
    char *data = (char *)malloc((fsize+1)*sizeof(char));
    load_json_string(fp,data,fsize);
    fclose(fp);
    cJSON *rootjson=cJSON_Parse(data);
    cJSON *node = cJSON_GetObjectItem(rootjson,"enable");
    int enable = node->valueint;
    cJSON *subnode = cJSON_GetObjectItem(rootjson,"clmax");
    cJSON *clmax_array = cJSON_GetArrayItem(subnode,0);
    double x = clmax_array->valuedouble;
    printf("%d ,%d\n",enable,x);
cJSON* root = cJSON_CreateObject();
cJSON* item = cJSON_CreateObject();
cJSON* next = cJSON_CreateObject();
cJSON* obj = cJSON_CreateObject();
cJSON_AddItemToObject(root,"wb",cJSON_CreateNumber(3));
cJSON_AddItemToObject(root,"book",cJSON_CreateString("dddd"));
cJSON_AddItemToObject(root,"author",cJSON_CreateString("wanger"));

cJSON* array = NULL;
cJSON_AddItemToObject(root,"books",array=cJSON_CreateArray());
float numbers[5]={0};
numbers[1] = 1.12221;
cJSON* floatarray  = cJSON_CreateFloatArray(numbers, 4);
cJSON_AddItemToObject(root,"clmax",floatarray);
printf("%s\n", cJSON_Print(root));
FILE *fp1 = fopen("create.json","w");
char *buf = cJSON_Print(root);
fwrite(buf,strlen(buf),1,fp);
fclose(fp1);
cJSON_Delete(root);
    return 0;

}