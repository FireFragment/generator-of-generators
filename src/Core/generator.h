#ifndef GOG_CORE_GENERATOR_H
#define GOG_CORE_GENERATOR_H

#include <QString>
#include <QVector>
#include "subgen.h"

namespace GoG::Core {

/**
 * @todo write docs
 */
class Generator
{
public:
    QString name;
    QVector<Subgen> subgens;
};

}

#endif // GOG_CORE_GENERATOR_H
