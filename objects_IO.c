
#include "objects_IO.h"
const uint32_t bounce_truth_table[21] = { 0x00, 0x01, 0x03, 0x07, 0x0F, 0x1F, 0x3F, 0x7F, 0xFF, 0x1FF, 0x3FF, 0x7FF, 0xFFF, 0x1FFF, 0x3FFF, 0x7FFF, 0xFFFF, 0x1FFFF, 0x3FFFF, 0x7FFFF, 0xFFFFF };
functions_object_t Servo_IO_Function = {
    { Output, OBJ_ACTIVE_HIGH, 0, 0, 0, 0, 0, { 0, 0 }, 0, 0 , 1},
    { Output, OBJ_ACTIVE_HIGH, 0, 0, 0, 0, 0, { 0, 0 }, 1, 0 , 1},
    { Output, OBJ_ACTIVE_HIGH, 0, 0, 0, 0, 0, { 0, 0 }, 2, 0 , 1},
    { Output, OBJ_ACTIVE_HIGH, 0, 0, 0, 0, 0, { 0, 0 }, 3, 0 , 1},
    { Input, OBJ_ACTIVE_LOW, 0, 0, 0, 0, 0, { 0, 0 }, 4, 0 , 1},
    { Input, OBJ_ACTIVE_LOW, 0, 0, 0, 0, 0, { 0, 0 }, 5, 0 , 1},
    { Input, OBJ_ACTIVE_LOW, 0, 0, 0, 0, 0, { 0, 0 }, 6, 0 , 1},
    { Input, OBJ_ACTIVE_LOW, 0, 0, 0, 0, 0, { 0, 0 }, 7, 0 , 1},
    { Input, OBJ_ACTIVE_LOW, 0, 0, 0, 0, 0, { 0, 0 }, 8, 0 , 1},
    { Input, OBJ_ACTIVE_LOW, 0, 0, 0, 0, 0, { 0, 0 }, 9, 0 , 1},
    { Input, OBJ_ACTIVE_LOW, 0, 0, 0, 0, 0, { 0, 0 }, 10, 0 , 1},
};

function_IO_object_t* functions[] = {
    &Servo_IO_Function.Ready,
    &Servo_IO_Function.Malfunction,
    &Servo_IO_Function.Speed_Reach,
    &Servo_IO_Function.Servo_On,
    &Servo_IO_Function.Reset,
    &Servo_IO_Function.Forward_Rotation_Stroke_End,
    &Servo_IO_Function.Reverse_Rotation_Stroke_End,
    &Servo_IO_Function.Analog_Torque_Limit_Enable,
    &Servo_IO_Function.Analog_Torque_Limit_Enable,
    &Servo_IO_Function.Analog_Speed_Limit_Enable,
    &Servo_IO_Function.CCW_CW_Rotation
};

pin_object_t pins[11];
pin_object_t* pin[] = {
    &pins[0],
    &pins[1],
    &pins[2],
    &pins[3],
    &pins[4],
    &pins[5],
    &pins[6],
    &pins[7],
    &pins[8],
    &pins[9],
    &pins[10],
    &pins[11],
};
/**
 * Function to Initialise MCU Pins and I_O Functions
 * Reads Eeprom to get pin&function properties
 */

IO_Obj_Error_Code init_Digital_IO()
{
    IO_Obj_Error_Code err;
    err = IO_OBJ_ERR_SUCCESS;
    /* Read Eeprom for config*/

    /* Initialise Pin structure */
    set_active_state(OBJ_ACTIVE_HIGH,  functions[0]);
    set_active_state(OBJ_ACTIVE_HIGH,  functions[1]);
    set_active_state(OBJ_ACTIVE_HIGH,  functions[2]);
    set_active_state(OBJ_ACTIVE_HIGH,  functions[3]);
    set_active_state(OBJ_ACTIVE_HIGH,  functions[4]);
    set_active_state(OBJ_ACTIVE_HIGH,  functions[5]);
    set_active_state(OBJ_ACTIVE_HIGH,  functions[6]);
    set_active_state(OBJ_ACTIVE_HIGH,  functions[7]);
    set_active_state(OBJ_ACTIVE_HIGH,  functions[8]);
    set_active_state(OBJ_ACTIVE_HIGH,  functions[9]);
    set_active_state(OBJ_ACTIVE_HIGH,  functions[10]);


    pins[0].pin_software.data=0;
    pins[1].pin_software.data=0;
    pins[2].pin_software.data=0;
    pins[3].pin_software.data=0;



}


IO_Obj_Error_Code set_active_state(bool active_state, function_IO_object_t* function )
{
    IO_Obj_Error_Code err;
    if (function == 0 /*NULL*/)
        err = IO_OBJ_ERROR_NULL_PARAM;

        if(!function->initialised){
         err=IO_FUNCTION_NUMBER_UNDEFINED;
        }
        else{
    function->active_high = active_state;
    err = IO_OBJ_ERR_SUCCESS;
        }
    return err;
}

