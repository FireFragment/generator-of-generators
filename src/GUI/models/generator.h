#ifndef GOG_GUI_MODEL_GENERATOR_H
#define GOG_GUI_MODEL_GENERATOR_H

#include <QObject>
#include <QString>
#include "parent.h"
#include "subgenerator.h"

namespace GoG::GUI::Model {

/**
 * @todo write docs
 */
class Generator : public Model::Parent
{
    Q_OBJECT

public:
    QString name;
    QVector<Model::Subgenerator> subgenerators;

    Generator(QString name) : name(name) {};
};

}

#endif // GOG_GUI_MODEL_GENERATOR_H
