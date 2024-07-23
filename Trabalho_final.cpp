#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

//Struct que vai conter os dados utilizados para realizar as contas e criar o novo arquivo
struct flor{
    float largura;
    float altura;
    string especie_flor;
    string grupo;
};

//Struct das flores selecionadas como representantes
struct flor_representantes{
    float largura;
    float altura;
    string especie_flor;
};

//Declaração dos protótipos das funções utilizadas no código
void ler_arq(flor* vet_flor, ifstream& leituraArq);

void escolher_k(int k, flor* vet_flor, flor_representantes* vet_representantes, int tamanho);

void distancia_euclidiana( flor* vet_flor, flor_representantes* vet_representantes, int k, int tamanho);

void atualizar_representantes_grupo(flor* vet_flor, flor_representantes* vet_representantes, int k, int tamanho);

void repetir_funcoes(int quant_vezes, flor* vet_flor, flor_representantes* vet_representantes, int k, int tamanho);

void escrever_resultados(flor* vet_flor, int tamanho);

//Início do int main
int main(){
    ifstream leituraArq("iris_petalas.csv", ios::in);
    float largura;
    float altura;
    string especie;

    int k = 0;
    int tamanho = 150;
    flor* vet_flor = new flor[tamanho];

    cout << "----------------------------------------------------------" << endl;

    cout << "Primeiro passo - ler arquivo: ";
    ler_arq(vet_flor, leituraArq);
    cout << "Passo concluido!" << endl;
    
    cout << "----------------------------------------------------------" << endl;

    cout << "Segundo passo - escolher representates: ";
    cin >> k;
    flor_representantes* vet_representantes = new flor_representantes[k];
    escolher_k(k, vet_flor, vet_representantes, tamanho);
    cout << "Passo concluido!" << endl;

    cout << "----------------------------------------------------------" << endl;

    cout << "Terceiro passo - fazer calculo da distancia euclidiana: " << endl;
    distancia_euclidiana(vet_flor, vet_representantes, k, tamanho);
    cout << "Passo concluido!" << endl;

    cout << "----------------------------------------------------------" << endl;

    cout << "Quarto passo - fazer a media das representantes de cada grupo: ";
    atualizar_representantes_grupo(vet_flor, vet_representantes, k, tamanho);
    cout << "Passo concluido!" << endl;

    cout << "----------------------------------------------------------" << endl;

    int quant_vezes = 0;
    cout << "Quinto passo - deseja repetir os quantas vezes: ";
    cin >> quant_vezes;
    repetir_funcoes(quant_vezes, vet_flor, vet_representantes, k, tamanho);
    cout << "Passo concluido!" << endl;

    cout << "----------------------------------------------------------" << endl;

    cout << "Ultimo passo - escrevendo resultados: ";
    escrever_resultados(vet_flor, tamanho);
    cout << "Passo concluido!" << endl;

    cout << "----------------------------------------------------------" << endl;

    delete[] vet_flor;
    delete[] vet_representantes;
    return 0;
}
//Final do int main

//Função de leitura do arquivo "iris_petalas.csv" e alocação das structs flores no vetor de struct
void ler_arq(flor* vet_flor, ifstream& leituraArq){
    string linha;
    int i = 0;
    int flag_first_linha = 0;
    string first_linha;

    while (getline(leituraArq, linha))
    {   
        string temp_largura;
        string temp_altura;
        string temp_especie;
        int flag = 0;
        int temp = 0;

        if (flag_first_linha == 0)
        {
            first_linha = linha;
            flag_first_linha += 1;
        } else {
            for (int i = 0; i <= linha.length(); i++)
            {                   
                
                if (linha[i] == ',' && flag == 0)
                { 
                    temp_largura = linha.substr(temp, i-temp);
                    temp = i + 1;
                    flag++;
                }
                if (linha[i] == ',')
                {   
                    temp_altura = linha.substr(temp, i-temp);
                    temp = i + 1;
                }
                if (i == linha.length())
                {
                    temp_especie = linha.substr(temp, i-temp);
                    temp = i + 1;
                }
            }
            (*(vet_flor+i)).largura = stof(temp_largura);
            (*(vet_flor+i)).altura = stof(temp_altura);
            (*(vet_flor+i)).especie_flor = temp_especie;
            i++;
        }
    }
    leituraArq.close();
}

//Função para decidir o número k de representantes e selecionar as flores aleatoriamente 
void escolher_k(int k, flor* vet_flor, flor_representantes* vet_representantes, int tamanho){
    srand(time(0));
    int aleatorio = 0;
    for (int i = 0; i < k; i++)
    {
        aleatorio = rand()%150;
        vet_representantes[i].largura = vet_flor[aleatorio].largura;
        vet_representantes[i].altura = vet_flor[aleatorio].altura;
        vet_representantes[i].especie_flor = vet_flor[aleatorio].especie_flor;
    }

    for (int i = 0; i < k; i++)
    {   
        cout <<vet_representantes[i].largura <<' '<< vet_representantes[i].altura<<' '<< vet_representantes[i].especie_flor << endl;
    }
}

//Função do cálculo da distância Euclidiana entre as flores representantes e o resto
void distancia_euclidiana( flor* vet_flor, flor_representantes* vet_representantes, int k, int tamanho){
    float* temp_result = new float[k];      
    for (int i = 0; i < tamanho; i++)
    {
        for (int j = 0; j < k; j++)
        {
            temp_result[j] = sqrt(pow((vet_flor[i].largura - vet_representantes[j].largura),2) + pow((vet_flor[i].altura - vet_representantes[j].altura),2));
        }  
        
        float menor_distancia = temp_result[0];
        int grupo = 1;

        for(int j = 0; j < k; j++)
        {   
            if (temp_result[j] < menor_distancia)
            {
                menor_distancia = temp_result[j];
                grupo = j + 1;
            }
        }
        vet_flor[i].grupo = "Grupo " + to_string(grupo);
    } 
    delete[] temp_result;
}

//Função para calcular a nova média das flores representantes após definir o grupo de cada flor
void atualizar_representantes_grupo(flor* vet_flor, flor_representantes* vet_representantes, int k, int tamanho){
    for(int i = 0; i < k; i++)
    {   
    float media_result_largura = 0;
    float media_result_altura = 0;
    int indice = 0;
    int grupo = 0;
        grupo = i + 1;
        for (int j = 0; j < tamanho; j++)
        {   
            if (vet_flor[j].grupo == "Grupo " + to_string(grupo))
            {
                media_result_largura += vet_flor[j].largura;
                media_result_altura += vet_flor[j].altura;
                indice += 1;
            }
        }
        media_result_largura = media_result_largura/indice;
        media_result_altura = media_result_altura/indice;
        vet_representantes[i].largura = media_result_largura;
        vet_representantes[i].altura = media_result_altura;
    }

}

//Função que chama novamente as funções de cálculo de distância Euclidiana e a de atualizar o ponto médio das representantes
void repetir_funcoes(int quant_vezes, flor* vet_flor, flor_representantes* vet_representantes, int k, int tamanho){
    for (int i = 0; i < quant_vezes; i++)
    {
        distancia_euclidiana(vet_flor, vet_representantes, k, tamanho);
        atualizar_representantes_grupo(vet_flor, vet_representantes, k, tamanho);
    }
}

//Função que cria um novo arquivo com os resultados obtidos pelo código
void escrever_resultados(flor* vet_flor, int tamanho){
    ofstream arqFinal_resultados("Resultados.dat" , ios::out);
    float largura;
    float altura;
    string especie;
    string grupo;

    int flag = 0;
    int indice = 0;
    for(int i = 0; i < tamanho; i++)
    {       
        arqFinal_resultados << vet_flor[i].largura <<','<< vet_flor[i].altura <<','<< vet_flor[i].especie_flor <<','<< vet_flor[i].grupo << endl;
    }

    arqFinal_resultados.close();
}
