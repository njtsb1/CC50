//Vamos começar a programar?
//Em uma máquina de doces há um monte de Skittles (balas) e M&Ms
//implemente um programa que primeiro escolhe um número aleatório (pseudo) entre 0 e 1023 
//e então pede que você adivinhe qual é esse valor. 
//O programa deve continuar pedindo para você adivinhar
//até que você adivinhe o valor certo, então ele deve lhe agradecer por jogar.
//Por onde começar esse quebra-cabeça?
//Permita-nos sugerir que você comece com este código:
//int
//main(void)
//{
// seed do PRNG
//srand(time(NULL));
// escolhe número pseudo-aleatório entre [0, 1023]
//int skittles = rand() % 1024;
//Deixamosa personalidade da sua máquina de Skittles falante inteiramente para você, 
//mas abaixo se encontra um projeto possível.
//Olá! Eu sou uma máquina de balas falante! Adivinhe quantos Skittles têm
//dentro de mim. Dica: Estou pensando em um número entre 0 e 1023. Qual éele?
//1
//Haha! Tenho muito mais Skittles do que isso. Tente novamente.
//-1
//Não tente ser difícil... Adivinhe novamente.
//1023
//Ok, eles não são tantos assim. Tente novamente.
//??
//Você está certo! Nom nom nom nom.
//Seu programa deve terminar quando o usuário acertar. O design acima responde aos inputs do
//usuário de algumas maneiras diferentes, mas vamos deixar para você decidir o quanto você quer
//variar as respostas dadas pelo seu programa.

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
