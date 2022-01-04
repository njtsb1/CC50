//Shall we start programming?
//In a candy machine there are a bunch of Skittles (candy) and M&Ms
//Implement a program that first chooses a random (pseudo) number between 0 and 1023
//and then asks you to guess what that value is.
//The program should keep asking you to guess
//until you guess the right amount, then he should thank you for playing.
//Where to start this puzzle?
//Let us suggest that you start with this code:
//int
//main(void)
//{
// PRNG seed
//srand(time(NULL));
// choose pseudo-random number between [0, 1023]
//int skittles = rand() % 1024;
//We leave the personality of your Skittles machine speaking entirely to you,
//but below is a possible project.
//Hi! I am a talking bullet machine! Guess how many Skittles they have
//inside of me. Hint: I'm thinking of a number between 0 and 1023. What is it?
//1
//Haha! I have a lot more Skittles than that. Try again.
//-1
//Don't try to be difficult... Guess again.
//1023
//Okay, they aren't that many. Try again.
//??
//You're right! No no no no no.
//Your program should terminate when the user gets it right. The design above responds to input from the
//user in a few different ways, but we'll leave it up to you to decide how much you want
//vary the answers given by your program.

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
