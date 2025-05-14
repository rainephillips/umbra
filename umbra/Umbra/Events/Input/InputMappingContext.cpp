#include "InputMappingContext.h"

InputMappingContext::InputMappingContext()
	: m_mappings(vector<ActionMapping&>()), m_priority( 0 )
{
}

InputMappingContext::~InputMappingContext() = default;

void InputMappingContext::SetDescription(const string& description)
{
	m_description = description;
}

const string& InputMappingContext::GetDescription() const
{
	return m_description;
}

void InputMappingContext::SetPriority(int8_t priority)
{
	m_priority = priority;
}

const int8_t& InputMappingContext::GetPriority() const
{
	return m_priority;
}

const vector<ActionMapping&>& InputMappingContext::GetMappings() const
{
	return m_mappings;
}

void InputMappingContext::AddMapping(ActionMapping& mapping)
{
	m_mappings.emplace_back(mapping);
}

void InputMappingContext::RemoveMapping(ActionMapping& mapping)
{
	m_mappings.erase(mapping);
}

void InputMappingContext::ClearMappings()
{
	m_mappings.clear();
}
