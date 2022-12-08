#include <stdlib.h>
#include <stdio.h>
#include "city.h"
#include "tHash.h"
#include "hash.h"

#define MAX 5439

void addMunicipio(TreeHashTable * tree_hash_table, Municipio * cidades){
    GenericData * data = newGenericData(sizeof(Municipio));
    data->data = cidades;
    data->size = sizeof(Municipio);
    //printf("main.c:11\n");
    addDataToTreeHashTable(tree_hash_table, data, cidades->store_key, compare);
}

void testeDictionary(Municipio * cidades){
    // Dictionary * dictionary;
    // dictionary = newDictionary(sizeof(Municipio));
    // addData(dictionary, &cidades[0], cidades[0].store_key, sizeof(Municipio));
    // printf("sizeof data: %d", sizeof(dictionary->vector[cidades[1].store_key].data));
    // Municipio * teste = dictionary->vector[cidades[0].store_key].data;
    // printf("codigo_estado: %d\n", teste->codigo_estado);
    // printf("size: %d\n", dictionary->vector[24307].size);
}

void testeHashTable(Municipio * cidades){
    HashTable * hash_table;
    hash_table = newHashTable(sizeof(Municipio));
    for (int i = 0; i < 100; i++){
        addData(hash_table, &cidades[i], cidades[i].store_key, sizeof(Municipio));
    }

    Municipio * teste = getData(hash_table, cidades[90].store_key);
    printf("%s\n", teste->nome);
}

void testeTreeHashTable(Municipio * cidades){
    TreeHashTable * tree_hash_table;
    tree_hash_table = newTreeHashTable(sizeof(Municipio));
    //printf("main.c:37\n");
    // addData(tree_hash_table->hash_table, &cidades[0], cidades[0].store_key, sizeof(Municipio));
    // addData(tree_hash_table->hash_table, &cidades[1], cidades[1].store_key, sizeof(Municipio));
    // Municipio * teste = getData(tree_hash_table->hash_table, cidades[0].store_key);
    // printf("%s\n", teste->nome);
    for (int i = 0; i < MAX; i++){
        cidades[i].store_key = simpleMod(cidades[i].codigo_municipio, 500);
    }
    // cidades[0].store_key = 100;
    // addMunicipio(tree_hash_table, &cidades[0]);
    for (int i = 0; i < MAX; i++){
        addMunicipio(tree_hash_table, &cidades[i]);
    }
    Municipio * cidade = NULL;
    cidade = (Municipio *) getDataFromTreeHashTable(tree_hash_table, cidades[2].store_key, cidades[2].nome, compareString);
    if (cidade){
        printf("nome: %s\n", cidade->nome);
    }
}

//Make the main menu
int main() {
    int loop = 0;//variavel de controle do loop do programa
    int escolha = 0;//variavel que armazena qual função o usuario escolheu
    int result = 0;
    // int index = 0;
    int grade_count = 0;
    Municipio cidades[5439];
    readDataBase(cidades);

    //testeHashTable(cidades);
    testeTreeHashTable(cidades);
    //testeTree(cidades);
    Municipio * teste;
    //printf("sizeof(municipio): %d", sizeof(Municipio));
    //( (Municipio *)e->data)->vertex

    while(loop){
        // char name[MAX] = "";
        //Menu para escolha de funções do programa
        //system("cls");//clear the terminal
        
        printf("====MENU====\n");//Make the menu a little bit more beautiful
        printf("1. Cadastrar um aluno\n");//Use whatever means necessary to register a new student
        printf("2. Auto load students\n");//for debbug only
        printf("3. Alterar um cadastro de um aluno\n");//Use whatever means necessary to modify a student registration
        printf("4. Remover um aluno\n");//Use whatever means necessary to remove a student from the list
        printf("5. Listar todos os alunos\n");//Use whatever means necessary to list all students
        printf("6. Listar alunos passados\n");//Use whatever means necessary to list all approved students
        printf("7. Sair\n");//set the loop variable to 0 making the program stop
        
        scanf("%d", &escolha);//read the keyboard
        fflush(stdin);//cleans the input file//cleans the input file
        //switch case statement, to chose what to do
        switch(escolha){
            case 1:
                
                break;//stop the switch statement :0//stop the switch statement :0

            case 2:
                
                break;//stop the switch statement :0

            case 3:
                
                break;//stop the switch statement :0

            case 4:
                
                break;//stop the switch statement :0

            case 5:
                
                break;//stop the switch statement :0

            case 6:
                
                break;//stop the switch statement :0
            
            case 7:
                loop = 0;
                break;//stop the switch statement :0

            default:
                printf("numero invalido tente novamente\n");
        }
    }
    return 0;
}