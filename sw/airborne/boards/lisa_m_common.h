#ifndef CONFIG_LISA_M_COMMON_H
#define CONFIG_LISA_M_COMMON_H

#include "generated/airframe.h"

/* SPI slave mapping */

#define SPI_SELECT_SLAVE0_PERIPH RCC_APB2ENR_IOPAEN
#define SPI_SELECT_SLAVE0_PORT GPIOA
#define SPI_SELECT_SLAVE0_PIN GPIO15

#define SPI_SELECT_SLAVE1_PERIPH RCC_APB2ENR_IOPAEN
#define SPI_SELECT_SLAVE1_PORT GPIOA
#define SPI_SELECT_SLAVE1_PIN GPIO4

#define SPI_SELECT_SLAVE2_PERIPH RCC_APB2ENR_IOPBEN
#define SPI_SELECT_SLAVE2_PORT GPIOB
#define SPI_SELECT_SLAVE2_PIN GPIO12

#define SPI_SELECT_SLAVE3_PERIPH RCC_APB2ENR_IOPCEN
#define SPI_SELECT_SLAVE3_PORT GPIOC
#define SPI_SELECT_SLAVE3_PIN GPIO13

#define SPI_SELECT_SLAVE4_PERIPH RCC_APB2ENR_IOPCEN
#define SPI_SELECT_SLAVE4_PORT GPIOC
#define SPI_SELECT_SLAVE4_PIN GPIO12

#define SPI_SELECT_SLAVE5_PERIPH RCC_APB2ENR_IOPCEN
#define SPI_SELECT_SLAVE5_PORT GPIOC
#define SPI_SELECT_SLAVE5_PIN GPIO4

/* PPM
 *
 * Default is PPM config 2, input on GPIO01 (Servo pin 6)
 */

#ifndef PPM_CONFIG
#define PPM_CONFIG 2
#endif

#if PPM_CONFIG == 1
/* input on PA01 (UART1_RX) */
#define USE_PPM_TIM1 1
#define PPM_CHANNEL         TIM_IC3
#define PPM_TIMER_INPUT     TIM_IC_IN_TI3
#define PPM_IRQ             NVIC_TIM1_UP_IRQ
#define PPM_IRQ2            NVIC_TIM1_CC_IRQ
#define PPM_IRQ_FLAGS       (TIM_DIER_CC3IE | TIM_DIER_UIE)
#define PPM_GPIO_PERIPHERAL RCC_APB2ENR_IOPAEN
#define PPM_GPIO_PORT       GPIOA
#define PPM_GPIO_PIN        GPIO10

#elif PPM_CONFIG == 2
/* input on PA10 (Servo 6 pin) */
#define USE_PPM_TIM2 1
#define PPM_CHANNEL         TIM_IC2
#define PPM_TIMER_INPUT     TIM_IC_IN_TI2
#define PPM_IRQ             NVIC_TIM2_IRQ
#define PPM_IRQ_FLAGS       (TIM_DIER_CC2IE | TIM_DIER_UIE)
#define PPM_GPIO_PERIPHERAL RCC_APB2ENR_IOPAEN
#define PPM_GPIO_PORT       GPIOA
#define PPM_GPIO_PIN        GPIO1

// Move default ADC timer
#if USE_AD_TIM2
#undef USE_AD_TIM2
#endif
#define USE_AD_TIM1 1

#else
#error "Unknown PPM config"

#endif // PPM_CONFIG

/* ADC */

// active ADC
#define USE_AD1 1
#define USE_AD1_1 1
#define USE_AD1_2 1
#define USE_AD1_3 1
#define USE_AD1_4 1


/*
 * PWM
 *
 */
#define PWM_USE_TIM3 1
#define PWM_USE_TIM5 1

#define USE_PWM1 1
#define USE_PWM2 1
#define USE_PWM3 1
#define USE_PWM4 1
#define USE_PWM5 1
#define USE_PWM6 1

#if USE_SERVOS_7AND8
  #if USE_I2C1
    #error "You cannot use Servos 7and8 and I2C1 at the same time"
  #else
    #define ACTUATORS_PWM_NB 8
    #define USE_PWM7 1
    #define USE_PWM8 1
    #define PWM_USE_TIM4 1
  #endif
#else
  #define ACTUATORS_PWM_NB 6
#endif

// PWM_SERVO_X should be the internal servo position (starting from 0) + 1 (meaning the servo is activated)
#if USE_PWM1
#define PWM_SERVO_1 1
#define PWM_SERVO_1_TIMER TIM3
#define PWM_SERVO_1_RCC_IOP RCC_APB2ENR_IOPCEN
#define PWM_SERVO_1_GPIO GPIOC
#define PWM_SERVO_1_PIN GPIO6
#define PWM_SERVO_1_AF 0
#define PWM_SERVO_1_OC TIM_OC1
#define PWM_SERVO_1_OC_BIT (1<<0)
#else
#define PWM_SERVO_1_OC_BIT 0
#endif

#if USE_PWM2
#define PWM_SERVO_2 2
#define PWM_SERVO_2_TIMER TIM3
#define PWM_SERVO_2_RCC_IOP RCC_APB2ENR_IOPCEN
#define PWM_SERVO_2_GPIO GPIOC
#define PWM_SERVO_2_PIN GPIO7
#define PWM_SERVO_2_AF 0
#define PWM_SERVO_2_OC TIM_OC2
#define PWM_SERVO_2_OC_BIT (1<<1)
#else
#define PWM_SERVO_2_OC_BIT 0
#endif

#if USE_PWM3
#define PWM_SERVO_3 3
#define PWM_SERVO_3_TIMER TIM3
#define PWM_SERVO_3_RCC_IOP RCC_APB2ENR_IOPCEN
#define PWM_SERVO_3_GPIO GPIOC
#define PWM_SERVO_3_PIN GPIO8
#define PWM_SERVO_3_AF 0
#define PWM_SERVO_3_OC TIM_OC3
#define PWM_SERVO_3_OC_BIT (1<<2)
#else
#define PWM_SERVO_3_OC_BIT 0
#endif

#if USE_PWM4
#define PWM_SERVO_4 4
#define PWM_SERVO_4_TIMER TIM3
#define PWM_SERVO_4_RCC_IOP RCC_APB2ENR_IOPCEN
#define PWM_SERVO_4_GPIO GPIOC
#define PWM_SERVO_4_PIN GPIO9
#define PWM_SERVO_4_AF 0
#define PWM_SERVO_4_OC TIM_OC4
#define PWM_SERVO_4_OC_BIT (1<<3)
#else
#define PWM_SERVO_4_OC_BIT 0
#endif

#if USE_PWM5
#define PWM_SERVO_5 5
#define PWM_SERVO_5_TIMER TIM5
#define PWM_SERVO_5_RCC_IOP RCC_APB2ENR_IOPAEN
#define PWM_SERVO_5_GPIO GPIOA
#define PWM_SERVO_5_PIN GPIO0
#define PWM_SERVO_5_AF 0
#define PWM_SERVO_5_OC TIM_OC1
#define PWM_SERVO_5_OC_BIT (1<<0)
#else
#define PWM_SERVO_5_OC_BIT 0
#endif

#if USE_PWM6
#define PWM_SERVO_6 6
#define PWM_SERVO_6_TIMER TIM5
#define PWM_SERVO_6_RCC_IOP RCC_APB2ENR_IOPAEN
#define PWM_SERVO_6_GPIO GPIOA
#define PWM_SERVO_6_PIN GPIO1
#define PWM_SERVO_6_AF 0
#define PWM_SERVO_6_OC TIM_OC2
#define PWM_SERVO_6_OC_BIT (1<<1)
#else
#define PWM_SERVO_6_OC_BIT 0
#endif

#if USE_PWM7
#define PWM_SERVO_7 7
#define PWM_SERVO_7_TIMER TIM4
#define PWM_SERVO_7_RCC_IOP RCC_APB2ENR_IOPBEN
#define PWM_SERVO_7_GPIO GPIOB
#define PWM_SERVO_7_PIN GPIO6
#define PWM_SERVO_7_AF 0
#define PWM_SERVO_7_OC TIM_OC1
#define PWM_SERVO_7_OC_BIT (1<<0)
#else
#define PWM_SERVO_7_OC_BIT 0
#endif

#if USE_PWM8
#define PWM_SERVO_8 8
#define PWM_SERVO_8_TIMER TIM4
#define PWM_SERVO_8_RCC_IOP RCC_APB2ENR_IOPBEN
#define PWM_SERVO_8_GPIO GPIOB
#define PWM_SERVO_8_PIN GPIO7
#define PWM_SERVO_8_AF 0
#define PWM_SERVO_8_OC TIM_OC2
#define PWM_SERVO_8_OC_BIT (1<<1)
#else
#define PWM_SERVO_8_OC_BIT 0
#endif

/* servos 1-4 on TIM3 */
#define PWM_TIM3_CHAN_MASK (PWM_SERVO_1_OC_BIT|PWM_SERVO_2_OC_BIT|PWM_SERVO_3_OC_BIT|PWM_SERVO_4_OC_BIT)
/* servos 5-6 on TIM5 */
#define PWM_TIM5_CHAN_MASK (PWM_SERVO_5_OC_BIT|PWM_SERVO_6_OC_BIT)
/* servos 7-8 on TIM4 if USE_SERVOS_7AND8 */
#define PWM_TIM4_CHAN_MASK (PWM_SERVO_7_OC_BIT|PWM_SERVO_8_OC_BIT)


#endif

