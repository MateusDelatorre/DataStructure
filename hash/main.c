#include <stdlib.h>
#include <stdio.h>
#include "linked.h"
#include "city.h"
#include "dic.h"

void doAddres(Student * student);//Give the interface to register a new address manually
void doGrades(int * grade_count, Student * student);//Give the interface to register a new grade array manually
int studentRegistration(int * grade_count, LinkedList * list);//Give the interface to register a new student manually
void loadStudentsFromFile(LinkedList * list);//Didn't work ;-;
void autoLoad(LinkedList * list);//generet 30 students and adds they to the list. Yes debbug only


//Make the main menu
int main() {

    LinkedList list;
    criarLista(&list);
    int loop = 0;//variavel de controle do loop do programa
    int escolha = 0;//variavel que armazena qual função o usuario escolheu
    int result = 0;
    // int index = 0;
    int grade_count = 0;
    Municipio cidades[5439];
    readDataBase(cidades);
    
    Dictionary * dictionary;
    dictionary = newDictionary(sizeof(Municipio));
    addData(dictionary, &cidades[0], cidades[0].store_key, sizeof(Municipio));
    //printf("sizeof(municipio): %d", sizeof(Municipio));
    //printf("sizeof data: %d", sizeof(dictionary->vector[cidades[1].store_key].data));
    Municipio * teste = dictionary->vector[cidades[0].store_key].data;
    printf("codigo_estado: %d\n", teste->codigo_estado);
    int t = generateKeyConcat(cidades[0].codigo_estado, cidades[0].codigo_municipio);
    printf("t: %d\n", t);
    printf("size: %d\n", dictionary->vector[24307].size);
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
                studentRegistration(&grade_count, &list);//register a student(manually) and add him to the list
                break;//stop the switch statement :0//stop the switch statement :0

            case 2:
                autoLoad(&list);//debbug only
                break;//stop the switch statement :0

            case 3:
                system("cls");//clear the terminal
                printf("Type the student registration number\n");
                scanf("%d", &result);
                fflush(stdin);//cleans the input file
                editStudent(getStudent(&list,result));
                break;//stop the switch statement :0

            case 4:
                system("cls");//clear the terminal
                printf("Type the student registration number\n");
                scanf("%d", &result);
                fflush(stdin);//cleans the input file
                if(removeFromList(&list,result)){
                    printf("Student removed\n");
                }
                break;//stop the switch statement :0

            case 5:
                system("cls");//clear the terminal
                //printf("\e[1;1H\e[2J");//if you are using unix based systems call this line instead
                printf("====Student List====\n");
                printList(&list);
                printf("====List Finished====\n");
                system("PAUSE");
                break;//stop the switch statement :0

            case 6:
                system("cls");//clear the terminal
                printf("====Student List====\n");
                printApprovedsStudents(&list);
                printf("====List Finished====\n");
                system("PAUSE");
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

//Give the interface to register a new student manually
int studentRegistration(int * grade_count, LinkedList * list){
    char name[MAX], sex[SEX_MAX], course[MAX];
    int enroll = 0, age = 0;

    system("cls");//clear the terminal
    //printf("\e[1;1H\e[2J");//if you are using unix based systems call this line instead

    printf("====Student Registration====\n");
    
    printf("1 - Enrollment number:\n");
    scanf("%d", &enroll);
    fflush(stdin);//cleans the input file
    printf("2 - Name:\n");
    scanf("%[^\n]", name);
    fflush(stdin);//cleans the input file
    printf("3 - Age:\n");
    scanf("%d", &age);
    fflush(stdin);//cleans the input file
    printf("4 - Sex:\n");
    scanf("%[^\n]", sex);
    fflush(stdin);//cleans the input file
    printf("5 - Course:\n");
    scanf("%[^\n]", course);
    fflush(stdin);//cleans the input file

    Student * student = newStudent(enroll, name, age, sex, course);

    //printf("This student has grades?");
    //check

    doGrades(grade_count, student);
    doAddres(student);
    addSort(list, student);
    return 1;
}

//Give the interface to register a new grade array manually
void doGrades(int * grade_count, Student * student){
    if (*grade_count == 0)
    {
        printf("This class does not have a defined grade amount\n");
        printf("Please inform that below. Max is seven\n");
        scanf("%d", grade_count);
    }
    setGradeCount(student, *grade_count);
    for (int i = 0; i < *grade_count; i++)
    {
        double grade = 0, weight = 0;
        printf("%d - Insert the %d° grade:\n", (i*2)+6, i+1);
        scanf("%lf", &grade);
        fflush(stdin);//cleans the input file
        printf("%d - Insert the grade weight:\n", (i*2)+ 7);
        scanf("%lf", &weight);
        fflush(stdin);//cleans the input file
        addNota(student, grade, weight, i);
    }
}

//Give the interface to register a new address manually
void doAddres(Student * student){
    char streat_name[MAX]; int number;char CEP[MAX];

    printf("===Student ADDRES===\n");
    printf("1 - Insert the streat name:");
    scanf("%[^\n]", streat_name);
    fflush(stdin);//cleans the input file

    printf("1 - Insert the number:");
    scanf("%d", &number);
    fflush(stdin);//cleans the input file

    printf("1 - Insert the CEP:");
    scanf("%[^\n]", CEP);
    fflush(stdin);//cleans the input file

    setAddres(student, streat_name, number, CEP);
}

//generet 30 students and adds they to the list. Yes debbug only
void autoLoad(LinkedList * list){
    int enroll = 0;
    
    for (int i = 0; i < 30; i++, enroll++)
    {
        Student * student = newStudent(enroll, "aluno", 22, "sex", "course");

        setGradeCount(student, 3);
        for (int i = 0; i < 3; i++)
        {
            double grade = 5, weight = 1;
            addNota(student, grade, weight, i);
        }
        setAddres(student, "streat_name", 345, "279236");
        addSort(list, student);
    }
}

void loadStudentsFromFile(LinkedList* list){
    Student* current;
    FILE * file;
    file = fopen("aluno.bin", "rb");
    if (!file){
        return;
    }

    if(!feof(file) && !ferror(file)){
		while(fread(current, sizeof(Student), 1, file)==1){
            fread(current->student_address, sizeof(Address), 1, file);
            for (int i = 0; i < current->grade_count; i++)
            {
                fread(current->notas[i], sizeof(Notas), 1, file);
            }
            printStudent(current);
			//append(list, current);
			if(feof(file)) break;
		}
	}
    fclose(file);
    //Student * student = newStudent(enroll, name, age, sex, course);
}

