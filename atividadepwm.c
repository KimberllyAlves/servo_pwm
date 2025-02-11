#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include <stdio.h>

#define SERVO_PIN 12  // Define o pino 22 como servoPin

void set_servo_angle(uint slice_num, uint angle) {
    uint16_t duty_cycle;

    // Usando switch para verificar o ângulo
    switch (angle) {
        case 0:
            duty_cycle = 500;  // 0 graus
            printf("Servo movido para 0 graus\n");
            break;
        case 90:
            duty_cycle = 1470; // 90 graus
            printf("Servo movido para 90 graus\n");
            break;
        case 180:
            duty_cycle = 2400; // 180 graus
            printf("Servo movido para 180 graus\n");
            break;
        default:
            printf("Ângulo inválido! Use 0, 90 ou 180 graus.\n");
            return;  // Sai da função se o ângulo for inválido
    }

    pwm_set_chan_level(slice_num, PWM_CHAN_A, duty_cycle);
}

void move_servo_smoothly(uint slice_num) {
    uint16_t duty_cycle = 500;  // Começa em 0 graus
    while (true) {
        // Move de 0 a 180 graus
        while (duty_cycle <= 2400) {
            pwm_set_chan_level(slice_num, PWM_CHAN_A, duty_cycle);
            duty_cycle += 5;
            sleep_ms(10);
        }
        printf("Servo movido para 180 graus\n");

        // Move de 180 a 0 graus
        while (duty_cycle >= 500) {
            pwm_set_chan_level(slice_num, PWM_CHAN_A, duty_cycle);
            duty_cycle -= 5;
            sleep_ms(10);
        }
        printf("Servo movido para 0 graus\n");
    }
}

int main() {

    stdio_init_all();  // Inicializa a comunicação serial para printf

    // Configura o GPIO 22 (servoPin) como PWM
    gpio_set_function(SERVO_PIN, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(SERVO_PIN);

    // Configura a frequência do PWM para 50 Hz
    pwm_set_clkdiv(slice_num, 125.0f); // Divisor de clock para 50 Hz
    pwm_set_wrap(slice_num, 20000);    // Período de 20 ms

    pwm_set_enabled(slice_num, true);  // Habilita o PWM

    // Move o servomotor para 180 graus e espera 5 segundos
    set_servo_angle(slice_num, 180);
    sleep_ms(5000);

    // Move o servomotor para 90 graus e espera 5 segundos
    set_servo_angle(slice_num, 90);
    sleep_ms(5000);

    // Move o servomotor para 0 graus e espera 5 segundos
    set_servo_angle(slice_num, 0);
    sleep_ms(5000);

    // Inicia a movimentação suave do servomotor
    move_servo_smoothly(slice_num);

    return 0;
}