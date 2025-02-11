Aqui está o README revisado, corrigido e melhor estruturado:  

---

# 🎯 Controle de Servomotor por PWM com Raspberry Pi Pico W  

Este projeto tem como objetivo controlar um **servomotor** utilizando o módulo **PWM (Pulse Width Modulation)** do microcontrolador **Raspberry Pi Pico W**. A simulação foi realizada no ambiente **Wokwi**, e o código foi desenvolvido em **C** utilizando o **Pico SDK**.  

---

## 🛠️ Componentes Utilizados  

- **Microcontrolador**: Raspberry Pi Pico W  
- **Servomotor**: Motor micro servo padrão (**simulado no Wokwi**)  
- **LED RGB**: Conectado à GPIO **12** (utilizado para experimento com **BitDogLab**)  

---

## 📋 Requisitos do Projeto  

1. **Frequência do PWM**  
   - A GPIO **22** foi configurada para operar com uma frequência de aproximadamente **50 Hz** (**período de 20 ms**).  

2. **Ciclo Ativo do PWM**  
   - **2.400 µs** (~12% de duty cycle) → Posição **180°**  
   - **1.470 µs** (~7,35% de duty cycle) → Posição **90°**  
   - **500 µs** (~2,5% de duty cycle) → Posição **0°**  

3. **Movimentação Periódica**  
   - O servomotor se move suavemente entre **0° e 180°**, com **incrementos de ±5 µs** e um **atraso de 10 ms** entre cada ajuste.  

4. **Experimento com LED RGB**  
   - Utilizando a ferramenta **BitDogLab**, foi observado e documentado o comportamento do **LED RGB** conectado à **GPIO 12**.  

---

## 🚀 Como Executar o Projeto  

### ✅ Pré-requisitos  

- **Ambiente de Desenvolvimento**: VS Code  
- **Ferramentas Necessárias**:  
  - **Pico SDK**  
  - **Simulador Wokwi** integrado ao VS Code  
- **Linguagem**: **C**  

### 🔧 Passos para Execução  

1. **Clone o Repositório**  
   ```bash
   git clone https://github.com/KimberllyAlves/servo_pwm.git
   ```
   
2. **Configure o Ambiente**  
   - Certifique-se de que o **Pico SDK** está instalado e configurado no **VS Code**.  
   - Integre o **simulador Wokwi** ao **VS Code**.  

3. **Compile e Execute**  
   - Abra o projeto no **VS Code**.  
   - Compile o código utilizando o **Pico SDK**.  
   - Execute a simulação no **Wokwi**.  

4. **Observe os Resultados**  
   - O **servomotor** deve se mover entre as posições **0°, 90° e 180°**, com pausas de **5 segundos** em cada posição.  
   - O **LED RGB** deve exibir um comportamento específico, conforme observado no experimento com **BitDogLab**.  

---

## 📹 Vídeo de Demonstração  
🔗 Assista ao vídeo de demonstração aqui


