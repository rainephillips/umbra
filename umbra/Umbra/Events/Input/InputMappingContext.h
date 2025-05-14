#pragma once

#include <Raylib/raylib.h>

#include <string>
#include <vector>

#include "Input.h"
#include "InputAction.h"
#include "InputModifier.h"

using std::string;
using std::vector;

struct InputMap
{
public:
	uint16_t inputKey;
	InputType inputType;
	vector<InputTriggers> triggers;
	vector<InputModifiers> modifiers;
};

struct ActionMapping
{
	InputAction* inputAction;
	vector<InputMap> inputMappings;
};

class InputMappingContext
{
public:
	InputMappingContext();
	~InputMappingContext();

public:
	void SetDescription(const string& description);
	const string& GetDescription() const;

	void SetPriority(int8_t priority);
	const int8_t& GetPriority() const;

	const vector<ActionMapping&>& GetMappings() const;
	void AddMapping(ActionMapping& mapping);
	void RemoveMapping(ActionMapping& mapping);

	void ClearMappings();

private:
	vector<ActionMapping&> m_mappings;
	string m_description;
	int8_t m_priority;
};

