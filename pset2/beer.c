int
main(void)
{
	int i = 10;
	while (i > 0) {
		printf("%d beer bottles on the wall, drink one, throw it in the trash, ", i);
		i--;
		if (i == 1) {
			printf("%d bottle on the wall...\n", i);
			sleep(1);
			printf("1 beer bottle on the wall, drink one, throw it in the trash, no bottle on the wall...\n");
			return 0;
		}
		printf("%d bottles on the wall...\n", i);
		sleep(1);
	}
}
