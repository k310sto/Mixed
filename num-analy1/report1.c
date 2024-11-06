#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(){

	char filename[] = "input.txt";
	FILE *ip = fopen(filename, "r");
	FILE *op = fopen("output.txt", "w");

	char letr;
	while(!feof(ip)){
		letr = fgetc(ip);
		if( isalpha(letr) )
			fprintf(op, "%c", letr);
		else {
			switch(letr){
			case 10 :
				fprintf(op, "\n");
				break;
			case 39 :
				fprintf(op, "'");
				break;
			case 44 :
				fprintf(op, ",");
				break;
			case 46 :
				fprintf(op, ".");
				break;
			default :
				fprintf(op, " ");
				break;
			}
		}
	}
	fclose(ip);
	fclose(op);

return 0;
}
