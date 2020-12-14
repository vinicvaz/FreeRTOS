/* 
 * File:   user_structures.h
 * Author: Giulio
 *
 * Created on 12 de Dezembro de 2020, 15:57
 */

#ifndef USER_STRUCTURES_H
#define	USER_STRUCTURES_H
#define MAX_CLOTHES 8
#define CYCLES_LIFE 10000


//////////////// TYPES ////////////////

typedef struct clothes_control
{
    //u_int id;
    int color; //colorida = 0; branca = 1;
    //u_int qtd; //quantidade pode ser usada pra saber o tempo de lavagem e de passagem
    int washing_cycles; //ciclo de lavagem
    int state;          // 0 suja; 1 limpa; 2 pronta

} clothes_control_t;

typedef struct fila_clothes
{
    clothes_control_t clothes_waiting[MAX_CLOTHES]; //fila de roupas prontas para serem lavadas
    int fila_size;                                // tamanho da fila
    clothes_control_t clothes_washing;
    clothes_control_t clothes_ironing;
    clothes_control_t clothes_finished[MAX_CLOTHES];
    int clothes_finished_size;

    //u_int clothes_washing;
} fila_clothes_t;



//////////////// RECURSOS ////////////////

typedef struct machine
{
    int counter;
    int flag; //0->desocupada; 1->ocupada;
        
} machine_t;

#endif	/* USER_STRUCTURES_H */

