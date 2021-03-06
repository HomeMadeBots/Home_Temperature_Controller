#include "Boiler_Manager.h"

#include <stddef.h>


/* Required Component_Prototypes */
/* Clock_Data */
#include "HTC_Clock.h"

/* Mesured_Temperature */
#include "Air_Temperature_Sensor.h"

/* Relay_Cmd */
#include "Boiler_Relay_Actuator.h"

/* Mode */
#include "Mode_Manager.h"


/*============================================================================*/
/* Component_Prototype */
/*============================================================================*/
static const Turn_On_Off_Delay Anti_Bounce_Delay;

static void Delay_Timer__Time_Is_Up( void )
{
    Delay__Timer_Is_Up( (Delay*)&Anti_Bounce_Delay );
}

static Triggered_Timer_Var Delay_Timer_Var = 
{
    /* uint32_t Counter */
    0
};

const Triggered_Timer Delay_Timer =
{
    /* Variable attributes */
    &Delay_Timer_Var,

    /* Sent events */
    /* Time_Is_Up */
    Delay_Timer__Time_Is_Up,

    /* Constants attributes */
    /* uint32_t Recurrence_Millisecond */
    1000
};

static Turn_On_Off_Delay_Var Anti_Bounce_Delay_Var =
{
    /* Inheritance */
    {
        /* Is_Output_On:bool */
        false
    },
    
    /* Is_Input_On:bool */
    false
};

static const Turn_On_Off_Delay Anti_Bounce_Delay =
{
    /* Inheritance */
    {
        /* Variable attributes */
        (Delay_Var*)&Anti_Bounce_Delay_Var,

        /* Virtual operations */
        &Turn_On_Off_Delay_Operations,
    
        /* Sent events */
        /* Delay_Is_Up */
        NULL,
    
        /* Associated objects */
        /* Class_Triggered_Timer* My_Timer */
        &Delay_Timer,

        /* Constants attributes */
        /* uint32_t Delay_Duration:uint32_t */
        120000
    },

    /* Configuration_Parameters */
    /* Off_Delay_Duration:uint32_t */
    30000
};

static Boiler_Manager_Class_Var Boiler_Manager_Attr =
{
    /* T_Ambient_Air_Temperature Low_Temperature */
    TEMPERATURE_18_DEG_CELCIUS,
    /* T_Ambient_Air_Temperature High_Temperature */
    TEMPERATURE_20_DEG_CELCIUS,
    /* T_Ambient_Air_Temperature Targeted_Temperature */
    TEMPERATURE_18_DEG_CELCIUS
};

const Boiler_Manager_Class Boiler_Manager =
{
    /* Variable attributes */
    &Boiler_Manager_Attr,
    
    /* Required interfaces */
    /* Clock:Clock_Data */
    &HTC_Clock__Data,
    /* Mesured_Temperature:Ambient_Air_Temperature */
    &Air_Temp_Sens__Air_Temperature,
    /* Relay_Cmd:Relay_Actuation_Requests */
    &Boiler_Relay_Actuator__Relay_Actuation,
    /* Mode HTC_Mode */
    &Mode_Mgr__Operating_Mode,

    /* Inner objects */
    /* Triggered_Timer* Anti_Bounce_Timer */
    &Anti_Bounce_Delay
};


/*============================================================================*/
/* Realized interfaces */
/*============================================================================*/
const Target_Home_Temperatures_Setting Boiler_Manager__Temperatures_Setting =
{
    Boiler_Mgr_Class__Temperatures_Setting__Increase_Low_Temperature,
    Boiler_Mgr_Class__Temperatures_Setting__Decrease_Low_Temperature,
    Boiler_Mgr_Class__Temperatures_Setting__Increase_High_Temperature,
    Boiler_Mgr_Class__Temperatures_Setting__Decrease_High_Temperature
};
/*----------------------------------------------------------------------------*/
const Target_Home_Temperatures Boiler_Manager__Temperatures =
{
    Boiler_Mgr_Class__Temperatures__Get_High_Temperature,
    Boiler_Mgr_Class__Temperatures__Get_Low_Temperature
};