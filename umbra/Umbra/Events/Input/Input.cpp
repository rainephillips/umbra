#include "Input.h"

Input::Input(uint16_t key, InputType type, InputTriggers state)
	: inputData( key ), inputType( type ), inputState( state )
{
}
