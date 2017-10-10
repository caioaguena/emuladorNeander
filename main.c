/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Caio
 *
 * Created on 10 de Outubro de 2017, 00:42
 */

#include <stdio.h>
#include <stdlib.h>

#define NOP (uint8_t)(0x00)
#define STA (uint8_t)(0x10)
#define LDA (uint8_t)(0x20)
#define ADD (uint8_t)(0x30)
#define OR (uint8_t)(0x40)
#define AND (uint8_t)(0x50)
#define NOT (uint8_t)(0x60)
#define JMP (uint8_t)(0x80)
#define JN (uint8_t)(0x90)
#define JZ (uint8_t)(0xA0)
#define HLT (uint8_t)(0xF0)
/*
 * 
 */
int main(int argc, char** argv) {
  FILE *arq;
  uint8_t Vet[256];
  int result;
  int i;
  uint8_t ac;

  // Abre um arquivo BINÁRIO para LEITURA
  arq = fopen("out4.bin", "rb");
  if (arq == NULL)  // Se houve erro na abertura
  {
     printf("Problemas na abertura do arquivo\n");
     return;
  }
  result = fread (&Vet[0], sizeof(uint8_t), 256, arq);
 // printf("Nro de elementos lidos: %d\n", result);

  for (i=0; i<result; i++){
      printf("%d: %x\n", i, Vet[i]);
  }
  
  fclose(arq);
  
  for(int j=0;j <=255;j++){
      switch((uint16_t)Vet[j])
  { 
    case (uint16_t)NOP: //faz nada
        //printf("fez nada \n");
      break;
    case (uint16_t)STA:
        Vet[Vet[j+1]] = ac;
      break;
    case (uint16_t)LDA:
        ac = Vet[Vet[j+1]];
        printf("\n %x Valor a ser carregado: ",Vet[Vet[j+1]]);
      break;
    case (uint16_t)ADD:
         ac = ac + Vet[Vet[j+1]];
      break;
    case (uint16_t)OR:
        ac = ac|Vet[Vet[j+1]];
      break;
    case (uint16_t)AND:
        ac = ac&Vet[Vet[j+1]];
      break;
    case (uint16_t)NOT:
        ac = -ac-1;
      break;
    case (uint16_t)JMP:
        j = (int)Vet[j]-1;
      break;
    case (uint16_t)JN:
        if(ac > 0x7E){
            j = (int)Vet[j+1]-1;
        }
      break;
      case (uint16_t)JZ:
          if(ac == 0){
            j = (int)Vet[j+1]-1;
        }
      break;
       case (uint16_t)HLT:j=256;
      break;
    default:break;
  }
      if(j==256 || j==-1){}
      else{
      printf("\n AC: %x",ac);
      printf(" PC: %i",j);
      }
  }
  
   
  
}