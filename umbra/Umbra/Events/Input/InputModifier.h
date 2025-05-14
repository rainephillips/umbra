#pragma once
enum class InputModifiers {
	NONE,
	NEGATE,
	SWIZZLE
};

class InputModifier
{
public:
	InputModifier();
	~InputModifier();

public:
	void Modify();


};