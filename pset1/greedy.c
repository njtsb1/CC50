int
main(void)
{
	float a = 0.25, b = 0.10, c = 0.05, d = 0.01, f = 0.00;
	int a2 = 0, b2 = 0, c2 = 0, d2 = 0, coins = 0, f2 = (int)f;

	do {
		printf("How much change do you want to receive? ");
		f = GetFloat();
	} while (f < 0);

	if (f == 0)
		printf("Thank you come back often!\nF2=%d.\n", f2);
	else {
		while (f >= a)
			f -= a, coins++, a2++;
		while (f >= b)
			f -= b, coins++, b2++;
		while (f >= c)
			f -= c, coins++, c2++;
		while (f >= d)
			f -= d, coins++, d2++;
		printf("This change requires %d coins. 25=%d, 10=%d, 5=%d, 1=%d, f=%f, F2=%d.\n", coins, a2, b2, c2, d2, f, f2);
	}

	return 0;
}
