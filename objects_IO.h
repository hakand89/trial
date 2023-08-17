#ifndef OBJECTS_IO_H
#define OBJECTS_IO_H

#include "stdbool.h"
#include "stdint.h"


#define OBJ_ACTIVE_HIGH 0X0001U /*Pin active high macro*/
#define OBJ_ACTIVE_LOW 0X0000U /*Pin active low macro*/

#define Output 1 /*Pin output macro*/
#define Input 0 /*Pin input macro*/
#define Bidirectional 3 /*Pin bidirection macro*/

#define Total_Function_Count 11
#define Total_Pin_Count 11

/**
*   Digital I_0 Error codes Enum.
*/
typedef enum {
    IO_OBJ_ERR_SUCCESS = 0x0000,
    IO_OBJ_ERROR_NO_INDEX = 0x0002,
    IO_OBJ_ERROR_NO_SUB_INDEX = 0x0004,
    IO_OBJ_ERROR_WRITEONLY = 0x0008,
    IO_OBJ_ERROR_READONLY = 0x00010,
    IO_OBJ_ERROR_NULL_PARAM = 0x00020,
    IO_OUT_OF_BOUNDARY = 0x00040,
    IO_FUNCTION_NUMBER_UNDEFINED = 0x00080,
} IO_Obj_Error_Code;

typedef struct {
    uint8_t bounce_filter_value; /* If It is input */
    uint8_t bounce_filter_counter;
} bounce_filter_t;
/**
*   Digital I_0 Object structures that holds
*   properties and data of the Assigned Function
*/
typedef struct {
    bool direction; /* Partially configurable */
    bool active_high; /* Configurable  */
    bool data_shadow;
    bool data;
    bool active_state;
    uint32_t count;
    uint32_t databuffer;
    bounce_filter_t bounce_filter;
    uint8_t function_number;
    void (*signal)();
      bool initialised;
} function_IO_object_t;

typedef struct {
    function_IO_object_t Ready;
    function_IO_object_t Malfunction;
    function_IO_object_t Speed_Reach;
    function_IO_object_t Zero_Speed_Detection;
    function_IO_object_t Servo_On;
    function_IO_object_t Reset;
    function_IO_object_t Forward_Rotation_Stroke_End;
    function_IO_object_t Reverse_Rotation_Stroke_End;
    function_IO_object_t Analog_Torque_Limit_Enable;
    function_IO_object_t Analog_Speed_Limit_Enable;
    function_IO_object_t CCW_CW_Rotation;
} functions_object_t;
/**
*   Digital I_0 PIN Object structure that holds
*   properties and data of the Pin
*   Data read from the pin and the final data to pass
*   to the pin
*/

typedef struct
    {
    uint8_t direction_capability; /* Hardware limitation for config. Inpu/ Output or Both */
    uint8_t port_number;
    uint8_t pin_number;
//    const DIGITAL_IO_t* mcu_pin;
} pin_driver_t;

typedef struct
    {
    bool data;
    function_IO_object_t* function;
    uint8_t function_number;
} pin_software_t;

typedef struct
    {
    pin_driver_t   pin_driver;
    pin_software_t pin_software;
} pin_object_t;

/**
*  Digital I_0 Functions Definitons
*  Ready -DIGITAL OUT
*  Malfunction -DIGITAL OUT
*  Speed_Reach -DIGITAL OUT
*  Zero_Speed_Detection -DIGITAL OUT
*  Servo_On -DIGITAL IN
*  Reset  -DIGITAL IN
*  Forward_Rotation_Stroke_End -DIGITAL IN
*  Reverse_Rotation_Stroke_End -DIGITAL IN
*  Analog_Torque_Limit_Enable  -DIGITAL IN
*  Analog_Speed_Limit_Enable   -DIGITAL IN
*  CCW_CW_Rotation    -DIGITAL IN
*/

extern functions_object_t Servo_IO_Function;

/*   Initialisation of I_O Function */
IO_Obj_Error_Code init_Digital_IO(void);

/*   Functions that sets related Functions situation */
IO_Obj_Error_Code set_Digital_IO(function_IO_object_t* function, bool value);

/*   Periodically Update Outputs/ Get Inputs  Function  */
IO_Obj_Error_Code update_Digital_IO(function_IO_object_t* function);
/*   Functions that gets related Functions' situation */

/*   Periodically Update Outputs/ Get Inputs  Function  */
IO_Obj_Error_Code get_Digital_IO(function_IO_object_t* function);

/*   Set Active State of the related function  */
IO_Obj_Error_Code set_active_state(bool active_state, function_IO_object_t* function );


IO_Obj_Error_Code connect_pin_and_functions(pin_object_t* pin_group_number, function_IO_object_t* function_number);

IO_Obj_Error_Code connect(uint8_t pin_number, uint8_t function_number);

extern void (*array[4])();

 IO_Obj_Error_Code   init_pins(pin_object_t* pin);

void init_mcu_pins(void);

#endif // OBJECTS_IO_H
