#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void cmd(char *command) {
	FILE *fp = popen(command,"r");
	char buff[64];
	char output[128] = "";
	if (fp == NULL)
	{
		fprintf(stderr,"popen() == NULL");
		exit(EXIT_FAILURE);
	}
	while (fgets(buff,sizeof(buff),fp) != NULL)
	{
		strcat(output,buff);	
	}
	printf("%s",output);
	pclose(fp);
}




int main() {

	FILE *file;
	char line[100];
	char *token;
	
	char promptChar = '%';
	char middlePromptChar = '@';
	char user[] = "PtR";
	char hostname[] = "machine";

	file = fopen("meshell","r");

	fgets(line,sizeof(line),file);

	token = strtok(line,"%");
	token = strtok(NULL,"%");
	system(token);
	//cmd(token);


	return 0;
}
