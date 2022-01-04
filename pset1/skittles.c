//Let's start programming?!
//So one of the best things about Maxwell Dworkin (the Computer Science building of
//Harvard) is the free candy machine in the lounge.
//There are a lot of Skittles (bullets) and M&M's in this
//machine. Want to guess how many Skittles are there?
//Implement, in a file called skittles.c, a program
//which first chooses a random (pseudo) number between 0 and 1023 and then asks you (the human) 
//to guess what that value is.14 The program should keep asking you to guess.
//until you guess the right amount, then he should thank you for playing.
//Where to start? Allow us to give you some pieces of the puzzle.
//To generate a random number, you can use a function called rand.


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
