/*

ATIVIDADE-2-EMBARCATECH_SUBGRUPO-4

DESCRIÇÃO: O presente projeto busca utilizar o monitor serial para realizar o envio de comandos para o microcontrolador raspberry pi pico W. A comunicação via protocolo UART entre o computador e a placa viabiliza o envio do programa e execução do mesmo, o qual, consiste em fazer o controle leds RGB e ativar um Buzzer por uma intervalo de 2000 ms.

Desenvolvedores: Theógenes Gabriel Araújo de Andrade,

DATA: 18/01/2025

*/

#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"

#define ledV 13
#define ledA 12
#define ledG 11
#define buzzer 21

// Inicializa os pinos como saída
void init_out() {
    gpio_init(ledV);
    gpio_init(ledA);
    gpio_init(ledG);
    gpio_init(buzzer);

    gpio_set_dir(ledV, GPIO_OUT);
    gpio_set_dir(ledA, GPIO_OUT);
    gpio_set_dir(ledG, GPIO_OUT);
    gpio_set_dir(buzzer, GPIO_OUT);

    // Todos os LEDs começam apagados
    gpio_put(ledV, 0);
    gpio_put(ledA, 0);
    gpio_put(ledG, 0);
    gpio_put(buzzer, 0);
}

//Modularização da frequência sonora
void play_sound(uint frequency, uint duration_ms) {
    uint delay = 1000000 / (2 * frequency); // Calcula o atraso (microsegundos) para a frequência
    uint cycles = frequency * duration_ms / 1000; // Número de ciclos para a duração

    for (uint i = 0; i < cycles; i++) {
        gpio_put(buzzer, 1); // Liga o buzzer
        sleep_us(delay);         // Espera metade do período
        gpio_put(buzzer, 0); // Desliga o buzzer
        sleep_us(delay);         // Espera a outra metade
    }
}

//controla o brilho dos leds
int put(int ledv, int leda, int ledg){
    gpio_put(ledV, ledv);
    gpio_put(ledA, leda);
    gpio_put(ledG, ledg);
}

int main() {

    stdio_init_all();
    init_out();

    char p[20];
    
    while (1) {
        printf("Digite e obtenha as saídas: (RED, BLUE, GREEN, WHITE, OFF, BUZZER): ");
        scanf(" %s", p);

        if (strcmp(p, "RED") == 0) {
            put(1, 0, 0);
            printf("LED VERMELHO ligado.\n");
        } else if (strcmp(p, "BLUE") == 0) {
            put(0, 1, 0);
            printf("LED AZUL ligado.\n");
        } else if (strcmp(p, "GREEN") == 0) {
            put(0, 0, 1);
            printf("LED VERDE ligado.\n");
        } else if (strcmp(p, "WHITE") == 0) {
            put(1, 1, 1);
            printf("BRANCO ligado.\n");

        } else if (strcmp(p, "OFF") == 0) {
            put(0,0,0);
            printf("Desligado.\n");
        }
         else if (strcmp(p, "BUZZER") == 0) {
            put(0,0,0);
            play_sound(1000, 500);
            sleep_ms(2000);
            gpio_put(buzzer, 0);
            printf("BUZZER ligado.\n");
        } 
    }

    return 0;
}

