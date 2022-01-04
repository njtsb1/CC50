int
main(void)
{
	// seed do PRNG
	srand(time());

	// choose pseudo-random number among [0, 1023]
	int skittles = rand() % 1024, i = 0;

	printf("Hi! I am a talking bullet machine! Guess how many Skittles I have inside me. Hint: I'm thinking of a number between 0 and 1023. What is it?\nType a number: ");

	do {
		i = GetInt();
		if (i < skittles)
			printf("Haha! I have a lot more Skittles than that. Try again.\nEnter a number: ");
		else if (i > skittles)
			printf("Don't try to be difficult... Guess again.\nEnter a number: ");
		else {
			printf("\nYou're right! Nom nom nom nom.\n");
			break;
		}
	} while (i != skittles);

	return 0;
}
