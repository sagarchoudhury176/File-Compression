#ifndef _LZW_STREAMBASE_DOT_H
#define _LZW_STREAMBASE_DOT_H

#include <string>

namespace lzw
{

    //
    // The input symbol stream class reads symbols until some stopping point.
    //

    template <typename T>
    class input_symbol_stream
    {
    public:
        input_symbol_stream(T &);
        bool operator>>(char &c);
    };

    //
    // The output symbol stream writes strings instead of individual
    // characters, because that is what is normally stored in the
    // dictionary. C++ std::string class makes a perfectly good
    // container for any variety of symbols.
    //

    template <typename T>
    class output_symbol_stream
    {
    public:
        output_symbol_stream(T &);
        void operator<<(const std::string &s);
    };

    //
    // The input code stream reads codes, normally unsigned integers,
    // from some type of stream. Note that the extraction
    // method that is reading the codes should return false.
    //

    const unsigned int EOF_CODE = 256;

    template <typename T>
    class input_code_stream
    {
    public:
        input_code_stream(T &, unsigned int);
        bool operator>>(unsigned int &i);
    };

    template <typename T>
    class output_code_stream
    {
    public:
        output_code_stream(T &, unsigned int);
        void operator<<(const unsigned int i);
    };

}; //namespace lzw

#endif //#ifndef _LZW_STREAMBASE_DOT_H