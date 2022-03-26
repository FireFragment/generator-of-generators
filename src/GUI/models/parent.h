#ifndef GOG_GUI_MODELS_PARENT_H
#define GOG_GUI_MODELS_PARENT_H

#include <QObject>
#include <QJsonObject>

namespace GoG::GUI::Model {

/**
 * @brief Parent for all models in Generator of generators
 */
class Parent : public QObject
{
    Q_OBJECT

public:

    /**
     * @brief Call, when you changed any property to update all views
     *
     * Emits `Update` signal
     */
    void Changed() { emit Update(); };

    Parent() {};
    /**
     * @brief Creates the object based on JSON data.
     *        The old data in the object is overriden.
     *
     * @param json The JSON data to use
     */
    virtual void FromJSON(QJsonObject json) = 0;

    virtual QJsonObject ToJSON() const = 0;
signals:
    /**
     * @brief Emitted when some property changed.
     */
    void Update();
};

}

#endif // GOG_GUI_MODELS_PARENT_H
