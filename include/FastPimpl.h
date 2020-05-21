/**
 * @file 		FastPimpl.h
 * @author 		Argishty Ayvazyan (ayvazyan.argishti@gmail.com)
 * @brief 		Declaration for FastPimpl class.
 * @date 		10-05-2020
 * @copyright 	Copyright (c) 2020
 */

#pragma once

#include <cstddef>
#include <utility>
#include <type_traits>


namespace utils
{

/**
 * @class
 * @brief      The helper class for implementation "fast Pimpl" Idiom.
 * 
 * @tparam     T          The type of hidden class.
 * @tparam     Size       The size of the hidden class.
 * @tparam     Alignment  The alignment of the hidden class.
 */
template <typename T, size_t Size, size_t Alignment>
class FastPimpl
{
public:

	/**
	 * @brief      Constructs a new FastPimpl instance.
	 *
	 * @param      args   The arguments for constructing a hidden class object.
	 *
	 * @tparam     TArgs  The arguments types list for constructing a hidden class object.
	 */
    template <typename... TArgs>
    explicit FastPimpl(TArgs&&... args)
    {
        new (ptr()) T(std::forward<TArgs>(args)...);
    }

    /**
     * @brief      Destroys the object.
     */
    ~FastPimpl() noexcept
    {
        validate<sizeof(T), alignof(T)>();
        ptr()->~T();
    }

    /**
     * @brief      Constructs a new copy of FastPimpl instance.
     *
     * @param[in]  rhs   The right hand side
     */
    explicit FastPimpl(const FastPimpl<T, Size, Alignment>& rhs)
    {
        new (ptr()) T(*rhs);
    }

    /**
     * @brief      The move constructor for Fast Pimple class.
     *
     * @param      rhs   The right hand side
     */
    explicit FastPimpl(FastPimpl<T, Size, Alignment>&& rhs)
    {
        new (ptr()) T(std::move(*rhs));
    }

    /**
     * @brief      Assignment operator.
     *
     * @param      rhs   The right hand side
     *
     * @return     The result of the assignment
     */
    FastPimpl<T, Size, Alignment>& operator=(FastPimpl<T, Size, Alignment>&& rhs)
    {
        *ptr() = std::move(*rhs);
        return *this;
    }

    /**
     * @brief      Assignment operator.
     *
     * @param[in]  rhs   The right hand side
     *
     * @return     The result of the assignment
     */
    FastPimpl<T, Size, Alignment>& operator=(const FastPimpl<T, Size, Alignment>& rhs)
    {
        *ptr() = *rhs;
        return *this;
    }

public:

	/**
	 * @brief      Gets an hidden data pointer.
	 *
	 * @return     The hidden data pointer.
	 */
    T* operator->() noexcept
    {
        return ptr();
    }

    /**
     * @brief      Gets an hidden data const pointer.
     *
     * @return     The hidden data pointer.
     */
    const T* operator->() const noexcept
    {
        return ptr();
    }

    /**
     * @brief      Gets an hidden data.
     *
     * @return     The reference of hidden data.
     */
    T& operator*() noexcept
    {
        return *ptr();
    }

    /**
     * @brief      Gets an hidden data.
     *
     * @return     The const reference of hidden data.
     */
    const T& operator*() const noexcept
    {
        return *ptr();
    }

private:

	/**
     * @internal
	 * @brief      Gets an hidden data pointer.
	 *
	 * @return     Iternal data pointer.
	 */
    T* ptr()
    {
        return reinterpret_cast<T*>(&m_data);
    }

	/**
     * @internal
	 * @brief      Gets an hidden data const pointer.
	 *
	 * @return     Iternal data const pointer.
	 */
    const T* ptr() const
    {
        return reinterpret_cast<const T*>(&m_data);
    }

    /**
     * @internal
     * @brief      Validates size and alignment for hidden class.
     *
     * @tparam     ActualSize       The actual Size for hidden class.
     * @tparam     ActualAlignment  The actual Alignment for hidden class.
     */
    template <std::size_t ActualSize, std::size_t ActualAlignment>
    static void validate() noexcept
    {
        static_assert(Size == ActualSize, "Size and sizeof(T) mismatch.");
        static_assert(Alignment == ActualAlignment, "Alignment and alignof(T) mismatch.");
    }

private:

    std::aligned_storage_t<Size, Alignment> m_data;
};

} // namespace util
