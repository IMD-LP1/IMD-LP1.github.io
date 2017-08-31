#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <fstream>
#include <string>
using std::string;

int main(int argc, char * argv[]) {

	if(argc != 3) {
		cout << "Informe o nome do arquivo e a palavra a ser buscada " << endl;
		exit(1);
	}
	
	int n{0}, total{0};
	std::ifstream in(argv[1]);
	std::ofstream out("resultado.out");
	string s; 
	string palavra{argv[2]};
	
	
	
	while(!in.eof()) {
		in >> s;
		total++;
		if(s == palavra) {
			n++;
		}
	}
	
	out << "Total de substrings em \"" << argv[1] << "\": " << total << endl;
	out << "Ocorrencias de \"" << argv[2] << "\" em \"" << argv[1] << "\": " << n;

}
