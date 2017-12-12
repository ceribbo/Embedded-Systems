

/* 
 * File:   framework_adc12.h
 * Author: mgrundler
 *
 * Created on 28. Januar 2014, 19:41
 */

#ifndef FRAMEWORK_ADC12_H
#define	FRAMEWORK_ADC12_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <xc.h>
// TODO: Take care of AN45-AN49! These are not "real" Channels! Their values are stored inside AD1DATA0 - AD1DATA4, and even the Ready-Bits of AN0-AN4 are used!!!


#define AN0             0
#define AN1             1
#define AN2             2
#define AN3             3
#define AN4             4
#define AN5             5
#define AN6             6
#define AN7             7
#define AN8             8
#define AN9             9
#define AN10            10
#define AN11            11
#define AN12            12
#define AN13            13
#define AN14            14
#define AN15            15
#define AN16            16
#define AN17            17
#define AN18            18
#define AN19            19
#define AN20            20
#define AN21            21
#define AN22            22
#define AN23            23
#define AN24            24
#define AN25            25
#define AN26            26
#define AN27            27
#define AN28            28
#define AN29            29
#define AN30            30
#define AN31            31
#define AN32            32
#define AN33            33
#define AN34            34
#define AN35            35
#define AN36            36
#define AN37            37
#define AN38            38
#define AN39            39
#define AN40            40
#define AN41            41
#define AN42            42
#define AN43            43
#define AN44            44
#define AN45            45
#define AN46            46
#define AN47            47
#define AN48            48
#define AN49            49


/*
 *  adc12_Init()
 *
 *  Arguments:      NONE
 *
 *  Returnvalues:   NONE
 *
 *  Function:       Initializes and Calibrates the ADC12-Module for Channel-Scan-Mode
 *
 */
void adc12_Init();


/*
 *  adc12_ConfigPort(port)
 *
 *  Arguments:      port (AN0 - AN49)
 *
 *  Returnvalues:   NONE
 *
 *  Function:       Adds the given ANx-Port to the Channel-Scan-List
 *
 */
void adc12_ConfigPort(int port);


/*
 *  adc12_Enable()
 *
 *  Arguments:      NONE
 *
 *  Returnvalues:   NONE
 *
 *  Function:       Enables the ADC12-Module and waits until Module is ready
 *
 */
void adc12_Enable();



/*
 *  adc12_StartSampling()
 *
 *  Arguments:      NONE
 *
 *  Returnvalues:   NONE
 *
 *  Function:       Triggers a complete Channel-Scan
 *
 */
void adc12_StartSampling();



/*
 *  adc12_SampleReady(port)
 *
 *  Arguments:      port (AN0 - AN49)
 *
 *  Returnvalues:   0 - if Sample-Data for Port is NOT ready
 *                  1 - if Data is ready to use
 *
 *  Function:       Returns the State of the Sample-Conversation
 *
 */
int adc12_SampleReady(int port);


/*
 *  adc12_Wait(port)
 *
 *  Arguments:      port (AN0 - AN49)
 *
 *  Returnvalues:   NONE
 *
 *  Function:       Waits until the Sample-Conversation of the given Port is finished and the Data is ready
 *
 */
void adc12_Wait(int port);



/*
 *  adc12_GetSample(port)
 *
 *  Arguments:      port (AN0 - AN49)
 *
 *  Returnvalues:   sampledata
 *
 *  Function:       Returns the Sampled Data for the given Port (attention! make sure that the conversation is finished before getting the Data!)
 *
 */
unsigned int adc12_GetSample(int port);



/*
 *  adc12_Read(port)
 *
 *  Arguments:      port (AN0 - AN49)
 *
 *  Returnvalues:   sampledata
 *
 *  Function:       Starts Sampling of the whole List(!), waits until the given port-conversation is finished (and data is ready), returns the sampled data
 *
 */
unsigned int adc12_Read(int port);





#ifdef	__cplusplus
}
#endif

#endif	/* FRAMEWORK_ADC12_H */
