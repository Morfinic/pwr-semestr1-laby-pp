#include <iostream>
#include <cmath>

int main(){
	int a, b, c;

	std::cout<<"Program liczy miejsca zerowe funkcji kwadrataowej f(x)=ax^2 + bx + c.\nPodaj a: \n";
	std::cin>>a;

	if(a == 0) {std::cout<<"To nie jest funkcja kwadratowa.\n"; return 0;}
	else{
		std::cout<<"Podaj b: \n";
		std::cin>>b;
		std::cout<<"Podaj c: \n";
		std::cin>>c;
		
		std::cout<<"Funkcja: ";
		
		if(a == 1) std::cout<<"x^2";
		else std::cout<<a<<"x^2";

		if(b == 0){}
		else if(b == 1) std::cout<<"x";
		else if(b > 0) std::cout<<"+"<<b<<"x";
		else std::cout<<b<<"x";

		if(c == 0){}
		else if(c > 0) std::cout<<"+"<<c;
		else std::cout<<c;
		std::cout<<"\n";

		float delta = pow(b,2) - 4*a*c;
	       	if(delta < 0) std::cout<<"Nie ma miejsc zerowych\n";
		else if(delta == 0){
			float x = -b/(2*a);
			std::cout<<"Miejsce zerowe: "<<x<<std::endl;
		}
		else if(delta > 0){
			float x1, x2;
			x1 = (-b + sqrt(delta))/2*a;
			x2 = (-b - sqrt(delta))/2*a;
			std::cout<<"Miejsca zerowe: "<<x1<<", "<<x2<<std::endl;
		}
	}	

	return 0;
}
