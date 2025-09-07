#include <stdio.h>
#include <string.h>

void remove_spaces(char file[],size_t len);

int main() {

	char response[] = "Download;              File.txt\n";
	/*
	char *request = strtok(response,";");
	char *file = strtok(NULL,"\n");
	*/
	
	char request[12];
	char file[32];
	sscanf(response,"%[A-Za-z];%[^;\n]",request,file);

	remove_spaces(file,strlen(file)+1);

	printf("%s\n",file);

	return 0;
}

void remove_spaces(char file[],size_t len) {

	int s = 0;
	for (int i=0;i<len;i++) {
		if ( file[i] != ' ' ) {
			file[s++] = file[i];
		}
	}
	printf("%d\n",s);
	file[s] = '\0';
	if ( file[s-1] == '\0' ) { 
		printf("Its null\n");
	} else {
		printf("Its not null\n");
	}
}
