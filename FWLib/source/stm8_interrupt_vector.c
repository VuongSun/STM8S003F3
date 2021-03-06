/**
  ******************************************************************************
  * @file stm8_interrupt_vector.c
  * @author  MCD Application Team
  * @version V2.3.1
  * @date    14-February-2011
  * @brief   This file provides the interrupt vector table for STM8L15x device.
  ******************************************************************************
  * @copy
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
 */


#include "stm8s_it.h"
/* Private typedef -----------------------------------------------------------*/
typedef void @far (*interrupt_handler_t)(void);

/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
struct interrupt_vector {
	u8 interrupt_instruction;
	interrupt_handler_t interrupt_handler;
};
extern void _stext();     /* startup routine */
void main(void);

struct interrupt_vector const _vectab[] = {
  {0x82, (interrupt_handler_t)_stext}, /* RESET */
  {0x82, (interrupt_handler_t)TRAP_IRQHandler}, /* TRAP - Software interrupt */
	{0x82, (interrupt_handler_t)TLI_IRQHandler}, /* irq0 - External Top Level interrupt (TLI) */
	{0x82, (interrupt_handler_t)AWU_IRQHandler}, /* irq1 - Auto Wake Up from Halt interrupt */
	{0x82, (interrupt_handler_t)CLK_IRQHandler}, /* irq2 - Clock Controller interrupt */
  {0x82, (interrupt_handler_t)EXTI_PORTA_IRQHandler}, /* irq3 - External interrupt 0 (GPIOA) */
	{0x82, (interrupt_handler_t)EXTI_PORTB_IRQHandler}, /* irq4 - External interrupt 1 (GPIOB) */
	{0x82, (interrupt_handler_t)EXTI_PORTC_IRQHandler}, /* irq5 - External interrupt 2 (GPIOC) */
	{0x82, (interrupt_handler_t)EXTI_PORTD_IRQHandler}, /* irq6 - External interrupt 3 (GPIOD) */
	{0x82, (interrupt_handler_t)EXTI_PORTE_IRQHandler}, /* irq7 - External interrupt 4 (GPIOE) */
	
#ifdef STM8S208
	{0x82, (interrupt_handler_t)CAN_RX_IRQHandler}, /* irq8 - CAN Rx interrupt */
	{0x82, (interrupt_handler_t)CAN_TX_IRQHandler}, /* irq9 - CAN Tx/ER/SC interrupt */
#elif defined (STM8S903)
	{0x82, (interrupt_handler_t)EXTI_PORTF_IRQHandler}, /* irq8 - External interrupt 5 (GPIOF) */
	{0x82, (interrupt_handler_t)NonHandledInterrupt}, /* irq9 - Reserved */
#else /*STM8S207, STM8S105 or STM8S103*/
	{0x82, (interrupt_handler_t)NonHandledInterrupt}, /* irq8 - Reserved */
	{0x82, (interrupt_handler_t)NonHandledInterrupt}, /* irq9 - Reserved */
#endif /*STM8S208*/
	{0x82, (interrupt_handler_t)SPI_IRQHandler}, /* irq10 - SPI End of transfer interrupt */
	{0x82, (interrupt_handler_t)TIM1_UPD_OVF_TRG_BRK_IRQHandler}, /* irq11 - TIM1 Update/Overflow/Trigger/Break interrupt */
	{0x82, (interrupt_handler_t)TIM1_CAP_COM_IRQHandler}, /* irq12 - TIM1 Capture/Compare interrupt */
  
#ifdef STM8S903
  {0x82, (interrupt_handler_t)TIM5_UPD_OVF_BRK_TRG_IRQHandler}, /* irq13 - TIM5 Update/Overflow/Break/Trigger interrupt  */
  {0x82, (interrupt_handler_t)TIM5_CAP_COM_IRQHandler}, /* irq14 - TIM5 Capture/Compare interrupt */
	
#else /*STM8S208, STM8S207, STM8S105 or STM8S103*/
  {0x82, (interrupt_handler_t)TIM2_UPD_OVF_BRK_IRQHandler}, /* irq13 - TIM2 Update/Overflow/Break interrupt  */
  {0x82, (interrupt_handler_t)TIM2_CAP_COM_IRQHandler}, /* irq14 - TIM2 Capture/Compare interrupt */
#endif /*STM8S903*/
	
#if defined (STM8S208) || defined(STM8S207) || defined(STM8S105)
  {0x82, (interrupt_handler_t)TIM3_UPD_OVF_BRK_IRQHandler}, /* irq15 - TIM3 Update/Overflow/Break interrupt */
  {0x82, (interrupt_handler_t)TIM3_CAP_COM_IRQHandler}, /* irq16 - TIM3 Capture/Compare interrupt */
#else
	{0x82, (interrupt_handler_t)NonHandledInterrupt}, /* irq15 - Reserved */
	{0x82, (interrupt_handler_t)NonHandledInterrupt}, /* irq16 - Reserved */
#endif /*STM8S208, STM8S207 or STM8S105*/
	
#ifdef STM8S105
	{0x82, (interrupt_handler_t)NonHandledInterrupt}, /* irq17 - Reserved */
	{0x82, (interrupt_handler_t)NonHandledInterrupt}, /* irq18 - Reserved */
#else
	{0x82, (interrupt_handler_t)UART1_TX_IRQHandler}, /* irq17 - UART1 Tx complete interrupt */
	{0x82, (interrupt_handler_t)UART1_RX_IRQHandler}, /* irq18 - UART1 Rx interrupt */
#endif /*STM8S105*/
	{0x82, (interrupt_handler_t)I2C_IRQHandler}, /* irq19 - I2C interrupt */

#if defined(STM8S208) || defined(STM8S207)

	{0x82, (interrupt_handler_t)UART3_TX_IRQHandler}, /* irq20 - UART3 Tx interrupt */
	{0x82, (interrupt_handler_t)UART3_RX_IRQHandler}, /* irq21 - UART3 Rx interrupt */
#elif defined (STM8S105)
	{0x82, (interrupt_handler_t)UART2_TX_IRQHandler}, /* irq20 - UART2 Tx interrupt */
	{0x82, (interrupt_handler_t)UART2_RX_IRQHandler}, /* irq21 - UART2 Rx interrupt */

#else /* STM8S103, STM8S903 */
	{0x82, (interrupt_handler_t)NonHandledInterrupt}, /* irq20 - Reserved */
	{0x82, (interrupt_handler_t)NonHandledInterrupt}, /* irq21 - Reserved */
#endif /* STM8S208, STM8S207 */

#if defined(STM8S208) || defined(STM8S207)
	{0x82, (interrupt_handler_t)ADC2_IRQHandler}, /* irq22 - ADC2 end of conversion interrupt */
#else /* STM8S105, STM8S103, STM8S903 */
	{0x82, (interrupt_handler_t)ADC1_IRQHandler}, /* irq22 - ADC1 end of conversion/Analog watchdog interrupts */

#endif /* STM8S208, STM8S207 */

#ifdef __TSL_TIMEBASE_H
	{0x82, (interrupt_handler_t)TSL_Timer_ISR}, /* irq23 */
#else
#if defined(STM8S903)
	{0x82, (interrupt_handler_t)TIM6_UPD_OVF_TRG_IRQHandler}, /* irq23 - TIM6 Update/Overflow interrupt */
#else /*STM8S208, STM8S207, STM8S105 or STM8S103*/
	{0x82, (interrupt_handler_t)TIM4_UPD_OVF_IRQHandler}, /* irq23 - TIM4 Update/Overflow interrupt */
#endif
#endif

	{0x82, (interrupt_handler_t)EEPROM_EEC_IRQHandler},  /* irq24 - FLASH interrupt */
	{0x82, (interrupt_handler_t)NonHandledInterrupt}, /* irq25 - Reserved */
	{0x82, (interrupt_handler_t)NonHandledInterrupt}, /* irq26 - Reserved */
	{0x82, (interrupt_handler_t)NonHandledInterrupt}, /* irq27 - Reserved */
	{0x82, (interrupt_handler_t)NonHandledInterrupt}, /* irq28 - Reserved */
	{0x82, (interrupt_handler_t)NonHandledInterrupt}, /* irq29 - Reserved */
};


/* Public functions ----------------------------------------------------------*/

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/

