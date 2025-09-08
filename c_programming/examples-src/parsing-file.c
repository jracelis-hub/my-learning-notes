#include <stdio.h>

char *get_request(char *cmd) {
	int i = 0;
	char cmds[] = { 'D','U','L','R'};
	
	for (i; *(cmd+i) != ';';i++) {
		if ( *(cmd+i) == cmds[0] || *(cmd+i) == cmds[1] || *(cmd+i) == cmds[2] || *(cmd+i) == cmds[3]) {
			char *temp = cmd+i;
			cmd = temp;
			continue;
		}
	}
	return cmd;
}

/* Stores the address of the first occurence of / 
   but if it finds */
char *get_file(char *file_path) {

	int i = 0;

	for (i; *(file_path+i) != '\0' ;i++) {
		if ( *(file_path+i) == '/' ) {
		/* This holds the address of the location where / is found */
			char *temp = (file_path+i); 
			file_path = temp + 1;
			continue;
		}
		if ( *(file_path+i) == '\n') {
			*(file_path+i) = '\0';
		}
	}

	return file_path;
}

int main() {

	char file_path[] = "/home/file.txt/random\n";
	char *request = "Download;";

	char *file = get_file(file_path);

	printf("%s\n",file);

	char *cmd = get_request(request);

	printf("%s\n",cmd);



	return 0;
}
