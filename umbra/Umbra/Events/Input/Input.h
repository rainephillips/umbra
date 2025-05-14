#pragma once

#include <cstdint>

enum class InputTriggers {
	UP,
	DOWN,
	RELEASED,
	PRESSED,
	MAX
};

enum struct InputType
{
	KEYBOARD,
	MOUSE,
	CONTROLLER,
	CONTROLLERAXIS
};

class Input
{
public:
	uint16_t inputData;
	InputType inputType;
	InputTriggers inputState;

public:
	Input(uint16_t key, InputType type, InputTriggers state);
};

