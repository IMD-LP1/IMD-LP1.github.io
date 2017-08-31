#include <iostream>
#include <iomanip>
using std::cout;
using std::endl;
using std::cin;


struct Matriz {
	int linhas, colunas;
	int** elementos;
};

void alocar_matriz(Matriz& m, int l, int c) {
	
	m.linhas = l;
	m.colunas = c;
	
	int i;
	
	m.elementos = new int*[l];
	for(i = 0; i < m.linhas; i++ ) {
		m.elementos[i] = new int[c];
	}
}

void libera_matriz(Matriz& m) {
	
	int i;
	for(i = 0; i < m.linhas; i++) {
		delete[] m.elementos[i];
	}
	
	delete[] m.elementos;
}

void ler_matriz(Matriz& m) {
	
	int i, j;
	
	for(i = 0; i < m.linhas; i++) {
		for(j = 0; j < m.colunas; j++) {
			cout << "M[" << i << "][" << j << "]:";
			cin >> m.elementos[i][j];
		}
	}
}

void escrever_matriz(Matriz m) {
	int i, j;
	
	for(i = 0; i < m.linhas; i++) {
		for(j = 0; j < m.colunas; j++) {
			cout << m.elementos[i][j] << " ";
		}
		cout << endl;
	}
}

void metriz2vetor(Matriz m, Matriz& v) {
	
	int i, j;
	
	for(i = 0; i < m.linhas; i++) {
		for(j = 0; j < m.colunas; j++) {
			cout << m.elementos[i][j] << endl;
			v.elementos[0][v.colunas + j] = m.elementos[i][j];
		}
		cout << endl;
	}	
}

int main() {

	int l, c;
	
	Matriz m, v;
	
	cout << "Informe o numero de linhas da matriz M: ";
	cin >> l;
	cout << "Informe o numero de colunas da matriz M: ";
	cin >> c;
	
	alocar_matriz(m, l, c);
	
	cout << "Informe os elementos da matriz M:" << endl;
	ler_matriz(m);
	
	cout << "Matriz informada:" << endl;
	escrever_matriz(m);
	
	cout << "Vetor produzido:" << endl;
	alocar_matriz(v, 1, c * l);
	escrever_matriz(v);
		
	
}
