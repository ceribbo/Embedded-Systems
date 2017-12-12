/*******************************************************************************
  MPLAB Harmony Application Source File
  
  Company:
    Microchip Technology Inc.
  
  File Name:
    estado.c

  Summary:
    This file contains the source code for the MPLAB Harmony application.

  Description:
    This file contains the source code for the MPLAB Harmony application.  It 
    implements the logic of the application's state machine and it may call 
    API routines of other MPLAB Harmony modules in the system, such as drivers,
    system services, and middleware.  However, it does not call any of the
    system interfaces (such as the "Initialize" and "Tasks" functions) of any of
    the modules in the system or make any assumptions about when those functions
    are called.  That is the responsibility of the configuration-specific system
    files.
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2013-2014 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
 *******************************************************************************/
// DOM-IGNORE-END


// *****************************************************************************
// *****************************************************************************
// Section: Included Files 
// **********************#*******************************************************
// *****************************************************************************

#include "estado.h"
#include <stdio.h>
#include "adc12_framework.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the APP_Initialize function.
    
    Application strings and buffers are be defined outside this structure.
*/

ESTADO_DATA estadoData;



// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

/* TODO:  Add any necessary callback functions.
*/

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************


/* TODO:  Add any necessary local functions.
*/
int ledon(SYS_CMD_DEVICE_NODE* pCmdIO, int argc, char **argv){
        const void* cmdIoParam = pCmdIO->cmdIoParam;
           if(argc>1){
                int idx;
                char output [1024];
                for(idx=1;idx<argc;idx++){
                    int led= atoi(argv[idx]);
                    switch(led){
                        //get the LED number and switch it on
                        case 1:
                            //switch on led 1
                            SYS_PORTS_PinSet(PORTS_ID_0, PORT_CHANNEL_G,PORTS_BIT_POS_6);
                            estadoData.ledBlinking1 = false;
                            //disable the potentiometer automatic follow
                            estadoData.followBlinking1 = false;
                            estadoData.ledOn1 = true;
                            sprintf(output," LED %d Enciendido.\r\n", led);
                            break;
                        case 2:
                            //switch on led 2
                            SYS_PORTS_PinSet(PORTS_ID_0, PORT_CHANNEL_D,PORTS_BIT_POS_4);
                            estadoData.ledBlinking2 = false;
                            //disable the potentiometer automatic follow
                            estadoData.followBlinking2 = false;
                            estadoData.ledOn2 = true;
                            sprintf(output," LED %d Enciendido.\r\n", led);
                            break;
                        case 3:
                            //switch on led 3
                            SYS_PORTS_PinSet(PORTS_ID_0, PORT_CHANNEL_B,PORTS_BIT_POS_11);
                            estadoData.ledBlinking3 = false;
                            //disable the potentiometer automatic follow
                            estadoData.followBlinking3 = false;
                            estadoData.ledOn3 = true;
                            sprintf(output," LED %d Enciendido.\r\n", led);
                            break;
                        case 4:
                            //switch on led 4
                            SYS_PORTS_PinSet(PORTS_ID_0, PORT_CHANNEL_G,PORTS_BIT_POS_15);
                            estadoData.ledBlinking4 = false;
                            //disable the potentiometer automatic follow
                            estadoData.followBlinking4 = false;
                            estadoData.ledOn4 = true;
                            sprintf(output," LED %d Enciendido.\r\n", led);
                            break;
                        default:
                            sprintf(output," ERROR: el LED %d no es valido.\r\n",led);
                            break;
                    };
                    (*pCmdIO->pCmdApi->print)(cmdIoParam,output);
                }
            }else{
                (*pCmdIO->pCmdApi->print)(cmdIoParam," ERROR: tienes que indicar el numero del LED como parametro.\r\n");
            }
            return 0;
    }

int ledoff(SYS_CMD_DEVICE_NODE* pCmdIO, int argc, char **argv){
    const void* cmdIoParam = pCmdIO->cmdIoParam;
           if(argc>1){
                char output [1024];
                int idx;
                for(idx=1;idx<argc;idx++){
                    int led= atoi(argv[idx]);
                    switch(led){
                        //get the LED number and switch it off
                        case 1:
                            //switch off led 1
                            SYS_PORTS_PinClear(PORTS_ID_0, PORT_CHANNEL_G,PORTS_BIT_POS_6);
                            estadoData.ledBlinking1 = false;
                            //disable the potentiometer automatic follow
                            estadoData.followBlinking1 = false;
                            estadoData.ledOn1 = false;
                            sprintf(output," LED %d apgado.\r\n", led);
                            break;
                        case 2:
                            //switch off led 2
                            SYS_PORTS_PinClear(PORTS_ID_0, PORT_CHANNEL_D,PORTS_BIT_POS_4);
                            estadoData.ledBlinking2 = false;
                            //disable the potentiometer automatic follow
                            estadoData.followBlinking2 = false;
                            estadoData.ledOn2 = false;
                            sprintf(output," LED %d apgado.\r\n", led);
                            break;
                        case 3:
                            //switch off led 3
                            SYS_PORTS_PinClear(PORTS_ID_0, PORT_CHANNEL_B,PORTS_BIT_POS_11);
                            estadoData.ledBlinking3 = false;
                            //disable the potentiometer automatic follow
                            estadoData.followBlinking3 = false;
                            estadoData.ledOn3 = false;
                            sprintf(output," LED %d apgado.\r\n", led);
                            break;
                        case 4:
                            //switch off led 4
                            SYS_PORTS_PinClear(PORTS_ID_0, PORT_CHANNEL_G,PORTS_BIT_POS_15);
                            estadoData.ledBlinking4 = false;
                            //disable the potentiometer automatic follow
                            estadoData.followBlinking4 = false;
                            estadoData.ledOn4 = false;
                            sprintf(output," LED %d apgado.\r\n", led);
                            break;
                        default:
                            sprintf(output," ERROR: el LED %d no es valido.\r\n",led);
                            break;
                    };
                    (*pCmdIO->pCmdApi->print)(cmdIoParam,output);
                }
            }else{
                (*pCmdIO->pCmdApi->print)(cmdIoParam," ERROR: tienes que indicar el numero del LED como parametro.\r\n");
            }
            return 0;
    }
int led(SYS_CMD_DEVICE_NODE* pCmdIO, int argc, char **argv){
           if(argc>1){
                char output [1024];
                int idx;
                for(idx=1;idx<argc;idx++){
                    int led= atoi(argv[idx]);
                    switch(led){
                        //check for the led if it is ON, ON blinking or OFF
                        case 1:
                            //estado led 1
                            if (!estadoData.ledOn1){
                                sprintf(output," Estado LED %d: apagado.\r\n", led);
                            }else if (estadoData.ledBlinking1){
                                sprintf(output," Estado LED %d: encendido y parpeando cada %dms.\r\n", led,estadoData.blinkingTime1);
                            }else{
                                sprintf(output," Estado LED %d: encendido y no parpeando.\r\n", led);
                            }
                            break;
                        case 2:
                            //estado led 2
                            if (!estadoData.ledOn2){
                                sprintf(output," Estado LED %d: apagado.\r\n", led);
                            }else if (estadoData.ledBlinking2){
                                sprintf(output," Estado LED %d: encendido y parpeando cada %dms.\r\n", led,estadoData.blinkingTime2);
                            }else{
                                sprintf(output," Estado LED %d: encendido y no parpeando.\r\n", led);
                            }
                            break;
                        case 3:
                            //estado led 3
                            if (!estadoData.ledOn3){
                                sprintf(output," Estado LED %d: apagado.\r\n", led);
                            }else if (estadoData.ledBlinking3){
                                sprintf(output," Estado LED %d: encendido y parpeando cada %dms.\r\n", led,estadoData.blinkingTime3);
                            }else{
                                sprintf(output," Estado LED %d: encendido y no parpeando.\r\n", led);
                            }
                            break;
                        case 4:
                            //estado led 4
                            if (!estadoData.ledOn4){
                                sprintf(output," Estado LED %d: apagado.\r\n", led);
                            }else if (estadoData.ledBlinking4){
                                sprintf(output," Estado LED %d: encendido y parpeando cada %dms.\r\n", led,estadoData.blinkingTime4);
                            }else{
                                sprintf(output," Estado LED %d: encendido y no parpeando.\r\n", led);
                            }
                            break;
                        default:
                            sprintf(output," ERROR: el LED %d no es valido.\r\n",led);
                            break;
                    } 
                    const void* cmdIoParam = pCmdIO->cmdIoParam;
                    (*pCmdIO->pCmdApi->print)(cmdIoParam,output);
                }
            }else{
               const void* cmdIoParam = pCmdIO->cmdIoParam;
                (*pCmdIO->pCmdApi->print)(cmdIoParam," ERROR: tienes que indicar el numero del LED como parametro.\r\n");
            }
            return 0;
    }
int estado(SYS_CMD_DEVICE_NODE* pCmdIO, int argc, char **argv){
    //get status of buttons and send them
    bool bt1 = SYS_PORTS_PinRead(PORTS_ID_0,PORT_CHANNEL_A,PORTS_BIT_POS_4);
    bool bt2 = SYS_PORTS_PinRead(PORTS_ID_0,PORT_CHANNEL_A,PORTS_BIT_POS_5);
          
    char output [1024];
    sprintf(output," Boton 1 pulsado: %s.\n Boton 2 pulsado: %s.\r\n",
            bt1 ? "true" : "false",bt2 ? "true" : "false");
    
    const void* cmdIoParam = pCmdIO->cmdIoParam;
    (*pCmdIO->pCmdApi->print)(cmdIoParam,output);
    
    return 0;
}
int decimas(SYS_CMD_DEVICE_NODE* pCmdIO, int argc, char **argv){
    //get tenth of second passed and send them
    char output [1024];
    sprintf(output," Decimas de segundo pasados: %d.\r\n", estadoData.totalDecimas);
    const void* cmdIoParam = pCmdIO->cmdIoParam;
    (*pCmdIO->pCmdApi->print)(cmdIoParam,output);
    
    return 0;
}
int cuentas(SYS_CMD_DEVICE_NODE* pCmdIO, int argc, char **argv){
    //get values of button counters and send them
    char output [1024];
    sprintf(output," Boton 1: pulsado -> %d, sueltado -> %d.\n Boton 2: pulsado -> %d, sueltado -> %d.\r\n",
            estadoData.pressedBT1, estadoData.releasedBT1, estadoData.pressedBT2, estadoData.releasedBT2);
    const void* cmdIoParam = pCmdIO->cmdIoParam;
    (*pCmdIO->pCmdApi->print)(cmdIoParam,output);
    
    return 0;
}

int adc(SYS_CMD_DEVICE_NODE* pCmdIO, int argc, char **argv){
    //get value of adc and print it
    int n = adc12_Read(AN8);
    char output [1024];
    sprintf(output," El valor del potenciometro es: %d.\r\n", n);
    const void* cmdIoParam = pCmdIO->cmdIoParam;
    (*pCmdIO->pCmdApi->print)(cmdIoParam, output);
    
    return 0;
}

int parpadea(SYS_CMD_DEVICE_NODE* pCmdIO, int argc, char **argv){
    const void* cmdIoParam = pCmdIO->cmdIoParam;
    //set the blinkingTime to potentiometer value
    int time = adc12_Read(AN8);
    char output [1024];
           if(argc>1){
                int idx;
                for(idx=1;idx<argc;idx++){
                    int led= atoi(argv[idx]);
                    switch(led){
                        //for each led it must be set as blinking
                        case 1:
                            //disable the potentiometer automatic follow
                            estadoData.followBlinking1 = false;
                            //check if led 1 is already
                            if (!estadoData.ledBlinking1){
                                //switch on and blink led 1
                                SYS_PORTS_PinSet(PORTS_ID_0, PORT_CHANNEL_G,PORTS_BIT_POS_6);
                                estadoData.ledBlinking1 = true;
                                estadoData.blinkingTime1 = time;
                                estadoData.ledOn1 = true;
                                sprintf(output," Parpeando LED %d.\r\n", led);
                            }else{
                                sprintf(output," ERROR: el LED %d ya esta parpeando.\r\n", led);
                            }
                            break;
                        case 2:
                            //disable the potentiometer automatic follow
                            estadoData.followBlinking2 = false;
                            //check if led 2 is already
                            if (!estadoData.ledBlinking2){
                                //switch on and blink led 2
                                SYS_PORTS_PinSet(PORTS_ID_0, PORT_CHANNEL_D,PORTS_BIT_POS_4);
                                estadoData.ledBlinking2 = true;
                                estadoData.blinkingTime2 = time;
                                estadoData.ledOn2 = true;
                                sprintf(output," Parpeando LED %d.\r\n", led);
                            }else{
                                sprintf(output," ERROR: el LED %d ya esta parpeando.\r\n", led);
                            }
                            break;
                        case 3:
                            //disable the potentiometer automatic follow
                            estadoData.followBlinking3 = false;
                            //check if led 3 is already
                            if (!estadoData.ledBlinking3){
                                //switch on and blink led 3
                                SYS_PORTS_PinSet(PORTS_ID_0, PORT_CHANNEL_B,PORTS_BIT_POS_11);
                                estadoData.ledBlinking3 = true;
                                estadoData.blinkingTime3 = time;
                                estadoData.ledOn3 = true;
                                sprintf(output," Parpeando LED %d.\r\n", led);
                            }else{
                                sprintf(output," ERROR: el LED %d ya esta parpeando.\r\n", led);
                            }
                            break;
                        case 4:
                            //disable the potentiometer automatic follow
                            estadoData.followBlinking4 = false;
                            //check if led 4 is already
                            if (!estadoData.ledBlinking4){
                                //switch on and blink led 4
                                SYS_PORTS_PinSet(PORTS_ID_0, PORT_CHANNEL_G,PORTS_BIT_POS_15);
                                estadoData.ledBlinking4 = true;
                                estadoData.blinkingTime4 = time;
                                estadoData.ledOn4 = true;
                                sprintf(output," Parpeando LED %d.\r\n", led);
                            }else{
                                sprintf(output," ERROR: el LED %d ya esta parpeando.\r\n", led);
                            }
                            break;
                        default:
                            sprintf(output," ERROR: el LED %d no es valido.\r\n",led);
                            break;
                    }
                    (*pCmdIO->pCmdApi->print)(cmdIoParam,output);
                }
            }else{
                if (estadoData.ledBlinking1){
                    (*pCmdIO->pCmdApi->print)(cmdIoParam," LED 1 parpeando.\r\n");
                }
                if (estadoData.ledBlinking2){
                    (*pCmdIO->pCmdApi->print)(cmdIoParam," LED 2 parpeando.\r\n");
                }
                if (estadoData.ledBlinking3){
                    (*pCmdIO->pCmdApi->print)(cmdIoParam," LED 3 parpeando.\r\n");
                }
                if (estadoData.ledBlinking4){
                    (*pCmdIO->pCmdApi->print)(cmdIoParam," LED 4 parpeando.\r\n");
                }
            }
            return 0;
    }

int sigue(SYS_CMD_DEVICE_NODE* pCmdIO, int argc, char **argv){
    int time = adc12_Read(AN8);
    char output [1024];
    const void* cmdIoParam = pCmdIO->cmdIoParam;
           if(argc>1){
                int idx;
                for(idx=1;idx<argc;idx++){
                    int led= atoi(argv[idx]);
                    switch(led){
                        case 1:
                            //check if led 1 is already
                            if (!estadoData.ledBlinking1){
                                //switch on and blink led 1
                                SYS_PORTS_PinSet(PORTS_ID_0, PORT_CHANNEL_G,PORTS_BIT_POS_6);
                                estadoData.ledBlinking1 = true;
                                estadoData.blinkingTime1 = time;
                                estadoData.followBlinking1 = true;
                                estadoData.ledOn1 = true;
                                sprintf(output," Parpeando LED %d proporcionalmente al valor del potenciometro.\r\n", led);
                            }else{
                                sprintf(output," ERROR: el LED %d ya esta parpeando.\r\n", led);
                            }
                            break;
                        case 2:
                            //check if led 2 is already
                            if (!estadoData.ledBlinking2){
                                //switch on and blink led 2
                                SYS_PORTS_PinSet(PORTS_ID_0, PORT_CHANNEL_D,PORTS_BIT_POS_4);
                                estadoData.ledBlinking2 = true;
                                estadoData.blinkingTime2 = time;
                                estadoData.followBlinking2 = true;
                                estadoData.ledOn2 = true;
                                sprintf(output," Parpeando LED %d proporcionalmente al valor del potenciometro.\r\n", led);
                            }else{
                                sprintf(output," ERROR: el LED %d ya esta parpeando.\r\n", led);
                            }
                            break;
                        case 3:
                            //check if led 3 is already
                            if (!estadoData.ledBlinking3){
                                //switch on and blink led 3
                                SYS_PORTS_PinSet(PORTS_ID_0, PORT_CHANNEL_B,PORTS_BIT_POS_11);
                                estadoData.ledBlinking3 = true;
                                estadoData.blinkingTime3 = time;
                                estadoData.followBlinking3 = true;
                                estadoData.ledOn3 = true;
                                sprintf(output," Parpeando LED %d proporcionalmente al valor del potenciometro.\r\n", led);
                            }else{
                                sprintf(output," ERROR: el LED %d ya esta parpeando.\r\n", led);
                            }
                            break;
                        case 4:
                            //check if led 4 is already
                            if (!estadoData.ledBlinking4){
                                //switch on and blink led 4
                                SYS_PORTS_PinSet(PORTS_ID_0, PORT_CHANNEL_G,PORTS_BIT_POS_15);
                                estadoData.ledBlinking4 = true;
                                estadoData.blinkingTime4 = time;
                                estadoData.followBlinking4 = true;
                                estadoData.ledOn4 = true;
                                sprintf(output," Parpeando LED %d proporcionalmente al valor del potenciometro.\r\n", led);
                            }else{
                                sprintf(output," ERROR: el LED %d ya esta parpeando.\r\n", led);
                            }
                            break;
                        default:
                            sprintf(output," ERROR: el LED no es valido.\r\n");
                            break;
                    }
                    (*pCmdIO->pCmdApi->print)(cmdIoParam,output);
                }
            }else{
                if (estadoData.ledBlinking1){
                    (*pCmdIO->pCmdApi->print)(cmdIoParam," LED 1 parpeando.\r\n");
                }
                if (estadoData.ledBlinking2){
                    const void* cmdIoParam = pCmdIO->cmdIoParam;
                    (*pCmdIO->pCmdApi->print)(cmdIoParam," LED 2 parpeando.\r\n");
                }
                if (estadoData.ledBlinking3){
                    const void* cmdIoParam = pCmdIO->cmdIoParam;
                    (*pCmdIO->pCmdApi->print)(cmdIoParam," LED 3 parpeando.\r\n");
                }
                if (estadoData.ledBlinking4){
                    const void* cmdIoParam = pCmdIO->cmdIoParam;
                    (*pCmdIO->pCmdApi->print)(cmdIoParam," LED 4 parpeando.\r\n");
                }
            }
            return 0;
    }

    static const SYS_CMD_DESCRIPTOR    cmdTbl[]=
    {
        {"ledon",
        ledon,
        ": enciende el led indicado como parametro"},
        {"ledoff",
        ledoff,
        ": apaga el  led indicado como parametro"},
        {"led",
        led,
        ": informa el estado del led n"},
        {"estado",
        estado,
        ": devuelve una cadena que resume el estado actual de los dos botones"},
        {"decimas",
        decimas,
        ": escribe el numero de decimas de segundo desde el arranque del sistema"},
        {"cuentas",
        cuentas,
        ": imprime el valor de los contadores asociados a los botones"},
        {"adc",
        adc,
        ": devuelve el valor actual del convertidor analagico/digital asociado al potenciometro"},
        {"parpadea",
        parpadea,
        ": sin parametros indica que leds estan parpadeando. Con parametros indica los LEDS que tienen que palpear"},
        {"sigue",
        sigue,
        ": sin parametros indica que leds estan parpadeando. Con parametros la frecuencia de parpadeo se debe ajustar continuamente al valor del potenciometro."},
    };

    bool APP_AddCommandFunction()
    {
        if (!SYS_CMD_ADDGRP(cmdTbl, sizeof(cmdTbl)/sizeof(*cmdTbl),
                        "LEDs", ": para encender y apagar los Leds"))
        {
            return false;
        }
        return true;
    }


// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void ESTADO_Initialize ( void )

  Remarks:
    See prototype in estado.h.
 */

void ESTADO_Initialize ( void )
{
    /* Place the App state machine in its initial state. */
    estadoData.state = ESTADO_STATE_INIT;

    
    /* TODO: Initialize your application's state machine and other
     * parameters.
     */
    
    //on/off variables for LEDs
    estadoData.ledOn1 = false;
    estadoData.ledOn2 = false;
    estadoData.ledOn3 = false;
    estadoData.ledOn4 = false;

    //blinking variables for LEDs 
    estadoData.ledBlinking1 = false,
    estadoData.ledBlinking2 = false,
    estadoData.ledBlinking3 = false,
    estadoData.ledBlinking4 = false;
    
    //timeout variables for LEDs 
    estadoData.blinkingTime1 = 0;
    estadoData.blinkingTime2 = 0;
    estadoData.blinkingTime3 = 0;
    estadoData.blinkingTime4 = 0;
    
    estadoData.timeoutLed1 = 0;
    estadoData.timeoutLed1 = 0;
    estadoData.timeoutLed1 = 0;
    estadoData.timeoutLed1 = 0;
    
    //timeout variables for LEDs 
    estadoData.followBlinking1 = false;
    estadoData.followBlinking2 = false;
    estadoData.followBlinking3 = false;
    estadoData.followBlinking4 = false;

    //variables for Button counter
    estadoData.pressedBT1 = 0;
    estadoData.releasedBT1 = 0;
    estadoData.pressedBT2 = 0;
    estadoData.releasedBT2 = 0;
    estadoData.stateBT1 = false;
    estadoData.stateBT2 = false;
    estadoData.wait1 = 0;
    estadoData.wait2 = 0;
    
    //variables for timer
    estadoData.decimasTimer = 0;
    estadoData.totalDecimas = 0;

}


/******************************************************************************
  Function:
    void ESTADO_Tasks ( void )

  Remarks:
    See prototype in estado.h.
 */

void APP_TimerCallback (uintptr_t context, uint32_t alarmCount ){
    
    //counter for tenth of seconds
    if (estadoData.decimasTimer >= 100) {
        //100 milliseconds have passed
        estadoData.totalDecimas ++;
        estadoData.decimasTimer = 0;
    }else{
        estadoData.decimasTimer ++;
    }
    
    int value = adc12_Read(AN8);
    
    if (estadoData.ledBlinking1)    {
        //if on of the timeoutLed variable reaches 0 it's time to blink!
        if (estadoData.timeoutLed1 <=0){
            estadoData.state = ESTADO_STATE_BLINK;
        }else{
            estadoData.timeoutLed1 --;
        }
        
        //check if we need to follow the potentiometer while blinking for each variable
        if (estadoData.followBlinking1)  {
            //check if value potentiometer value has changed value with at least +-10 difference
            if ((value > (estadoData.blinkingTime1 + 10)) || (value <(estadoData.blinkingTime1 -10)))  {
                estadoData.blinkingTime1 = value;
            }
        }
    }
    
    if (estadoData.ledBlinking1)    {
        if (estadoData.timeoutLed2 <=0){
            estadoData.state = ESTADO_STATE_BLINK;
        }else{
            estadoData.timeoutLed2 --;
        }
        
        if (estadoData.followBlinking2)  {
            if ((value > (estadoData.blinkingTime2 + 10)) || (value <(estadoData.blinkingTime2 -10)))  {
                estadoData.blinkingTime2 = value;
            }
        }
    }
    
    if (estadoData.ledBlinking1)    {
        if (estadoData.timeoutLed3 <=0){
            estadoData.state = ESTADO_STATE_BLINK;
        }else{
            estadoData.timeoutLed3 --;
        }
        
        if (estadoData.followBlinking3)  {
            if ((value > (estadoData.blinkingTime3 + 10)) || (value <(estadoData.blinkingTime3 -10)))  {
                estadoData.blinkingTime3 = value;
            }
        }
    }
    
    if (estadoData.ledBlinking1)    {
        if (estadoData.timeoutLed4 <=0){
            estadoData.state = ESTADO_STATE_BLINK;
        }else{
            estadoData.timeoutLed4 --;
        }
    
        if (estadoData.followBlinking4)  {
            if ((value > (estadoData.blinkingTime4 + 10)) || (value <(estadoData.blinkingTime4 -10)))  {
                estadoData.blinkingTime4 = value;
            }
        }
    }
}

void ESTADO_Tasks ( void )
{

    /* Check the application's current state. */
    switch ( estadoData.state )
    {
        /* Application's initial state. */
        case ESTADO_STATE_INIT:
        {
            bool appInitialized = true;
       
        
            if (appInitialized)
            {
                //initialize pins
                SYS_PORTS_PinSet(PORTS_ID_0, PORT_CHANNEL_G,PORTS_BIT_POS_6);
                SYS_PORTS_PinClear(PORTS_ID_0, PORT_CHANNEL_D,PORTS_BIT_POS_4);
                SYS_PORTS_PinClear(PORTS_ID_0, PORT_CHANNEL_B,PORTS_BIT_POS_11);
                SYS_PORTS_PinClear(PORTS_ID_0, PORT_CHANNEL_G,PORTS_BIT_POS_15);
                
                //1st pin need to be blink 
                estadoData.ledOn1 = true;
                estadoData.ledBlinking1 = true;
                estadoData.blinkingTime1 = 1000;
                estadoData.timeoutLed1 = estadoData.blinkingTime1;
                
                //1 milliseconds timer start
                estadoData.tmrDrvHandle = DRV_TMR_Open(DRV_TMR_INDEX_0, DRV_IO_INTENT_EXCLUSIVE);
                if (estadoData.tmrDrvHandle != DRV_HANDLE_INVALID)  {
                    uint32_t desiredFrequency = 1000 ; // 1000 hertz
                    uint32_t actualFrequency = DRV_TMR_CounterFrequencyGet(estadoData.tmrDrvHandle) ;
                    uint32_t divider = actualFrequency/desiredFrequency; // calculate divider value

                    DRV_TMR_AlarmRegister(estadoData.tmrDrvHandle, divider, true, 0, APP_TimerCallback);
                    DRV_TMR_Start(estadoData.tmrDrvHandle);
                }
                
                
                //command function start
                APP_AddCommandFunction();
                
                //initialize the potentiometer 
                adc12_Init();
                adc12_ConfigPort(AN8);
                adc12_Enable();
                adc12_StartSampling();
                
                //change state to blink
                estadoData.state = ESTADO_STATE_BLINK;
                
            }
            break;
        }

        case ESTADO_STATE_BLINK:
        {
            //blink all LEDs
            if (estadoData.ledBlinking1 && estadoData.ledOn1 && estadoData.timeoutLed1==0)   {
                SYS_PORTS_PinToggle(PORTS_ID_0, PORT_CHANNEL_G,PORTS_BIT_POS_6);
                //reset blinking 1 timer
                estadoData.timeoutLed1 = estadoData.blinkingTime1;
            }
            if (estadoData.ledBlinking2 && estadoData.ledOn2 && estadoData.timeoutLed2==0)   {
                SYS_PORTS_PinToggle(PORTS_ID_0, PORT_CHANNEL_D,PORTS_BIT_POS_4);
                //reset blinking 2 timer
                estadoData.timeoutLed2 = estadoData.blinkingTime2;
            }
            if (estadoData.ledBlinking3 && estadoData.ledOn3 && estadoData.timeoutLed3==0)   {
                SYS_PORTS_PinToggle(PORTS_ID_0, PORT_CHANNEL_B,PORTS_BIT_POS_11);
                //reset blinking 3 timer
                estadoData.timeoutLed3 = estadoData.blinkingTime3;
            }
            if (estadoData.ledBlinking4 && estadoData.ledOn4 && estadoData.timeoutLed4==0)   {
                SYS_PORTS_PinToggle(PORTS_ID_0, PORT_CHANNEL_G,PORTS_BIT_POS_15);
                //reset blinking 4 timer
                estadoData.timeoutLed4 = estadoData.blinkingTime4;
            }
            
            //change state to wait
            estadoData.state = ESTADO_STATE_WAIT;
            break;
        }
        
        case ESTADO_STATE_WAIT:
        {
            //wait
            
            //check button 1
            if (estadoData.wait1 == 0)  {
                if (SYS_PORTS_PinRead(PORTS_ID_0,PORT_CHANNEL_A,PORTS_BIT_POS_4)){
                    //button 1 pressed
                    if (estadoData.stateBT1 == false)   {
                        //change state LED 2
                        estadoData.ledOn2 = !estadoData.ledOn2;
                        estadoData.ledBlinking2 = false;
                        estadoData.followBlinking2 = false;
                        SYS_PORTS_PinToggle(PORTS_ID_0, PORT_CHANNEL_D,PORTS_BIT_POS_4);

                        //counter
                        estadoData.pressedBT1++;
                        estadoData.stateBT1 = true;
                        estadoData.wait1 = 5;
                    }
                }else{
                    //BT1 not pressed
                    if (estadoData.stateBT1 == true)    {
                        estadoData.releasedBT1++;
                        estadoData.stateBT1 = false;
                    }
                }
            }
            if (estadoData.wait1 > 0) estadoData.wait1--;
            
            //check button 2
            if (estadoData.wait2 == 0)  {
                if (SYS_PORTS_PinRead(PORTS_ID_0,PORT_CHANNEL_A,PORTS_BIT_POS_5)){
                    //button 1 pressed
                    if (estadoData.stateBT2 == false)   {

                        //counter
                        estadoData.pressedBT2++;
                        estadoData.stateBT2 = true;
                        estadoData.wait2 = 5;
                    }
                }else{
                    //BT2 not pressed
                    if (estadoData.stateBT2 == true)    {
                        estadoData.releasedBT2++;
                        estadoData.stateBT2 = false;
                    }
                }
            }
            if (estadoData.wait2 > 0) estadoData.wait2--;
            
            //ready to read command
            SYS_CMD_READY_TO_READ();
            
            break;
        }

        /* TODO: implement your application state machine.*/
        

        /* The default state should never be executed. */
        default:
        {
            /* TODO: Handle error in application's state machine. */
            break;
        }
    }
}

 

/*******************************************************************************
 End of File
 */
