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

    ui->setupUi(this);
    fileMenu = menuBar()->addMenu(tr("&File"));
    newAct = new QAction(tr("&New"),this);
    fileMenu->addAction(newAct);
    connect(newAct, &QAction::triggered,this, &OrgaNicer::newFile);


}




void OrgaNicer::newFile(){

}



OrgaNicer::~OrgaNicer()
{
    delete ui;
}
