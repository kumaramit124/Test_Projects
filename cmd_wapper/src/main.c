#include "cmd_fun.h"

int main() {
    //get the system information
    int res; 
    char *output = (char *)malloc(512);
    res = platform_model_info(output);
    if(RETURN_OK != res)
    {
	printf("Fail to get system info\n");
    }
    else
    {
	printf("System info Success!!!\n");
    }

    free(output);
    return 0;
}

