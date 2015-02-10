/**
 * Copyright 2014 Lucas Nunes de Lima
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 **/

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
