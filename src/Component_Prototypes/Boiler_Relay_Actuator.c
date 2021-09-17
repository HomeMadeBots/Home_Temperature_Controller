#include "Boiler_Relay_Actuator.h"


/* Required Component_Prototypes */
#include "Boiler_Relay_Pin.h"


/*============================================================================*/
/* Component_Prototype */
/*============================================================================*/
const Relay_Actuator Boiler_Relay_Actuator = {

    /* Required interfaces */
    /* Discrete_Pin:Discrete_Output */
    &Boiler_Relay_Pin__Discrete_Pin,
    
    /* Configuration_Parameter */
    /* Relay_Configuration:E_Relay_Configuration */
    MONOSTABLE_RELAY_NORMALLY_OPEN
};


/*============================================================================*/
/* Realized interfaces */
/*============================================================================*/
static void Boiler_Relay_Actuator__Relay_Actuation__Close_Circuit( void )
{
    Relay_Actuator__Relay_Actuation__Close_Circuit( &Boiler_Relay_Actuator );
}
static void Boiler_Relay_Actuator__Relay_Actuation__Open_Circuit( void )
{
    Relay_Actuator__Relay_Actuation__Open_Circuit( &Boiler_Relay_Actuator );
}
const Relay_Actuation_Requests Boiler_Relay_Actuator__Relay_Actuation =
{
    Boiler_Relay_Actuator__Relay_Actuation__Close_Circuit,
    Boiler_Relay_Actuator__Relay_Actuation__Open_Circuit
};