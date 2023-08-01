#include "cmd_fun.h"

#define MAX_BUFFER_SIZE     1024
#define TMP_BUFFER_SIZE     128

//command execution functions
static int execute(char *cmd, char *result)
{
    FILE *fp = NULL;
    char output[MAX_BUFFER_SIZE] = {0};
    char *str = NULL,*pos=NULL;

    fp = popen(cmd, "r");
    if(NULL == fp)
    {
        printf("Failed to run command\n" );
        return RETURN_ERR;
    }

    /* only the first line of the output is of interest */
    fgets(output, sizeof(output)-1, fp);
    if (NULL != (pos=strchr(output, '\n')) ) {
        *pos = '\0';
    }
    str = strstr(output, ":");

    if(NULL != str)
    {
        strcpy(result, (str + 1));
    }
    else
    {
        strcpy(result,output);
    }

    printf("\nresult = %s\n", result);
    pclose(fp);

    return RETURN_OK;
}    

//This function used to collect the cpu info
int platform_model_info(char *pValue) {
    char model[TMP_BUFFER_SIZE] = {'\0'};
    int ret = RETURN_ERR;

    if(pValue == NULL)
    {
	return RETURN_ERR;
    }
    ret = execute("grep 'model name' /proc/cpuinfo", model);
    if(RETURN_OK != ret)
    {
	printf("\nError %s\n", __func__);
    }
    else
    {
	strncpy(pValue, model, strlen(model));
    }

    return ret;
}


