#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_ints.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "KS0108.h"

#include "skull.h"

int main(void)
{
  //Setup system clock
  SysCtlClockSet(SYSCTL_SYSDIV_5|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN);

  GLCD_Initalize();
  GLCD_ClearScreen();

  //Draw the Hackaday.com skull and wrenches
  GLCD_GoTo(0,0);
  for (unsigned char j=0; j<8; j++)
  {
    GLCD_GoTo(0,j);
    for (unsigned char i=0; i<64; i++)
    {
      GLCD_WriteData(skull[i+(j*64)]);
    }
  }

  while (1) { ;  }
}
