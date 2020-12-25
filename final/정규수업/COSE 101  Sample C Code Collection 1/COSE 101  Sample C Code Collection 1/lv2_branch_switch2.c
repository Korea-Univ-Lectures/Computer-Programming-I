#include <stdio.h>

int main()
{
	int menu;
	
	printf("[ Menu ]\n");
	printf("1) My Phone\n");
	printf("2) Phone List\n");
	printf("3) e-Diary\n");
	printf("4) e-Mail\n");
	printf("%d", &menu);
	
	switch (menu)
	{
		case 1:
			printf("Configure your phone...");
			break;
		case 2:
			printf("Reg. & Search others's phone number...");
			break;
		case 3:
			printf("Check your schedule...");
			break;
		case 4:
			printf("Check your e-mail...");
			break;
		default:
			printf("Unknown Number...");
	}
	
	return 0;
}