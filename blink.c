/*
ATIVIDADE 1-AULA SINCRONA(14/01)

DESCRIÇÃO: O projeto da atividade prática visa fazer uso dos botões associados ao teclado matricial, a fim de ligar dispositivos de saída. O teclado matricial 4 x 4 é formado por linhas e colunas, cuja localização dos botões é definida por uma valor de posição na matriz na qual está inserida. Em relação ao teclado, duas funções são imprescindíveis, são elas, key_init e key_read, cuja função, respectivamente é inicializar corretamente e fazer a leitura do teclado. Ademais, todos os disposivos de saída são inicializados em uma função(Disp_OUT) e o buzzer tem sua frequência sonora controlada por play_som.


*/

#include <stdio.h>
#include "pico/stdlib.h"

#define ROWS 4
#define COLS 4
#define LED_GREEN 11
#define LED_BLUE 12
#define LED_RED 13
#define BUZZER 15

const uint8_t ROW_PINS[ROWS] = {8, 7, 6, 5}; // R1 R2 R3 R4
const uint8_t COL_PINS[COLS] = {4, 3, 2, 27}; // C1 C2 C3 C4


// Mapeamento do teclado matricial
const char KEY_MAP[ROWS][COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
};

void keypad_init() {
    for (int i = 0; i < ROWS; i++) {
        gpio_init(ROW_PINS[i]);
        gpio_set_dir(ROW_PINS[i], GPIO_OUT);
        gpio_put(ROW_PINS[i], 0);
    }
    for (int i = 0; i < COLS; i++) {
        gpio_init(COL_PINS[i]);
        gpio_set_dir(COL_PINS[i], GPIO_IN);
        gpio_pull_down(COL_PINS[i]);
    }
}


//Leitura do Keypad
char read_keypad() {
    for (int row = 0; row < ROWS; row++) {
        gpio_put(ROW_PINS[row], 1);

        for (int col = 0; col < COLS; col++) {
            if (gpio_get(COL_PINS[col])) {
                gpio_put(ROW_PINS[row], 0);
                sleep_ms(20);
                return KEY_MAP[row][col];
            }
        }
        gpio_put(ROW_PINS[row], 0);
    }
    return '\0';
}

// Definição dos Dispositivos de Saída
void Disp_OUT() {
   //Leds inicialização
    gpio_init(LED_GREEN);
    gpio_set_dir(LED_GREEN, GPIO_OUT);   
    gpio_init(LED_BLUE);
    gpio_set_dir(LED_BLUE, GPIO_OUT);   
    gpio_init(LED_RED);
    gpio_set_dir(LED_RED, GPIO_OUT);   

    //Buzzer inicialização
    gpio_init(BUZZER);
    gpio_set_dir(BUZZER, GPIO_OUT);
}

// inicialização e definição da frequência sonora
void play_som(){
  for (int i = 0; i < 80; i++) {
    gpio_put(BUZZER, 1);
    sleep_ms(2);
    gpio_put(BUZZER, 0);
    sleep_ms(2);
  }
}

// Função para ligar e desligar os Leds em sequencia e acionar Buzzer, de forma coordenadada
void piscar_leds_sequencia(){
    for(int i = 0; i< 3; i++){
        gpio_put(LED_GREEN, 1);
        gpio_put(LED_BLUE, 1);
        gpio_put(LED_RED, 1);
        sleep_ms(200);

        gpio_put(LED_GREEN, 0);
        gpio_put(LED_BLUE, 1);
        gpio_put(LED_RED, 1);
        sleep_ms(200);

        gpio_put(LED_GREEN, 0);
        gpio_put(LED_BLUE, 0);
        gpio_put(LED_RED, 1);
        sleep_ms(200);

        gpio_put(LED_GREEN, 0);
        gpio_put(LED_BLUE, 0);
        gpio_put(LED_RED, 0);
        sleep_ms(200);
    }
    for(int j = 0; j<3; j++){

        gpio_put(LED_GREEN, 1);
        gpio_put(LED_BLUE, 1);
        gpio_put(LED_RED, 1);
        play_som();
        sleep_ms(250);
        
        gpio_put(LED_GREEN, 0);
        gpio_put(LED_BLUE, 0);
        gpio_put(LED_RED, 0);
        sleep_ms(250);
    }
}

void alarm_mode() {
    for(int i = 0; i <= 10; i++) {
        gpio_put(LED_GREEN, 1);
        gpio_put(LED_BLUE, 1);
        gpio_put(LED_RED, 1);
        play_som();
        sleep_ms(200);

        gpio_put(LED_GREEN, 0);
        gpio_put(LED_BLUE, 0);
        gpio_put(LED_RED, 0);
        sleep_ms(200);
    }
}

// Função para piscar LEDs em sequência
void pisca_leds() {
    for (int i = 0; i < 3; i++) { // Pisca 3 vezes
        gpio_put(LED_GREEN, 1);
        sleep_ms(200);
        gpio_put(LED_GREEN, 0);

        gpio_put(LED_BLUE, 1);
        sleep_ms(200);
        gpio_put(LED_BLUE, 0);

        gpio_put(LED_RED, 1);
        sleep_ms(200);
        gpio_put(LED_RED, 0);
    }
}

int main() {

    //Inicialição das funções
    Disp_OUT();
    stdio_init_all();
    keypad_init();


    while (true) {
        char key = read_keypad();
        if (key != '\0') {
            switch (key) {
                case '0':
                    piscar_leds_sequencia();
                    break;
                case '1':
                    alarm_mode();
                    break;
                case 'A':
                    gpio_put(LED_GREEN, 1);
                    sleep_ms(10);
                    gpio_put(LED_GREEN, 0);
                    break;
                case 'B':
                    gpio_put(LED_BLUE, 1);
                    sleep_ms(10);
                    gpio_put(LED_BLUE, 0);
                    break;
                case 'C':
                    gpio_put(LED_RED, 1);
                    sleep_ms(10);
                    gpio_put(LED_RED, 0);
                    break;
                case 'D':
                    gpio_put(LED_GREEN, 1);
                    gpio_put(LED_RED, 1);
                    gpio_put(LED_BLUE, 1);
                    sleep_ms(10);
                    gpio_put(LED_GREEN, 0);
                    gpio_put(LED_RED, 0);
                    gpio_put(LED_BLUE, 0);
                    break;
                case '#':
                    play_som();
                    break;
                case '*':
                    pisca_leds();
                    break;  
            }
        }
        //time para fluidez da execução
        sleep_ms(60);
    }
}