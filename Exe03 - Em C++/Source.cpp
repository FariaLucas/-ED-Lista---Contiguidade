#include<iostream>
#include <string>
#include <conio.h>
#define tam 10

struct Cadastro {
	std::string nome;
	std::string score;
	char Date_gegister[8];
};

int main() {
	bool ComNome = false;
	bool fim = true;
	bool TudoPrenchido = false;
	char ch;
	int i;
	int	a = 0;
	int EstadoDeJogo = 0;
	Cadastro jogadores[tam];

	for (int j = 0; j < 10; j++) {
		jogadores[j].nome = "0";
		jogadores[j].score = "0";
	}

	while (fim) {
		switch (EstadoDeJogo) {
		case 0:
			system("cls");
			std::cout << "Quais das Tarefas a baixo voce gostaria de fazer?" << std::endl;
			std::cout << "1. Cadastro" << std::endl;
			std::cout << "2. Pesquisa" << std::endl;
			std::cout << "3. Excluir Usuario" << std::endl;
			std::cout << "4. Mostrar Lista de Usuarios" << std::endl;
			ch = _getche();
			switch (ch)
			{
			case 49:
				i = 0;
				ComNome = false;
				EstadoDeJogo = 1;
				break;
			case 50: EstadoDeJogo = 2;
				break;
			case 51: EstadoDeJogo = 3;
				break;
			case 52: EstadoDeJogo = 4;
				break;
			}
			break;
		case 1:

			while (ch != 27) {
				if (a > 9) {
					system("cls");
					std::cout << "" << std::endl;
					std::cout << "Os cadastros ja chegaram no limite, se quiser adicionar mais usuarios por favor exclua algum" << std::endl;
					std::cout << "" << std::endl;
					ComNome = true;
					ch = _getche();
				}
				system("cls");
				std::cout << "Qual seu nome?" << std::endl;

				for (int j = 0; j < 10; j++)
					if (!ComNome)
						if (jogadores[j].nome == "0") {
							std::cin >> jogadores[j].nome;
							ComNome = true;
							a++;
						}
				ComNome = false;

				std::cout << "Qual seu score?" << std::endl;

				for (int j = 0; j < 10; j++)
					if (!ComNome)
						if (jogadores[j].score == "0") {
							std::cin >> jogadores[j].score;
							ComNome = true;
						}
				break;
			}
			EstadoDeJogo = 0;
			break;

		case 2:
			system("cls");
			while (ch != 27) {
				int indice;
				std::cout << "Qual indice voce quer pesquisar? (de 0 a 9) " << std::endl;
				std::cin >> indice;
				std::cout << jogadores[indice].nome;
				ch = _getche();
			}
			EstadoDeJogo = 0;

			break;
		case 3:
			system("cls");
			int indice;
			std::cout << "Qual indice voce quer EXCLUIR? (de 0 a 9) " << std::endl;
			std::cin >> indice;
			while (indice > 9) {
				std::cout << "Indice nao existe, por favor ensira um numero entre 0 e 9 " << std::endl;
				std::cin >> indice;
			}//
			jogadores[indice].nome = "0";
			jogadores[indice].score = "0";
			a--;

			for (int j = indice; j < 10; j++) {
				if (jogadores[j].nome == "0" && j + 1<10) {
					jogadores[j].nome = jogadores[j + 1].nome;
					jogadores[j + 1].nome = "0";
					jogadores[j].score = jogadores[j + 1].score;
					jogadores[j + 1].score = "0";
				}
			}
			EstadoDeJogo = 0;

			break;
		case 4:
			system("cls");
			std::cout << "ID    " << "USUARIO         " << "SCORE   " << std::endl;
			std::cout << "" << std::endl;
			for (int j = 0; j < 10; j++)
				std::cout <<  j << "     " << jogadores[j].nome << "                 " << jogadores[j].score << std::endl;
			ch = _getche();
			if (ch == 27)
				EstadoDeJogo = 0;
			break;
		}
	}
	return 0;
}