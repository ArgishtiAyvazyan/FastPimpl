#include "Interface.h"

#include "NativeType.h"


Interface::Interface() = default;

Interface::Interface(int ID)
    : m_data (ID)
{ }

Interface::~Interface() = default;

Interface::Interface(Interface&&) = default;

Interface::Interface(const Interface&) = default;

Interface& Interface::operator=(Interface&&) = default;

Interface& Interface::operator=(const Interface&) = default;

void Interface::doWork()
{
    m_data->doWork();
}
