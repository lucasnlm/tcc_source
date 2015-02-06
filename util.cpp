#include "util.hpp"
#include "analog.hpp"

#include <ctype.h>
#include <cmath>
#include <algorithm>
#include <fstream>

namespace controller
{
    namespace util
    {
        bool writeFileContent(const std::string& path, const std::string& content)
        {
            try
            {
                std::ofstream file(path);
                file << content;
            }
            catch(...)
            {
                return false;
            }
        }
        
        std::string getFileContent(const std::string& path)
        {
            try
            {
                std::ifstream file(path);
                return std::string((std::istreambuf_iterator<char>(file)),
                                    std::istreambuf_iterator<char>());
            }
            catch(...)
            {
                return "";
            }
        }
        
        int clamp(int value, int lower, int upper)
        {
            return std::min(upper, std::max(value, lower));
        }

        int clampADC(int value)
        {
            return std::min(Analog::MAX_VALUE, std::max(value, Analog::MIN_VALUE));
        }
    }

    namespace http
    {
        namespace util
        {
            bool isChar(int value)
            {
                return (value >= 0) && (value <= 127);
            }

            bool isControl(int value)
            {
                return (::iscntrl(value) != 0);
            }

            bool isTypingSpecial(int value)
            {
                switch (value)
                {
                    case '(': case ')': case '<': case '>': case '@':
                    case ',': case ';': case ':': case '\\': case '"':
                    case '/': case '[': case ']': case '?': case '=':
                    case '{': case '}': case ' ': case '\t':
                        return true;
                    default:
                        return false;
                }
            }

            bool isDigit(int value)
            {
                return (::isdigit(value) != 0);
            }
        }
    }
}
