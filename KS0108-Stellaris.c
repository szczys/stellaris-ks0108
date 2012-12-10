//-------------------------------------------------------------------------------------------------
// Universal KS0108 driver library
// Atmel AVR MCU low-level driver.
// (c) Rados�aw Kwiecie�, radek@dxp.pl
//-------------------------------------------------------------------------------------------------
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"

#define KS0108_DATA_PERIPH	SYSCTL_PERIPH_GPIOB
#define KS0108_DATA_PORT	GPIO_PORTB_BASE

#define KS0108_CTRL_PERIPH	SYSCTL_PERIPH_GPIOE
#define KS0108_CTRL_PORT	GPIO_PORTE_BASE

#define KS0108_RS			GPIO_PIN_0
#define KS0108_RW			GPIO_PIN_1
#define KS0108_EN			GPIO_PIN_2

#define KS0108_CS1			GPIO_PIN_3
#define KS0108_CS2			GPIO_PIN_4
#define KS0108_CS3			GPIO_PIN_4

extern unsigned char screen_x;
extern unsigned char screen_y;

#define DISPLAY_STATUS_BUSY	0x80

//-------------------------------------------------------------------------------------------------
// Delay function
//-------------------------------------------------------------------------------------------------
void GLCD_Delay(void)
{
  SysCtlDelay(450);
}
//-------------------------------------------------------------------------------------------------
// Enalbe Controller (0-2)
//-------------------------------------------------------------------------------------------------
void GLCD_EnableController(unsigned char controller)
{
switch(controller){
	case 0 : GPIOPinWrite(KS0108_CTRL_PORT, KS0108_CS1, 0x00); break;
	case 1 : GPIOPinWrite(KS0108_CTRL_PORT, KS0108_CS2, 0x00); break;
	case 2 : GPIOPinWrite(KS0108_CTRL_PORT, KS0108_CS3, 0x00); break;
	}
}
//-------------------------------------------------------------------------------------------------
// Disable Controller (0-2)
//-------------------------------------------------------------------------------------------------
void GLCD_DisableController(unsigned char controller)
{
switch(controller){
	case 0 : GPIOPinWrite(KS0108_CTRL_PORT, KS0108_CS1, 0xFF); GLCD_Delay(); break;
	case 1 : GPIOPinWrite(KS0108_CTRL_PORT, KS0108_CS2, 0xFF); GLCD_Delay(); break;
	case 2 : GPIOPinWrite(KS0108_CTRL_PORT, KS0108_CS3, 0xFF); GLCD_Delay(); break;
	}
}
//-------------------------------------------------------------------------------------------------
// Read Status from specified controller (0-2)
//-------------------------------------------------------------------------------------------------
unsigned char GLCD_ReadStatus(unsigned char controller)
{
  unsigned char status;
  GPIOPinTypeGPIOInput(KS0108_DATA_PORT, 0xFF);			//Set data pins as inputs
  GPIOPinWrite(KS0108_CTRL_PORT, KS0108_RW, 0xFF);		//Set RW high
  GPIOPinWrite(KS0108_CTRL_PORT, KS0108_RS, 0xFF);		//Set RS low
  GLCD_EnableController(controller);
  GPIOPinWrite(KS0108_CTRL_PORT, KS0108_EN, 0xFF); 		//Enable pin high
  GLCD_Delay();
  status = GPIOPinRead(KS0108_DATA_PORT, 0xFF);			//Read status from data port
  GPIOPinWrite(KS0108_CTRL_PORT, KS0108_EN, 0x00);		//Enable pin low
  GLCD_Delay();
  GLCD_DisableController(controller);
  return status;
}
//-------------------------------------------------------------------------------------------------
// Write command to specified controller
//-------------------------------------------------------------------------------------------------
void GLCD_WriteCommand(unsigned char commandToWrite, unsigned char controller)
{
  //while(GLCD_ReadStatus(controller)&DISPLAY_STATUS_BUSY);
  GPIOPinTypeGPIOOutput(KS0108_DATA_PORT, 0xFF); 		//Data pins as outputs
  GPIOPinWrite(KS0108_CTRL_PORT, KS0108_RS | KS0108_RW, 0x00);	//RS and RW Low
  GLCD_EnableController(controller);
  GPIOPinWrite(KS0108_DATA_PORT, 0xFF, commandToWrite);		//Write command to port
  GPIOPinWrite(KS0108_CTRL_PORT, KS0108_EN, 0xFF); 		//Enable pin high
  GLCD_Delay();
  GPIOPinWrite(KS0108_CTRL_PORT, KS0108_EN, 0x00); 		//Enable pin low
  GLCD_Delay();
  GLCD_DisableController(controller);
}
//-------------------------------------------------------------------------------------------------
// Read data from current position
//-------------------------------------------------------------------------------------------------
unsigned char GLCD_ReadData(void)
{
  unsigned char data;
  //while(GLCD_ReadStatus(screen_x / 64)&DISPLAY_STATUS_BUSY);
  GPIOPinTypeGPIOInput(KS0108_DATA_PORT, 0xFF);			//Set data pins as inputs
  GPIOPinWrite(KS0108_CTRL_PORT, KS0108_RS | KS0108_RW, 0xFF);	//Set RS and RW high
  GLCD_EnableController(screen_x / 64);
  //GLCD_Delay();	//This was commented out in the original code
  GPIOPinWrite(KS0108_CTRL_PORT, KS0108_EN, 0xFF); 		//Enable pin high
  GLCD_Delay();
  data = GPIOPinRead(KS0108_DATA_PORT, 0xFF);			//Read data from data port
  GPIOPinWrite(KS0108_CTRL_PORT, KS0108_EN, 0x00); 		//Enable pin low
  GLCD_DisableController(screen_x / 64);
  screen_x++;
  return data;
}
//-------------------------------------------------------------------------------------------------
// Write data to current position
//-------------------------------------------------------------------------------------------------
void GLCD_WriteData(unsigned char dataToWrite)
{
  //while(GLCD_ReadStatus(screen_x / 64)&DISPLAY_STATUS_BUSY);
  GPIOPinTypeGPIOOutput(KS0108_DATA_PORT, 0xFF); 		//Data pins as outputs
  GPIOPinWrite(KS0108_CTRL_PORT, KS0108_RW, 0x00);		//Set RW low
  GPIOPinWrite(KS0108_CTRL_PORT, KS0108_RS, 0xFF);		//Set RS high
  GPIOPinWrite(KS0108_DATA_PORT, 0xFF, dataToWrite);		//Write data to port
  GLCD_EnableController(screen_x / 64);
  GPIOPinWrite(KS0108_CTRL_PORT, KS0108_EN, 0xFF); 		//Enable pin high
  GLCD_Delay();
  GPIOPinWrite(KS0108_CTRL_PORT, KS0108_EN, 0x00); 		//Enable pin low
  GLCD_Delay();
  GLCD_DisableController(screen_x / 64);
  screen_x++;
}
//-------------------------------------------------------------------------------------------------
//
//-------------------------------------------------------------------------------------------------
void GLCD_InitalizePorts(void)
{
  //Enable peripheral clocks
  SysCtlPeripheralEnable(KS0108_DATA_PERIPH);
  SysCtlPeripheralEnable(KS0108_CTRL_PERIPH);

  //Set control pins as outputs
  GPIOPinTypeGPIOOutput(KS0108_CTRL_PORT, KS0108_RS | KS0108_RW | KS0108_EN | KS0108_CS1 | KS0108_CS2 | KS0108_CS3);

  //Set CS pins high
  GPIOPinWrite(KS0108_CTRL_PORT, KS0108_CS1 | KS0108_CS2 | KS0108_CS3, 0xFF);
}

void GLCD_Test(void){
  GPIOPinTypeGPIOOutput(KS0108_DATA_PORT, 0xFF); 		//Data pins as outputs
  GPIOPinWrite(KS0108_CTRL_PORT, KS0108_CS1 | KS0108_RS | KS0108_RW, 0x00);	//Set RS and RW low
  GPIOPinWrite(KS0108_DATA_PORT, 0xFF, 0b01000000); 		//Y address 0
  GPIOPinWrite(KS0108_CTRL_PORT, KS0108_EN, 0xFF); 		//Enable pin high
  GLCD_Delay();
  GPIOPinWrite(KS0108_CTRL_PORT, KS0108_EN, 0x00); 		//Enable pin low
  GLCD_Delay();
  GPIOPinWrite(KS0108_DATA_PORT, 0xFF, 0b10111000); 		//X address 0
  GPIOPinWrite(KS0108_CTRL_PORT, KS0108_EN, 0xFF); 		//Enable pin high
  GLCD_Delay();
  GPIOPinWrite(KS0108_CTRL_PORT, KS0108_EN, 0x00); 		//Enable pin low
  GLCD_Delay();
  GPIOPinWrite(KS0108_CTRL_PORT, KS0108_RS, 0xFF);		//Set RS high
  for (unsigned char i=0; i<8; i++) {
    GPIOPinWrite(KS0108_DATA_PORT, 0xFF, 0b10101010);
    GPIOPinWrite(KS0108_CTRL_PORT, KS0108_EN, 0xFF); 		//Enable pin high
    GLCD_Delay();
    GPIOPinWrite(KS0108_CTRL_PORT, KS0108_EN, 0x00); 		//Enable pin low
  }

}
//-------------------------------------------------------------------------------------------------
//
//-------------------------------------------------------------------------------------------------
unsigned char GLCD_ReadByteFromROMMemory(char * ptr)
{
  //FIXME: This needs to be ported for ARM
  //return pgm_read_byte(ptr);
  return 255;
}
//-------------------------------------------------------------------------------------------------
//
//-------------------------------------------------------------------------------------------------
