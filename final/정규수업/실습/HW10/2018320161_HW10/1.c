#include <stdio.h>
#include <string.h>

int i;
int j;
int k;
int getstring(char name[], char def, int length);
int getint(int a, int b, char wanted[], char def);

void main() {
	FILE * fpr = fopen("student_file.txt", "wt");

	char name[10];
	char strnumber[9] = {0};
	char strgrade[2] = {0};
	char major[10] = {0};
	char total[31] = { 0 };

	int i, judge = 0;
	for (i = 0; i < 5; i++) {
		do {
			printf("Name Student_Number Grade Major: ");
			judge = getstring(name,' ', 10);
			if (judge == 1)
				judge = getint(10000000, 99999999, strnumber, ' ');
			if (judge == 1) {
				judge = getint(1, 4, strgrade, ' ');
			}
			if (judge == 1) {
				judge = getstring(major, '\n', 10);
			}
		} while (judge == 0);
		fputs(name,fpr);
		fputc(' ',fpr);
		fputs(strnumber, fpr);
		fputc(' ', fpr);
		fputs(strgrade, fpr);
		fputc(' ', fpr);
		fputs(major, fpr);
		fputc('\n', fpr);
		/*for (i = 0; name[i]; i++) {
			total[i] = name[i];
		}
		total[i] = ' ';
		j = i;
		for (i = ++j, j = 0; strnumber[j]; i++, j++) {
			total[i] = strnumber[j];
		}
		total[i] = ' ';
		j = i;
		for (i = ++j, j = 0; strgrade[j]; i++, j++) {
			total[i] = strgrade[j];
		}
		total[i] = ' ';
		j = i;
		for (i = ++j, j = 0; major[j]; i++, j++) {
			total[i] = strgrade[j];
		}
		total[i] = '\n';
		*/
	}
	fclose(fpr);

	FILE * fpw = fopen("student_file.txt", "rt");
	do {
		judge=printf("Insert the student number to find: ");
		getint(10000000, 99999999, strnumber, '\n');
	} while (judge==0);

	judge = 1;
	for (i = 0; i < 5; i++) {
		j = 0; k = 0;
		fgets(total, sizeof(total),fpw);
		while (total[j]!=' ')j++;
		j++;
		while (total[j]!=' ') {
			if (total[j] != strnumber[k]) {
				judge = 0;
				break;
			}
		}
		if (judge == 1) {
			j += 3;
			while (total[j] != '\n') {
				major[k] = total[j];
			}
			major[k + 1] = NULL;
		}
		if (judge == 1)break;
	}
	strnumber[8] = NULL;
	if(judge==1)
	printf("The major of student with ID %s is %s\n", strnumber,major);
	else printf("There is no student with ID %s \n", strnumber);

	fgets(total, sizeof(total), fpw);
	fclose(fpw);
}

int getstring (char name[], char def, int length) {
	int judge;
	
	judge = 0;
	for (i = 0; i <length; i++) {
		name[i] = getchar();
		if (name[i] == def) {
			name[i] = NULL;
			judge = 1;
			break;
		}
	}
	if (judge == 0) {
		while (getchar() != '\n');
		printf("Wrong Input!\n");
	}
	return judge;
}
int getint(int a, int b, char wanted[], char def) {
	int judge = 1;
	char inputint[11];
	int i;
	judge=getstring(inputint,def, 11);
	if (judge == 1) for (i = 0; inputint[i]; i++) if (inputint[i] < '0' || inputint[i] > '9') {
		printf("WRONG INPUT: input must be integer\n\n");
		judge = 0;
		break;
	}
	if (judge == 1) for (i = 0; inputint[i]; i++) {
		wanted[i] = inputint[i];
	}
	return judge;
}

	
