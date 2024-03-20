#include "organicer.h"
#include "./ui_organicer.h"

OrgaNicer::OrgaNicer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::OrgaNicer)
{
    ui->setupUi(this);
    this->setFixedSize(500,500);
    neuerknopf = new QPushButton("Test", this);
    neuerknopf->setGeometry(20, 120, 50, 30);
    connect(neuerknopf, SIGNAL(clicked()), qApp, SLOT(quit()));
}


// Tes qwoefgqwefoiqgwezqw


OrgaNicer::~OrgaNicer()
{
    delete ui;
}
