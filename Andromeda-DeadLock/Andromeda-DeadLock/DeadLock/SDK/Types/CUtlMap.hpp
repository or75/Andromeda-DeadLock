#pragma once

#include <optional>

#include <Common/Common.hpp>

template <typename K , typename V>
class CUtlMap
{
public:
    struct Node_t
    {
        int m_left;
        int m_right;
        int m_parent;
        int m_tag;
        K m_key;
        V m_value;
    };

    auto begin() const { return m_data; }
    auto end() const { return m_data + m_size; }

    auto FindByKey( K key ) const -> std::optional<V>
    {
        int current = m_root;

        while ( current != -1 )
        {
            const Node_t& element = m_data[current];

            if ( element.m_key < key )
            {
                current = element.m_right;
            }
            else if ( element.m_key > key )
            {
                current = element.m_left;
            }
            else
            {
                return element.m_value;
            }
        }

        return std::nullopt;
    }

public:
    char pad0[0x8];  // no idea
    Node_t* m_data;
    char pad1[0x8];  // no idea
    int m_root;
    int m_size;
    char pad2[0x8];  // no idea
};
