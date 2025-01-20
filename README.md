# Projeto: Controle de Dispositivos com Teclado Matricial

## Descrição
Este projeto tem como objetivo implementar o controle de dispositivos de saída, como LEDs e um buzzer, utilizando um teclado matricial 4x4 conectado a uma Raspberry Pi Pico. As principais funções incluem a inicialização do teclado matricial, a leitura das teclas pressionadas e o acionamento dos dispositivos de saída com base na entrada do teclado.

## Estrutura do Teclado Matricial
O teclado matricial 4x4 é composto por:
- **Linhas (ROWS):** Pinos conectados às linhas do teclado.
- **Colunas (COLS):** Pinos conectados às colunas do teclado.

Cada botão do teclado é mapeado para uma posição na matriz e representa um caractere conforme o seguinte esquema:

```
  {'1', '2', '3', 'A'}
  {'4', '5', '6', 'B'}
  {'7', '8', '9', 'C'}
  {'*', '0', '#', 'D'}
```

## Funcionalidades
1. **Inicialização do Teclado:** A função `keypad_init` configura os pinos do teclado como entradas ou saídas conforme necessário.
2. **Leitura do Teclado:** A função `read_keypad` identifica a tecla pressionada e retorna o caractere correspondente.
3. **Controle de LEDs:**
   - Tecla `A`: Liga o LED verde.
   - Tecla `B`: Liga o LED azul.
   - Tecla `C`: Liga o LED vermelho.
   - Tecla `D`: Liga todos os LEDs simultaneamente.
4. **Controle do Buzzer:**
   - Tecla `#`: Aciona o buzzer com uma frequência predefinida.
5. **Funcionalidade Extra - Pisca LEDs em Sequência:**
   - A tecla `*` aciona a função `pisca_leds`, que faz os LEDs piscarem em sequência, três vezes, indicando um evento ou status.
6. **Funcionalidade Extra - Modo Alarme:**
   - A tecla `1` aciona a função `alarm_mode`, que faz os LEDs piscarem 10 vezes juntamente com o efeito sonoro emitido pelo buzzer.
7. **Funcionalidade Extra - Modo Desligar Leds em sequencia:**
   - A tecla `0` aciona a função `pisca_leds_sequencia`, que faz os leds desligarem em sequencia, três vezes, e piscar os mesmos simultaneamente juntamente com o acionamento do Buzzer.
8. **Funcionalidade Extra - Tocar "Cai Cai Balão":**
   - A tecla `2` aciona a função `musica`, que faz o acionamento do buzzer em frêquencia certas para tocar as notas da música Cai Cai Balão.



## Hardware Utilizado
- **Microcontrolador:** Raspberry Pi Pico.
- **Teclado Matricial 4x4:** Utilizado para entrada de dados.
- **LEDs:** Verde, azul e vermelho conectados aos pinos GPIO 11, 12 e 13, respectivamente.
- **Buzzer:** Conectado ao pino GPIO 15.

### Pinos GPIO do Teclado
- **Linhas (ROWS):** GPIO 8, 7, 6, 5.
- **Colunas (COLS):** GPIO 4, 3, 2, 27.

## Como Usar
1. **Conecte o Hardware:** Certifique-se de que todos os dispositivos estejam conectados corretamente aos pinos especificados.
2. **Compile o Código:** Utilize um ambiente de desenvolvimento para compilar e enviar o código para a Raspberry Pi Pico.
3. **Execute o Programa:** Inicialize o sistema e pressione as teclas no teclado matricial para controlar os dispositivos de saída.

## Dependências
- Biblioteca `pico/stdlib.h` para controle de GPIO e gerenciamento de tempo.

## Fluxo do Programa
1. Inicialização do teclado e dos dispositivos de saída (LEDs e buzzer).
2. Monitoramento contínuo do teclado para detectar teclas pressionadas.
3. Execução de ações correspondentes com base na entrada do teclado.

## Observações
- Certifique-se de que os resistores pull-down estejam configurados corretamente para evitar leituras erradas no teclado matricial.
- Adicione uma fonte de alimentação estável para o funcionamento adequado dos LEDs e do buzzer.

## Vídeo Demonstrativo
Adicione aqui o link para o vídeo de demonstração do projeto:
[Link para o vídeo](https://drive.google.com/file/d/1UsoD_r4XtI_9eVaffLhlHnI-RMFj4bII/view?usp=sharing)

## Licença
Este projeto está sob a licença MIT. Você é livre para modificar e usar o código conforme necessário, desde que mantenha a referência ao autor original.

---
**Autores:** Theógenes Gabriel Araújo de Andrade, Lucas Dias da Silva, Marco Túlio Macêdo O. dos Santos, Luis Filipe Vieira Silva


