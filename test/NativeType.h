/**
 * @file        NativeType.h
 * @author      Argishty Ayvazyan (argishty.ayvazyan@gmail.com)
 * @brief       Declaration for NativeType class.
 * @date        10-05-2020
 * @copyright   Copyright (c) 2020
 */

 #pragma once

#include <iostream>

/**
 * @class
 * @brief      An example of a class whose implementation you want to hide
 */
class NativeType
{
public:

    NativeType()
        : m_iID { std::rand() }
    { }

    NativeType(int ID) noexcept
        : m_iID (ID)
    { }

    NativeType(NativeType&&) = default;
    NativeType(const NativeType&) = default;
    NativeType& operator=(NativeType&&) = default;
    NativeType& operator=(const NativeType&) = default;


    void doWork() const
    {
        std::cout << "ID: " << m_iID << " Is working." << std::endl;
    }

private:
    int m_iID;
};

