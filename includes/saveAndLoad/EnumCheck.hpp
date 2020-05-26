/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** EnumCheck
*/

#ifndef ENUMCHECK_HPP_
#define ENUMCHECK_HPP_

template <typename EnumType, EnumType... Values>
class EnumCheck;

template <typename EnumType>
class EnumCheck<EnumType>
{
public:
    template <typename IntType>
    static bool constexpr is_value(IntType) { return false; }
};

template <typename EnumType, EnumType V, EnumType... Next>
class EnumCheck<EnumType, V, Next...> : private EnumCheck<EnumType, Next...>
{
    using super = EnumCheck<EnumType, Next...>;

public:
    template <typename IntType>
    static bool constexpr is_value(IntType v)
    {
        return v == static_cast<IntType>(V) || super::is_value(v);
    }
};

#endif /* !ENUMCHECK_HPP_ */