#include <iostream>
#include <vector>

using namespace std;

void imprimeVetor(vector <int> v){
    cout << "{";
    for(int i=0; i< v.size(); i++){
        cout << v[i] << ",";
    }
    cout << "}" << endl;
}

void mergeSort(vector <int> &vetor, int inicio, int meio, int fim){

    int elemento;
    vector <int> intermediario;
    int i, j;
    i = inicio;
    j = meio+1;

    while (i<= meio && j <= fim){
        if(vetor[i] < vetor[j]){
            elemento = vetor[i];
            intermediario.push_back(elemento);
            i++;
        } else {
            elemento = vetor[j];
            intermediario.push_back(elemento);
            j++;
        }
    }

    while (i<= meio){
            elemento = vetor[i];
            intermediario.push_back(elemento);
            i++;
    }

    while (j<= fim){
            elemento = vetor[j];
            intermediario.push_back(elemento);
            j++;
    }


   for (int i=inicio; i<intermediario.size(); i++){
        vetor[i] = intermediario[i];
    }
}

void dividir(vector <int> &vetor, int inicio, int fim){


    if (inicio < fim){
        int meio;
        meio = (inicio+fim)/2;
        dividir(vetor, inicio, meio);
        dividir(vetor, meio+1, fim);
        mergeSort(vetor,inicio, meio, fim);
    }


}


int main()
{
    int quantidade;
    int elemento;

    cout << "Digite a quantidade de elementos do vetor: ";
    cin >> quantidade;

    vector <int> vetor;

    for (int i=0; i< quantidade; i++){
        cout << "Insira o "<< i+1 << " elemento do vetor: ";
        cin >> elemento;
        vetor.push_back(elemento);
    }

    cout << "Vetor desordenado: " << endl;
    imprimeVetor(vetor);

    cout << "Vetor ordenado:" << endl;
    dividir(vetor, 0, vetor.size()-1);
    imprimeVetor(vetor);

    return 0;
}
