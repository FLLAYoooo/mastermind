#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

void affiche(int *tab){
    for(int i=0;i<4;i++){
        int nombre = tab[i];
        if(nombre == 1){
            printf("%c", 'P');
        }
        if(nombre == 2){
            printf("%c", 'B');
        }
        if(nombre == 3){
            printf("%c", 'M');
        }
        if(nombre == 4){
            printf("%c", 'Y');
        }
        if(nombre == 5){
            printf("%c", 'O');
        }
        if(nombre == 6){
            printf("%c", 'G');
        }
    }
}

void responseGen(int *tab) {
    int index = 0;
    while (index < 4) {
        int value = rand()%7;
        if (value != 0) {
            tab[index] = value;
            ++index;
        }
    }
}

int convert(char letter) {
    if (letter == 'P') {
        return 1;
    } else if (letter == 'B') {
        return 2;
    } else if (letter == 'M') {
        return 3;
    } else if (letter == 'Y') {
        return 4;
    } else if (letter == 'O') {
        return 5;
    } else if (letter == 'G') {
        return 6;
    }
}

void saisie(char *array) {
    printf("Rentrez vos lettres svp :\n");
    for (int i = 0; i < 4; i++) {
        printf("%d > ", i + 1);
        scanf("%s", &array[i]);
    }
}

void validator(int *solution, char *user, int *result) {
    for (int i = 0; i < 4; i++) {
        bool contains = false;
        for (int j = 0; j < 4; j++) {
            if (solution[j] == user[i]) {
                contains = true;
            }
        }
        result[i] = 0;
        if (contains) {
            result[i] = 2;
            if (solution[i] == user[i]) {
                result[i] = 1;
            }
        }
    }
}

void rengementator(int liste[4]) {
    srand(time(NULL)); 
    for (int i = 0; i < 4; i++) {
        int j = rand() % 4;
        int temp = liste[i];
        liste[i] = liste[j];
        liste[j] = temp;
    }
}

int main() {
    srand(time(NULL));
    int solution[4];
    char user[4];
    int result[4];
    responseGen(solution);
    bool win = false;
    int coups = 0;
    while(win == false && coups <= 10){
        saisie(user);
        for(int i=0;i<4;i++){
            int chiffre = convert(user[i]);
            user[i] = chiffre;
        }
        validator(solution, user, result);
        rengementator(result);
        for(int j=0;j<4;j++){
            if(result[j] == 0){
                printf("%c", '*');
            }
            else if(result[j] == 1){
                printf("%c", 'W');
            }
            else if(result[j] == 2){
                printf("%c", 'R');
            }
        }
        int vic = 0;
        for(int v=0;v<4;v++){
            if(result[v] == 1){
                vic++;
            }
            if(vic==4){
                win = true;
                printf("gagne");
            }
        }
        coups++;
    
    }
    int vic = 0;
    for(int v=0;v<4;v++){
            if(result[v] == 1){
                vic++;
            }
            if(vic==4){
                win = true;
                printf("gagne");
            }
            else{
                printf("perdu");
            }
        }
    return 0;
}