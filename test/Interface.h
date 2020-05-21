/**
 * @file        Interface.h
 * @author      Argishty Ayvazyan (ayvazyan.argishti@gmail.com)
 * @brief       Declaration for Interface class.
 * @date        10-05-2020
 * @copyright   Copyright (c) 2020
 */

#pragma once

#include <memory>

#include "FastPimpl.h"

class NativeType;


/**
 * @brief      The public interface for the hidden class.
 */
class Interface
{
public:

    Interface();
    Interface(int ID);
    ~Interface();

    Interface(Interface&&);
    Interface(const Interface&);
    Interface& operator=(Interface&&);
    Interface& operator=(const Interface&);

    void doWork();

private:

    /**
     * @brief      The size of hidden class.
     * @note       The wrong size will lead to a compilation error.
     */
    static constexpr std::size_t iDataImplSize = 4;

    /**
     * @brief      The alignment of hidden class.
     * @note       The wrong alignment will lead to a compilation error.
     */
    static constexpr std::size_t iDataimplAlign = 4;

    utils::FastPimpl<NativeType, iDataImplSize, iDataimplAlign> m_data;
};

