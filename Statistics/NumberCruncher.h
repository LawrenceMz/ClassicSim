#ifndef NUMBERCRUNCHER_H
#define NUMBERCRUNCHER_H

#include <QMap>
#include <QMutexLocker>
#include <QVector>
#include "SimSettings.h"

class ClassStatistics;
class DamageBreakdownModel;
class StatisticsSpell;

class NumberCruncher {
public:
    ~NumberCruncher();

    void add_class_statistic(SimOption, ClassStatistics*);
    void reset();

    void print();

private:
    friend class DamageBreakdownModel;

    QMutex mutex;
    QMap<SimOption, QVector<ClassStatistics*>> class_stats;

    double get_dps_for_option(SimOption) const;
    void calculate_stat_weights() const;

    void merge_spell_stats(QList<StatisticsSpell*>& vec);
    void merge_spell_entry(const QString& name, long long int total_damage_dealt, QList<StatisticsSpell*>& vec);
};

#endif // NUMBERCRUNCHER_H
