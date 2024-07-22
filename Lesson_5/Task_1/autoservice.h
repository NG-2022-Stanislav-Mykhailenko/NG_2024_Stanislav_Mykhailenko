#ifndef AUTOSERVICE_H
#define AUTOSERVICE_H

#include <QMainWindow>
#include "childautomobile.h"
#include <QListWidget>
#include <QRandomGenerator>

QT_BEGIN_NAMESPACE
namespace Ui {
class AutoService;
}
QT_END_NAMESPACE

class AutoService : public QMainWindow
{
    Q_OBJECT

public:
    AutoService(QWidget *parent = nullptr);
    ~AutoService();

private slots:
    void filter();

private:
    Ui::AutoService *ui;
    QVector<ChildAutomobile *> m_automobiles;
    void addAutomobile(ChildAutomobile*);
    void generateAutomobiles();
    void select(QListWidgetItem *);
};
#endif // AUTOSERVICE_H
