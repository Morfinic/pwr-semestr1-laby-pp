#include <iostream>
#include <algorithm>
#include <cmath>

int main(){
	unsigned int a, b, c;

	std::cout<<"Podaj 3 boki trojkata.\n Program sprawdzi czy mozna utworzyc trojkat i jego typ.\n";
	std::cin>>a>>b>>c;

	if(a > c) std::swap(a, c);
	if(b > c) std::swap(b, c);

	if(a + b > c){
		std::cout<<"Mozna utworzyc trojkat o bokach: "<<a<<", "<<b<<", "<<c<<std::endl;
		if(a == b && b == c && a==c) 
			std::cout<<"Trojkat jest rownoboczny\n";
		if(a == b && a!=c && b!=c)
			std::cout<<"Trojkat jest rownoramienny\n";
		if(c>a && c>b && (pow(a,2)+pow(b,2)==pow(c,2)))
			std::cout<<"Trojkat jest prostokatny\n";
	}
	else{
		std::cout<<"Nie mozna utworzyc trojkata.\n";
		return 0;
	}
	return 0;
}
