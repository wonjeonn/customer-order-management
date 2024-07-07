#include "Utilities.h"
#include <algorithm>
#include <sstream>

namespace assemblyLine {
    char Utilities::m_delimiter = ',';

    void Utilities::setFieldWidth(size_t newWidth) {
        m_widthField = newWidth;
    }

    size_t Utilities::getFieldWidth() const {
        return m_widthField;
    }

    std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
        more = false;
        std::string token;
        size_t start_pos = next_pos;
        size_t end_pos = str.find(m_delimiter, start_pos);

        if (end_pos == next_pos) {
            more = false;
            throw std::string("ERROR: No token between delimiters");
        }

        if (end_pos == std::string::npos) {
            token = str.substr(start_pos);
            next_pos = str.length();
        } else {
            token = str.substr(start_pos, end_pos - start_pos);
            next_pos = end_pos + 1;
            more = true;
        }

        auto ltrim = [](std::string &s) { s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) { return !std::isspace(ch); })); };
        auto rtrim = [](std::string &s) { s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) { return !std::isspace(ch); }).base(), s.end()); };

        ltrim(token);
        rtrim(token);

        if (token.empty()) {
            throw std::runtime_error("Empty token found.");
        }

        if (m_widthField < token.length()) {
            m_widthField = token.length();
        }

        return token;
    }

    void Utilities::setDelimiter(char newDelimiter) {
        m_delimiter = newDelimiter;
    }

    char Utilities::getDelimiter() {
        return m_delimiter;
    }
}
