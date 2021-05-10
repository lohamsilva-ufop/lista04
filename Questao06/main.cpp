//algoritmo implementado com base no link: https://blog.pantuza.com/artigos/o-algoritmo-de-ordenacao-quicksort
#include <iostream>
#include <vector>

using namespace std;

//função que imprime o vetor
void imprimeVetor(vector<int> vetor){
    cout << "{";
    for(int i=0; i<vetor.size(); i++){
        cout << vetor[i] << ",";
    }
    cout << "}";
}

int particiona(vector<int> &vetor, int inicio, int fim){
    int pivo = vetor[fim];
    int marcador = inicio;
    int auxiliar;

    /* Ao iterar, da esquerda para direita, em toda a sequência, toda vez
     que encontrarmos um elemento cujo valor seja menor do que nosso pivô,
     iremos colocá-lo à esquerda do pivô.*/

     for(int i=inicio; i<fim; i++){
        if(vetor[i] <= pivo){ //se o elemento da posicao atual e menor ou igual ao pivô
            auxiliar = vetor[i]; //troca de posicao com o pivo
            vetor[i] = vetor[marcador];
            vetor[marcador] = auxiliar;
            marcador = marcador+1; //marcador passa a ser a proxima posição
        }
     }
     //depois de feitas as trocas, coloca o pivô na sua posição correta.
            auxiliar = vetor[marcador];
            vetor[marcador] = vetor[fim];
            vetor[fim] = auxiliar;

    return marcador;
}

//funcao recursiva que termina de ordenar o vetor, ate que inicio seja menor que o fim
void quicksort(vector<int> &vetor, int inicio, int fim){
    if (inicio < fim){

        int pivo = particiona(vetor, inicio, fim); //recebe a posicao do pivo
        quicksort(vetor, inicio, pivo-1); //divide o vetor e analisa
        quicksort(vetor, pivo+1, fim);
    }
}

int main(){

    //declara e insere valores no vetor
	vector <int> vetor = {5,1,4,2,3,80,-1,70};
	//imprime o vetor desornado
	cout << "Vetor desornado: " << endl;
	imprimeVetor(vetor);
	cout << endl;
	//chama a funcao quicksort
	quicksort(vetor, 0, vetor.size()-1);
	//imprime o vetor após ordenar
	cout << "Vetor ordenado: " << endl;
	imprimeVetor(vetor);

	return 0;
}
