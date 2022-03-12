#ifndef GOG_PTRVECTOR_H
#define GOG_PTRVECTOR_H

#include <QVector>

namespace GoG {

/**
 * \brief Vector of pointers.
 *
 * When copied, it copies also it's items
 * When deleted, deletes all items
 */
template<typename T>
class PtrVector :  public QVector<T*>
{
public:
    /**
     * Copy constructor
     * Copies also all items
     */
    PtrVector(const PtrVector& other) {
        for (T* item : other) {
            append(item);
        }
    };

    /**
     * Destructor
     * Deletes all items
     */
    ~PtrVector() {
        for (T* item : &this) {
            delete item;
        }
    };

};

}

#endif // GOG_PTRVECTOR_H
