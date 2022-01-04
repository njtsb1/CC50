// recover.c	CC50 Pset5	retrieve images JPG. njtsb1.

#include <stdint.h>
#include <stdio.h>

uint8_t checkJPG(uint8_t *buffer);

int
main(void)
{
	// Welcome
	printf("\033[1;30;47mPOWERED BY njtsb1\033[0m\nStarting operation.\n");

	// Open file
	FILE *fpr = fopen("card.raw", "r");
	if (fpr == NULL) {
		printf("\033[31mError opening file.\033[0m\n");
		return 1;
	}

	//Variables
	uint8_t buffer[512];
	int count = 0;
	char name[8];
	FILE *exit;

	// Loop that copies
	while (fread(&buffer, 512, 1, fpr) == 1)
		while (checkJPG(buffer)) {
			count++;
			sprintf(name, "%03d.jpg", count);
			exit = fopen(name, "w");
			fwrite(&buffer, 512, 1, exit);
			// End of file or other signature, for
			while (fread(&buffer, 512, 1, fpr) == 1 && !checkJPG(buffer))
				fwrite(&buffer, 512, 1, exit);
		}

	// That's all, folks :)
	count < 2 ? printf("%d found.\n", count) : printf("Encontrados! %d.\n", count);
	fclose(fpr);
	fclose(exit);
	printf("That's all, folks .\n");
	return 0;
}

// Check signature JPG
uint8_t
checkJPG(uint8_t *buffer)
{
	if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] == 0xe0 || buffer[3] == 0xe1))
		return 1;
	else
		return 0;
}
