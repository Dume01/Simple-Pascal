#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_VARIABLES 1000

struct Variable {
    char var_name[50];
    char data_type[50];
    int isArray;
    int isAssigned;
};

struct Variable variables[MAX_VARIABLES];
int total = 0;

void add_variable_name(const char *name) {
    if (total < MAX_VARIABLES) {
        strcpy(variables[total].var_name, name);
        total++;
    } else {
        fprintf(stderr, "Error: Maximum number of variables reached\n");
    }
}

void add_variable_data_type(const char *type,int isA) {
    for (int i = total - 1; i >= 0; i--) {
        if (variables[i].data_type[0] == '\0') {
            if(isA!=0)
            {
                for(int j=0;j<isA;j++)
                {
                    strcpy(variables[i].data_type, type);
                    variables[i].isArray=isA;
                    variables[i].isAssigned=0;
                }
            }
            else
            {
                    strcpy(variables[i].data_type, type);
                    variables[i].isArray=isA;
                    variables[i].isAssigned=0;
            }
        } else {
            break;
        }
    }
}

bool isPresent(const char *name) {
    for (int i = 0; i < total; i++) {
        if (strcmp(variables[i].var_name, name) == 0) {
            return true;
        }
    }
    return false;
}

char* dataType(const char *name) {
    if(strcmp(name,"INT")==0) return "INT";
    if(strcmp(name,"BOOLEAN")==0) return "BOOLEAN";
    if(strcmp(name,"CHAR")==0) return "CHAR";
    if(strcmp(name,"REAL")==0) return "REAL";
    char* dt = NULL;
    if (isPresent(name)) {
        for (int i = 0; i < total; i++) {
            if (strcmp(variables[i].var_name, name) == 0) {
                dt = strdup(variables[i].data_type);
                break;
            }
        }
    } else {
        dt = strdup("SEND ERROR");
    }
    return dt;
}

char* dataType_constant(const char *val) {
    char* type = NULL;
    if (strcmp(val, "INTEGER") == 0) {
        type = strdup("INT");
    } else if (strcmp(val, "REALX") == 0) {
        type = strdup("REAL");
    } else if (strcmp(val, "CHARACTER") == 0) {
        type = strdup("CHAR");
    } else if (strcmp(val, "TRU") == 0 || strcmp(val, "FAL") == 0) {
        type = strdup("BOOLEAN");
    }
    return type;
}

void print()
{
    for(int i=0;i<total;i++)
    {
        printf("%d %s %s %d %d\n",i,variables[i].var_name,variables[i].data_type,variables[i].isArray,variables[i].isAssigned);
    }
}

bool is_This_Array(const char *name)
{
    for(int i=0;i<total;i++)
    {
        if(strcmp(variables[i].var_name,name)==0)
        {
            if(variables[i].isArray==0)
                return 0;
            else
                break;
        }
    }
    return 1;
}

void assign_val_done(const char *name)
{   
    //printf("%s\n",name);
    for(int i=0;i<total;i++)
    {
        if(strcmp(variables[i].var_name,name)==0)
        {
            variables[i].isAssigned=1;
        }
    }
}

bool is_Assigned(const char *name)
{   
    bool tell;
    for(int i=0;i<total;i++)
    {
        if(strcmp(variables[i].var_name,name)==0)
        {
            tell=variables[i].isAssigned;
        }
    }
    return tell;
}

int getMAx(char* name)
{
    int a=0;
    for(int i=0;i<total;i++)
    {
        if(strcmp(variables[i].var_name,name)==0)
        {
            a=variables[i].isArray;
        }
    }
    return a;
}