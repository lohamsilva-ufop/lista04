#include <iostream>
#include <vector>

using namespace std;

int encontraNumero(vector <int> vetor, int numero){
    int meio = vetor.size()/2;

    if(numero>vetor[meio]){
        for (int i=meio; i<vetor.size(); i++){
            if(numero == vetor[i]){
                return i;
            }
        }
    } else{
        for (int i=0; i<meio; i++){
            if(numero == vetor[i]){
                return i;
        }
    }
}
return -1;
}


void mostraImpares(int numero){
    for (int i=1; i<=numero; i++){
        if(i%2 == 1){
            cout << i << endl;
        }
    }
}

int main(){
    int numero;
    vector <int> vetor = {4,5,8,34,45,78,89,96,145};

    //cout << "Digite um numero: " << endl;
    //cin >> numero;

    //mostraImpares(numero);

    cout << "Digite o elemento a ser encontrado: ";
    cin >> numero;

    cout << "O elemento esta na posicao: " << encontraNumero(vetor, numero);



    return 0;
}
