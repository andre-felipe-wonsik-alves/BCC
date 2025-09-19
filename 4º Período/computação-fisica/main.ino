

// ============================
// Variáveis de controle
// ============================


bool btn_state = 0;           // Estado atual do botão (pressionado/solto)
bool btn_last_state = 0;      // Estado anterior do botão
int btn_last_click = 0;       // Momento do último clique detectado
bool clk_state = 0;           // Estado atual do pino CLK do encoder rotativo
bool clk_last_state = 0;      // Estado anterior do CLK
int clk_last_turn = 0;        // Momento da última rotação detectada
bool dt_state = 0;            // Estado atual do pino DT do encoder
bool point = true;            // Estado do "ponto" (dois pontos do display, piscando)
bool slider_state = 0;

unsigned int valor = 0;       // Valor configurado (em segundos)
unsigned long last_update = 0;// Última atualização do display multiplexado
unsigned int last_point = 0;  // Última atualização do piscar do "ponto"
unsigned long beep_time = 0;  // Tempo de ativação do buzzer


// Dígitos individuais do display
int d = 0;  
int d0 = 0;  // Unidade dos segundos
int d1 = 0;  // Dezena dos segundos
int d2 = 0;  // Unidade dos minutos
int d3 = 0;  // Dezena dos minutos


bool countdown = false;       // Indica se o cronômetro está em contagem regressiva
int saida;                    // Dígito a ser exibido no display


unsigned long countdown_start = 0;  // Marca de tempo do início da contagem regressiva




// ============================
// Tabela do display 7 segmentos
// ============================
// Cada valor corresponde ao padrão dos segmentos para números 0–F
const unsigned char Tabela[] PROGMEM = {
 0x40, // 0
 0x79, // 1
 0x24, // 2
 0x30, // 3
 0x19, // 4
 0x12, // 5
 0x02, // 6
 0x78, // 7
 0x00, // 8
 0x18, // 9
 0x08, // A
 0x03, // b
 0x46, // C
 0x21, // d
 0x06, // E
 0x0E  // F
};




// ============================
// Configuração inicial
// ============================
void setup() {
 // Configuração do encoder rotativo
 DDRB &= ~(1 << PB0);  // PB0 = CLK como entrada
 PORTB |= (1<<PB0);    // Pull-up interno
 DDRB &= ~(1 << PB1);  // PB1 = DT como entrada
 PORTB |= (1<<PB1);    // Pull-up interno
 DDRB &= ~(1 << PB2);  // PB2 = botão SW como entrada
 PORTB |= (1<<PB2);    // Pull-up interno


 // Saídas: dois pontos e buzzer
 DDRB |= (1 << PB3);   // PB3 controla os "dois pontos" no display
 DDRB |= (1 << PB4);   // PB4 controla o buzzer


 // Estado inicial de saídas
 PORTB |= (1 << PB0);
 PORTB |= (1 << PB1);
 PORTB |= (1 << PB2);
 PORTB |= (1 << PB4);

// lendo o slider
 DDRC &= ~(1<<PC1);
 
 // estado inicial do slider
 PORTC |= (1<<PC1);


 // Display multiplexado
 DDRD = 0x7F;   // PORTD como saída (segmentos)
 PORTD = 0xFF;  // Apaga todos os segmentos
// Ajusta só os pinos do display como saída, mas mantém PC1 como entrada
DDRC |= (1<<PC2) | (1<<PC3) | (1<<PC4) | (1<<PC5);  // apenas os dígitos
PORTC |= (1<<PC2) | (1<<PC3) | (1<<PC4) | (1<<PC5); // desliga todos os dígitos

// PC1 continua sendo entrada com pull-up ativado
DDRC &= ~(1<<PC1);  
PORTC |= (1<<PC1);


 // Desliga UART (economia de energia, não usado aqui)
 UCSR0B = 0x00;


 clk_last_state = true;  // Estado inicial do encoder
}




// ============================
// Loop principal
// ============================
void loop() {
 // Leitura do encoder e botão
 clk_state = (PINB & (1 << PB0)) > 0;
 dt_state  = (PINB & (1 << PB1)) > 0;
 btn_state = (PINB & (1 << PB2)) > 0;
 slider_state = (PINC & (1 << PC1)) > 0;

 // --- Controle do encoder ---
 if(clk_state == 1 && clk_state != clk_last_state && (millis() - clk_last_turn) > 0) {
   clk_last_turn = millis();

   // Rotação horária → incrementa valor
   if(dt_state != clk_state) {
     if(!slider_state){
        valor += 60;
     } else{
        valor++;
     }
   }
   // Rotação anti-horária → decrementa valor
   else {
     if(!slider_state && valor > 0){
        valor -= 60;
     } else if (valor > 0){
        valor--;
     }
   }


   // Limite máximo: 59:59 (3600s)
   if(valor >= 3600) valor = 0;
 }


 // --- Conversão do valor em dígitos (MM:SS) ---
 d0 = valor % 10;          // unidade dos segundos
 d1 = (valor/10) % 6;      // dezena dos segundos (0–5)
 d2 = (valor/60) % 10;     // unidade dos minutos
 d3 = (valor/600) % 10;    // dezena dos minutos


 // --- Controle do botão ---
 if(btn_state != btn_last_state && btn_state == 0 && (millis() - btn_last_click) > 0) {
   btn_last_click = millis();
   countdown = !countdown;  // alterna entre configurar e contar
   countdown_start = valor * 1000 + millis(); // salva tempo inicial
 }


 // --- Contagem regressiva ---
 if(countdown) {
   if(valor > 0) {
     valor = (countdown_start - millis()) / 1000;
   }
   else { // Quando termina
     if(!beep_time) beep_time = millis();


     // Ativa buzzer por 500 ms
     if(millis() - beep_time < 500) PORTB &= ~(1 << PB4);
     else {
       beep_time = 0;
       PORTB |= (1 << PB4);
       countdown = false;
       countdown_start = 0;
     }
   }
 }


 // --- Multiplexação do display ---
 if ((millis() - last_update) >= 5) {
   last_update = millis();
   d %= 4;  // ciclo entre os 4 dígitos


   if (d==0) { // Dígito 0 (segundos unidade)
     saida = d0;
     PORTC &= ~(1<<PC3);
     PORTD = pgm_read_byte(&Tabela[saida]);
     PORTC |= (1<<PC2);
   }
   else if (d==1) { // Dígito 1 (segundos dezena)
     saida = d1;
     PORTC &= ~(1<<PC2);
     PORTD = pgm_read_byte(&Tabela[saida]);
     PORTC |= (1<<PC5);
   }
   else if (d==2) { // Dígito 2 (minutos unidade)
     saida = d2;
     PORTC &= ~(1<<PC5);
     PORTD = pgm_read_byte(&Tabela[saida]);
     PORTC |= (1<<PC4);
   }
   else if (d==3) { // Dígito 3 (minutos dezena)
     saida = d3;
     PORTC &= ~(1<<PC4);
     PORTD = pgm_read_byte(&Tabela[saida]);
     PORTC |= (1<<PC3);
   }
   d++;
 }


 // --- Controle do piscar do "ponto" ---
 if (millis() - last_point >= 500) {
   point = !point;
   last_point = millis();


   if(countdown) {
     if(!point) PORTB |= (1 << PB3 );  // acende ponto
     else PORTB &= ~(1 << PB3 );       // apaga ponto
   }
   else PORTB &= ~(1 << PB3 );         // ponto desligado fora do countdown
 }


 // Atualiza estados anteriores
 clk_last_state = clk_state;
 btn_last_state = btn_state;
}
