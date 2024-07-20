#include "autoservice.h"
#include "ui_autoservice.h"
#include <QDebug>

AutoService::AutoService(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AutoService)
{
    ui->setupUi(this);
    connect(ui->b_filter, &QPushButton::clicked, this, &AutoService::filter);
    connect(ui->l_automobiles, &QListWidget::itemClicked, this, &AutoService::select);

    ChildAutomobile* automobile1 = new ChildAutomobile();
    ChildAutomobile* automobile2 = new ChildAutomobile();
    ChildAutomobile* automobile3 = new ChildAutomobile();

    automobile1->setManufacturer("Rolls-Royce");
    automobile1->setModel((QString)"Wraith");
    automobile1->setType("Coupé");
    automobile1->setPrice(343350);
    automobile1->setSeats(4);
    automobile1->setColor(QColor(19, 25, 98));

    automobile2->setManufacturer("Hyundai");
    automobile2->setModel((QString)"Santa Cruz");
    automobile2->setType("Pickup truck");
    automobile2->setPrice(26900);
    automobile2->setSeats(5);
    automobile2->setColor(QColor(143, 144, 139));

    automobile3->setManufacturer("JAC");
    automobile3->setModel((QString)"Shuailing T6");
    automobile3->setType("Pickup truck");
    automobile3->setPrice(13778);
    automobile3->setSeats(5);
    automobile3->setColor(QColor(221, 225, 228));

    m_automobiles.append(automobile1);
    m_automobiles.append(automobile2);
    m_automobiles.append(automobile3);
}

AutoService::~AutoService()
{
    delete ui;
}

void AutoService::filter()
{
    ui->l_automobiles->clear();
    ui->e_selected->clear();
    for (int automobile = 0; automobile < m_automobiles.size(); ++automobile) {
        if (
            ((ui->e_manufacturer->text().isEmpty()) || m_automobiles[automobile]->getManufacturer() == ui->e_manufacturer->text())
            && ((ui->e_type->text().isEmpty()) || (m_automobiles[automobile]->getType() == ui->e_type->text()))
            && ((ui->e_price->text().isEmpty()) || (m_automobiles[automobile]->getPrice() >= ui->e_price->text().toInt()))
            )
                addAutomobile(m_automobiles[automobile]);

    }
}

void AutoService::addAutomobile(ChildAutomobile * automobile)
{
    ui->l_automobiles->addItem(automobile->getManufacturer() + " " + automobile->getModel());
}

void AutoService::select(QListWidgetItem * item)
{
    for (int automobile = 0; automobile < m_automobiles.size(); ++automobile) {
        if (item->text() == (m_automobiles[automobile]->getManufacturer() + " " + m_automobiles[automobile]->getModel())) {
            ui->e_selected->setText("Manufacturer: " + m_automobiles[automobile]->getManufacturer() + "\n"
                                    + "Model: " + m_automobiles[automobile]->getModel() + "\n"
                                    + "Type: " + m_automobiles[automobile]->getType() + "\n"
                                    + "Seats: " + QString::number(m_automobiles[automobile]->getSeats()) + "\n"
                                    + "Color: " + m_automobiles[automobile]->getColor().name() + "\n"
                                    + "Price: " + QString::number(m_automobiles[automobile]->getPrice()));
            break;
        }
    }
}
