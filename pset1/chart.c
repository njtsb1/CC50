int
main(void)
{
	int mw, mm, wm, ww;

	do {
		printf("\nHow many men looked for women? ");
		mw = GetInt();
	} while (mw < 0);

	do {
		printf("\nHow many men looked for men? ");
		mm = GetInt();
	} while (mm < 0);

	do {
		printf("\nHow many women looked for men? ");
		wm = GetInt();
	} while (wm < 0);

	do {
		printf("\nHow many women looked for women? ");
		ww = GetInt();
	} while (ww < 0);

	int total = mw + mm + wm + ww;
	printf("\nTotal: %d. Search chart:\n", total);

	int tether = 80*mw/total, i = 100*mw/total;
	printf("\nM searching W - %d%%\n", i);
	for (int i = 0; i < tether; i++)
		printf("#");

	tether = 80*mm/total, i = 100*mm/total;
	printf("\nM searching M - %d%%\n", i);
	for (int i = 0; i < tether; i++)
		printf("#");

	tether = 80*wm/total, i = 100*wm/total;
	printf("\nW searching M - %d%%\n", i);
	for (int i = 0; i < tether; i++)
		printf("#");

	tether = 80*ww/total, i = 100*ww/total;
	printf("\nW searching W - %d%%\n", i);
	for (int i = 0; i < tether; i++)
		printf("#");

	printf("\n\n");
	return 0;
}
