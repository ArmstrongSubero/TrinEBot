/**
  Generated main.c file from MPLAB Code Configurator

  @Company
    Microchip Technology Inc.

  @File Name
    main.c

  @Summary
    This is the generated main.c using PIC24 / dsPIC33 / PIC32MM MCUs.

  @Description
    This source file provides main entry point for system initialization and application code development.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.125
        Device            :  PIC24FJ128GB204
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.36B
        MPLAB 	          :  MPLAB X v5.20
*/

/*
    (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

/**
  Section: Included Files
*/
#include "mcc_generated_files/system.h"
#include "mcc_generated_files/mcc.h"

/*
                         Main application
 */

////////////////////////
// Buzzer
////////////////////////
#define BUZZER LATAbits.LATA9


//////////////////////
// Motor Control
//////////////////////
#define leftForwardEnable  = OFF;
#define rightForwardEnable = OFF;
#define leftReverseEnable  = OFF;
#define rightReverseEnable = OFF;

void left_Forward();
void left_Stop();


void left_Backward();
void right_Forward();
void right_Backward();
void move_Forward();
void move_Backward();
void move_Left();
void move_Right();
void all_MotorsStop();
void all_MotorsEnable();
void all_MotorsInitialize();


//////////////////////
// Encoders
//////////////////////
volatile int leftEncoder_A;
volatile int leftEncoder_B;
volatile int rightEncoder_A;
volatile int rightEncoder_B;


int main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    
    // Buzzer output
    TRISAbits.TRISA9 = OUTPUT;
    
    all_MotorsStop();
    __delay_ms(500);
    
    all_MotorsInitialize();
    
    left_Stop();
    
    while(1)
    {
      left_Forward();
      __delay_ms(500);
      left_Stop();
      
       left_Backward();
      __delay_ms(500);
      left_Stop();
      
      printf("Right: %d\t Left: %d\n", rightEncoder_B, leftEncoder_B);
      __delay_ms(100);
    }

    return 1;
}



void left_Forward()
{
    OC1_Start();
    OC2_Stop();
}

void left_Backward()
{
    OC1_Stop();
    OC2_Start();
}


void left_Stop()
{
    OC1_Stop();
    OC2_Stop();
    __delay_ms(500);
}


void right_Forward()
{
    OC3_Start();
    OC4_Stop();
}


void right_Backward()
{
    OC3_Stop();
    OC4_Start(); 
}


void right_Stop()
{
    OC3_Stop();
    OC4_Stop();
    __delay_ms(500);
}


void move_Forward()
{
    left_Forward();
    right_Forward();
}

void move_Backward()
{
    left_Backward();
    right_Backward();
    
}

void move_Left()
{
    left_Backward();
    right_Forward();
    
}

void move_Right()
{
    right_Backward();
    left_Forward(); 
}

void all_MotorsStop()
{
    // Initial PWM state
    OC1_Stop();
    OC2_Stop();
    OC3_Stop();
    OC4_Stop();
}

void all_MotorsEnable()
{
    
}

void all_MotorsInitialize()
{
    OC1_Start();
    OC2_Start();
    OC3_Start();
    OC4_Start(); 
    
    OC1_Stop();
    OC2_Stop();
    OC3_Stop();
    OC4_Stop(); 
}

/*
 End of File
*/

