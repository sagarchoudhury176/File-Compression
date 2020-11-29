#ifndef LZW_A_DOT_H
#define LZW_A_DOT_H

#include "lzw_streambase.h"
#include <iostream>

namespace lzw
{
    //
    //ifstream extraction operator, as in m_impl >> c, but that operator
    // skips over whitespace, so we don't get an exact copy of
    // the input stream. Using get() works.
    //
    template <>
    class input_symbol_stream<std::istream>
    {
    public:
        input_symbol_stream(std::istream &input)
            : m_input(input) {}
        bool operator>>(char &c)
        {
            if (!m_input.get(c))
                return false;
            else
                return true;
        }

    private:
        std::istream &m_input;
    };
    //
    // Using the insertion operator to output strings seems to work properly,
    // even when the strings contain binary data
    //
    template <>
    class output_symbol_stream<std::ostream>
    {
    public:
        output_symbol_stream(std::ostream &output)
            : m_output(output) {}
        void operator<<(const std::string &s)
        {
            m_output << s;
        }

    private:
        std::ostream &m_output;
    };

    template <>
    class output_code_stream<std::ostream>
    {
    public:
        output_code_stream(std::ostream &output, const int)
            : m_output(output) {}
        void operator<<(unsigned int i)
        {
            m_output << i << '\n';
        }
        ~output_code_stream()
        {
            *this << EOF_CODE;
        }

    private:
        std::ostream &m_output;
    };

    template <>
    class input_code_stream<std::istream>
    {
    public:
        input_code_stream(std::istream &input, unsigned int)
            : m_input(input) {}
        bool operator>>(unsigned int &i)
        {
            m_input >> i;
            if (!m_input || i == EOF_CODE)
                return false;
            else
                return true;
        }

    private:
        std::istream &m_input;
    };

}; //namespace lzw

#endif //#ifndef LZW_A_DOT_H