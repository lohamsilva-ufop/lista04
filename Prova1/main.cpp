#include <iostream>
#include <vector>

using namespace std;

float mediaDQ(vector<int> &vetor, int inicio, int fim){
    if(inicio == fim){
        float m = vetor[inicio]/vetor.size();
        return m;
    } else{
        int media = (fim+inicio)/2;
        float s1 =  mediaDQ(vetor, inicio, media);
        float s2 =  mediaDQ(vetor, media+1, fim);
        return s1+s2;
    }
}



float media(vector<int> vetor){
float soma = 0;

    for(int i=0; i<vetor.size(); i++){
        soma = soma + vetor[i];
    }

    return soma/vetor.size();

}

int buscaExaustiva(vector <int> vetor, int chave, int inicio, int fim){
    if (inicio > fim){
        return -1;
    } else{
    int meio = (fim+inicio)/2;
    if(chave == vetor[meio]){
        return meio;
    } else if(chave < vetor[meio]){
        return buscaExaustiva(vetor, chave, inicio, meio);
    } else {
        return buscaExaustiva(vetor, chave, meio+1, fim);
    }
}
}



void buscaExaustivaFB(vector <int> vetor, int chave){
int i;

    for(i=0; i<vetor.size();i++){
        if(chave == vetor[i]){
            cout << "O elemento " << chave <<" foi encontrado na posicao " << i;
            break;

        }
    }

    if (i == vetor.size()){
            cout << "Nao encontrou";
        }
}


int soma(vector<int> vetor, int inicio, int fim){
cout <<  endl;
cout << "Inicio: " << inicio << endl;
cout << "Fim: " << fim << endl;


    if(inicio == fim){
        cout << "Retornou: " << vetor[inicio] << endl;
        cout <<  endl;
        return vetor[inicio];
    } else{
        int media = (inicio+fim)/2;
        cout << "Media: " << media << endl;
        int n1 = soma(vetor, inicio, media);
        cout << "N1: " << n1 << endl;
        int n2 = soma(vetor, media+1, fim);
        cout << "N2: " << n2 << endl;
        int soma = n1 + n2;
        cout << "Soma: " << soma << endl;
        return soma;
    }
}

int multiplica(vector<int> vetor, int inicio, int fim){

    if(inicio == fim){
        return vetor[inicio];
    } else{
        int media = (inicio+fim)/2;
        int n1 = multiplica(vetor, inicio, media);
        int n2 = multiplica(vetor, media+1, fim);
        int produto = n1 * n2;
        return produto;
    }
}

int main()
{
    vector <int> vetor = {1,2,3,4,5,6,7,8};
   // cout << "A soma e: " << soma(vetor, 0, vetor.size()-1) << endl;
   // cout << "A multiplicacao e: " << multiplica(vetor, 0, vetor.size()-1);
   // buscaExaustivaFB(vetor,80);
   //cout << "O elemento chave esta na posicao: " << buscaExaustiva(vetor, 9, 0, 8);
   //cout <<  "A media do vetor e:  " << media(vetor);
   cout <<  "A media do vetor e:  " << mediaDQ(vetor,0,8);
    return 0;
}
