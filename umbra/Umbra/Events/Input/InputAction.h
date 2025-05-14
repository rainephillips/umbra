#pragma once

#include <cstdint>
#include <string>

using std::string;

enum class ValueTypes : uint8_t {
	DIGITAL,
	AXIS1D,
	AXIS2D,
	AXIS3D
};

enum class Flags : uint8_t {
	VALUE_TYPE = 0,
	TRIGGER_WHEN_GAME_PAUSED = 8,
	CONSUME_LOWER_INPUTS = 16
};

class InputAction
{
public:
	InputAction();
	~InputAction();

public:
	string& GetDescription();

private:
	uint8_t m_inputData;
	string m_description;

};

