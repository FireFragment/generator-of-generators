#ifndef GOG_CORE_SUBGEN_H
#define GOG_CORE_SUBGEN_H

#include <QString>

namespace GoG::Core {

/**
 * @todo write docs
 */
class Subgen
{
public:
    /**
     * @brief The name of subgenerator
     * 
     */
    QString name;
    Subgen(QString name) : name(name) {};
    Subgen() {};
};

}


#endif // GOG_CORE_SUBGEN_H
