#ifndef CUSTOMERORDER_H
#define CUSTOMERORDER_H
#include <string>
#include "Station.h"

namespace assemblyLine {
    struct Item {
        std::string m_itemName{};
        size_t m_serialNumber{ 0 };
        bool m_isFilled{ false };
        Item(const std::string& src) : m_itemName(src) {};
    };
    class CustomerOrder {
        std::string m_name{};
        std::string m_product{};
        size_t m_cntItem{ 0 };
        Item** m_lstItem{ nullptr };
        static size_t m_widthField;
    public:
        CustomerOrder();
        CustomerOrder(const std::string&);
        CustomerOrder(const CustomerOrder&);
        CustomerOrder& operator=(const CustomerOrder&) = delete;
        CustomerOrder(CustomerOrder&&) noexcept;
        CustomerOrder& operator=(CustomerOrder&&) noexcept;
        ~CustomerOrder();
        bool isOrderFilled() const;
        bool isItemFilled(const std::string& itemName) const;
        void fillItem(Station& station, std::ostream& os);
        void display(std::ostream& os) const;
    };
}

#endif // !CUSTOMERORDER_H
