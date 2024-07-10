#include "Station.h"
#include "Utilities.h"
#include <iostream>
#include <sstream>

namespace assemblyLine {
    size_t Station::m_widthField = 0;
    int Station::id_generator = 0;

    Station::Station(const std::string& record) {
        Utilities util;
        size_t next_pos = 0;
        bool more = true;

        m_itemName = util.extractToken(record, next_pos, more);
        m_serialNumber = std::stoi(util.extractToken(record, next_pos, more));
        m_quantity = std::stoi(util.extractToken(record, next_pos, more));
        m_description = util.extractToken(record, next_pos, more);

        m_id = ++id_generator;

        if (m_widthField < m_itemName.length()) {
            m_widthField = m_itemName.length();
        }
    }

    const std::string& Station::getItemName() const {
        return m_itemName;
    }

    size_t Station::getNextSerialNumber() {
        return m_serialNumber++;
    }

    size_t Station::getQuantity() const {
        return m_quantity;
    }

    void Station::updateQuantity() {
        if (m_quantity > 0) {
            --m_quantity;
        }
    }

    void Station::display(std::ostream& os, bool full) const {
        os << std::setw(3) << std::right << std::setfill('0') << m_id << " | "
           << std::setw(m_widthField) << std::left << std::setfill(' ') << m_itemName << " | "
           << std::setw(6) << std::right << std::setfill('0') << m_serialNumber << std::setfill(' ') << " | ";        
        if (!full) {
            os << std::endl;
        } else {
            os << std::setw(4) << m_quantity << " | " << m_description << std::endl;
        }
    }
}
