#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
#include "Utilities.h"
#include "LineManager.h"
#include "Workstation.h"
#include "CustomerOrder.h"

namespace assemblyLine {
    LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations) {
        Utilities utility;
        std::string str;
        size_t nextPos;
        bool more = false;
        std::string item;
        std::string nextItem;

        std::ifstream fs(file);
        if (!fs) {
            throw std::string("Unable to open file");
        }

        while (getline(fs, str)) {
            nextPos = 0;
            more = true;
            Workstation* currentStation{};
            Workstation* nextStation{};

            item = utility.extractToken(str, nextPos, more);
            currentStation = *find_if(stations.begin(), stations.end(), [&](Workstation* ws) {
                return ws->getItemName() == item;
            });
            m_activeLine.push_back(currentStation);

            if (more) {
                nextItem = utility.extractToken(str, nextPos, more);
                nextStation = *find_if(stations.begin(), stations.end(), [&](Workstation* s) {
                    return s->getItemName() == nextItem;
                });
                currentStation->setNextStation(nextStation);
            }
        }

        for_each(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* ws1) {
            auto firstStation = std::find_if(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* ws2) {
                return ws1 == ws2->getNextStation();
            });
            if (firstStation == m_activeLine.end()) {
                m_firstStation = ws1;
            }
        });

        fs.close();
        m_cntCustomerOrder = g_pending.size();
    }

    void LineManager::reorderStations() {
        m_activeLine.clear();
        Workstation* ws = m_firstStation;
        while (ws != nullptr) {
            m_activeLine.push_back(ws);
            ws = ws->getNextStation();
        }
    }

    bool LineManager::run(std::ostream& os) {
        static size_t count = 0;
        count++;

        os << "Line Manager Iteration: " << count << std::endl;

        if (!g_pending.empty()) {
            *m_firstStation += std::move(g_pending.front());
            g_pending.pop_front();
        }

        for (auto& workstation : m_activeLine) {
            workstation->fill(os);
        }

        for (auto& workstation : m_activeLine) {
            workstation->attemptToMoveOrder();
        }

        return g_completed.size() + g_incomplete.size() == m_cntCustomerOrder;
    }

    void LineManager::display(std::ostream& os) const {
        for (const auto& ws : m_activeLine) {
            ws->display(os);
        }
    }
}
