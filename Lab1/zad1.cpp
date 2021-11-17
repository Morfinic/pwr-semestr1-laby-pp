#include <iostream>

int main(){
	int num1, num2;
	float wynik;
	char wyb;

	std::cout<<"Podaj dwie liczby: "<<std::endl;
	std::cin>>num1>>num2;

	std::cout<<"Wybierz dzialanie:\n + -> dodawanie\n - -> odejmowanie\n * -> mnozenie\n / -> dzielenie\n"<<std::endl;
	std::cin>>wyb;

	switch(wyb){
		case '+':
			wynik = num1 + num2;
			break;
		case '-':
			wynik = num1 - num2;
			break;
		case '*':
			wynik = num1 * num2;
			break;
		case '/':
			if(num2 == 0)
				std::cout<<"Nie mozna dzielic przez 0\n";
			else
				wynik = (float)num1 / (float)num2;
			break;
		default:
			std::cout<<"Zla instrukcja\n";
			break;
	}

	if(wynik)
		std::cout<<"wynik: "<<wynik<<std::endl;

	return 0;
}
