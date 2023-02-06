#ifndef PAGESINTERFACE_H
#define PAGESINTERFACE_H

#include <QWidget>
#include <QLineEdit>
#include "../../Models/SerializableObject.h";

class PagesInterface : public QWidget {
Q_OBJECT
protected:
    const SerializableObject *objToManage;
    QLineEdit *nameField;
    bool toEdit;
public:
    PagesInterface(const SerializableObject * = nullptr, bool tE = false, QWidget *parent = 0);

    void returnTypeSelectionPageSignal();

    void addSerializableObjectSignal(SerializableObject *);

    virtual void editSerializableObjectSignal(SerializableObject *toEdit, SerializableObject *edited) = 0;

public slots:

    void returnTypeSelectionPageSlot();

    virtual void addSerializableObjectSlot() = 0;

    virtual void editSerializableObjectSlot() = 0;
};

#endif
