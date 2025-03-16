#include <stdio.h>


void readFile(char* output, char* filename){
  FILE *f = fopen(filename, "r");
    // Nessa função, já supomos que o input será exatamente "pesquisa e ordenacao"
    // desse modo são 21 caracteres.
    fgets(output, 21, f);
    // Só mandar o ponteiro pra função fgets altera
    // a string no endereço onde ela se localiza
    // por isso a função é void
 }
void createFile(char* contents, char* filename) {
    FILE *f = fopen(filename, "w+");
    fputs(contents, f);
}

int main(){
    char reading[21];
    readFile(reading, "arquivo.txt");
    // reverse strings
    for(int i = 0; i < 12; i++) {
        const char aux = reading[i];
        reading[i] = reading[19-i];
        reading[20-i] = aux;
    }
    printf(reading);
    createFile(reading, "resultado.txt");
    return 0;
    }