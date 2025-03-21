#include <stdio.h>
#define INPUT "input.txt"
#define OUTPUT "output.txt"

int char_counter(char* filename){
  int counter;
  char c;
  printf("Contando caracteres...\n");
  counter = 0;
  FILE *f = fopen(filename, "r");
  while((c = fgetc(f)) != EOF){
    counter++;
  }
  printf("Terminou contagem de caracteres...");
  fclose(f);
  return counter;
}

void reverseFile(char* filename){
    FILE *f = fopen(filename, "r");
    int file_len = char_counter(filename);
    fseek(f, file_len, SEEK_SET);
    FILE *foutput = fopen("output.txt", "w+");
    char list[file_len];
    for(int i = 0; i < file_len; i++){
      fseek(f, file_len - i, SEEK_SET);
      char c = fgetc(f);
      list[i] = c;
    }
    printf("Inserindo string %s\n", list);
    fputs(list, foutput);
    fclose(foutput);
    fclose(f);
    return;

  }

 void writeBinary(char* filename){
   FILE *f = fopen(filename, "wb+");
   int numbers[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8 ,9 , 10};
   fwrite(numbers, sizeof(int), 11, f);
   fclose(f);
 }

 void getBinary(char *filename, int* destination, int size){
   FILE *f = fopen(filename, "rb");
   int reading[size];
   fread(destination, sizeof(int), size, f);
 }
void calculateAverage(int *array, int size) {
  double total = 0;
  printf("%d\n", size);
  for(int i = 0; i < size; i++)
   {
      total += array[i];
   }
   double average = (total / size);
  printf("A média é: %.2lf\n", average);
}
int main() {
  char* input = INPUT;
  // .1
  // reverseFile(input);
  // . 2 binary
  writeBinary("binaryInput.bin");
  int num_list[11];
  getBinary("binaryInput.bin", num_list, 11);
  calculateAverage(num_list, 11);
  int testing[3] = {1,2,3};
  calculateAverage(testing, 3);

  return 0;
}