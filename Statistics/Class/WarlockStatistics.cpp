
#include "WarlockStatistics.h"

WarlockStatistics::WarlockStatistics(SimSettings* settings) :
    ClassStatistics(settings)
{

}

int WarlockStatistics::getNumStatisticsRows() const {
    int data = spell_statistics.empty() ? 0 : 1;
    data += buff_statistics.empty() ? 0 : 1;
    data += resource_statistics.empty() ? 0 : 1;
    data += proc_statistics.empty() ? 0 : 1;
    return data;
}

QVariantList WarlockStatistics::getTableInfo(const int index) const {
    QVariantList table_info;

    switch (index) {
    case 0:
        table_info.append(get_damage_breakdown_table());
        break;
    case 1:
        table_info.append(get_buff_uptime_table());
        break;
    case 2:
        table_info.append(get_resource_gain_table());
        break;
    case 3:
        table_info.append(get_proc_table());
        break;
    }

    return table_info;
}

QVariantList WarlockStatistics::getChartInfo(const int index) const {
    QVariantList chart_info;


    switch (index) {
    case 0:
        chart_info.append(get_damage_breakdown_chart());
        break;
    }

    return chart_info;
}

QString WarlockStatistics::getEntryIcon(const int) const {
    return "";
}
