#include <stdio.h>

/* Challenge
   ---------------------
   Use the presidents.dat database file
   Read the 10 records stored in the file backward
   Use the fseek() function to set the file position indicator
   Obtain each record from the file in reverse order.
   Output each record, on after the other
*/

int main(int argc, char* argv[]) {
	
	if ( argc == 1 ) {
		FILE *fp;
		const char *filename = "presidents.dat";
		struct person {
			char name[32];
			int inaguaration;
			int age;
		} presidents;
		int x;

		fp = fopen(filename,"r");
		if ( fp == NULL ) {
			fprintf(stderr,"Could not open file\n");
			return -1;
		}
			
		for( x=9; x>=0; x--) {
			fseek(fp,sizeof(struct person)*x,SEEK_SET);
			fread(&presidents,sizeof(struct person),1,fp);
			printf("President %s was %d years old when inaguaration in %d\n"
			       ,presidents.name
				   ,presidents.inaguaration
				   ,presidents.age);
		}
		

		fclose(fp);

		return 0;
	}
	else {
		printf("%s does not use any arguments\n",argv[0]);
		return -1;
	}
}
