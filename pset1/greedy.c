// A customer goes to the supermarket and buys a product worth R$11.59,
// he goes to the cash register and pays R$12.00 with two notes, respectively R$10 and R$2, and needs to receive R$0.41 in change.
// The cashier performs the operation on the computer and looks in his drawer for coins of 50, 25, 10, 5 and 1 cents.
// To solve this "problem" requires one or more withdrawals of one or more different types of currency.
// Think of a "greedy" cashier, someone who wants to settle, with each withdrawal of a single coin,
// as much of this problem as possible, the best first step (the best choice
// immediate, or local) is the withdrawal of a 25¢ coin (it's "better" as this withdrawal leaves us
// closer to 0¢ than any other single-coin withdrawal). Note that this first
// step reduces the 41¢ problem to a 16¢ problem, since 41-25 = 16. That is, the second is
// a similar but minor problem. Needless to say, another 25¢ withdrawal would be
// very big (assuming the cashier prefers not to lose money), and so our gluttonous cashier
// would withdraw a 10¢ coin, leaving you with a 6¢ problem. At that point, greed calls for a
// takedown of 5¢ followed by a takedown of 1¢, and now the problem is solved. the customer receives
// one 25¢ coin, one 10¢ coin, one 5¢ coin, and one 1¢ coin: four coins total.
// As long as a cashier has a sufficient number of each coin, this approach will withdraw, in the
// end, as few coins as possible.
// How small is this number of coins? Well, tell us.
// Develop a program that first asks the user how much change he wants to receive and,
// then answer the minimum number of coins this change can be given with.
// Using the supermarket customer example,
// consider the representation below of how your program should behave:
// message: Hello. How much change do you owe?
// change amount in BRL: 0.41
// number of coins: 4
// Your code will likely have some kind of loop.
// If, when testing your program, you find yourself looping forever, remember that you
// can always force your program to die (ie short circuit its execution),
// pressing ctrl-c (maybe many times in a row).
// We leave it up to you to determine how to compile, run and debug this program!


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
