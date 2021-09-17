#include "Keypad_Pin.h"


/*============================================================================*/
/* Component_Prototype */
/*============================================================================*/
const Arduino_Analogic_Input_Pin_5 Keypad_Pin = {
    /* Configuration_Parameter */
    /* uint8_t Arduino_Pin_Id */
    PIN_A0
};


/*============================================================================*/
/* Realized interfaces */
/*============================================================================*/
static void Keypad_Pin__Analogic_Pin__Get_Voltage( 
    T_Voltage_5* voltage )
{
    Arduino_AIP5__Pin__Get_Voltage(
        &Keypad_Pin,
        voltage );
}
const Analogic_Input_5 Keypad_Pin__Analogic_Pin =
{
    Keypad_Pin__Analogic_Pin__Get_Voltage
};