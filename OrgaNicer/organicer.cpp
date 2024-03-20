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

    fileMenu = menuBar()->addMenu(tr("&Putzplan"));
    newAct1 = new QAction(tr("&Übersicht"),this);
    fileMenu->addAction(newAct1);
    connect(newAct1, &QAction::triggered,this, &OrgaNicer::Uebersicht);

    newAct2 = new QAction(tr("&Marcel"),this);
    fileMenu->addAction(newAct2);
    connect(newAct2, &QAction::triggered,this, &OrgaNicer::Marcel);

    newAct3 = new QAction(tr("&Marlon"),this);
    fileMenu->addAction(newAct3);
    connect(newAct3, &QAction::triggered,this, &OrgaNicer::Marcel);

    newAct4 = new QAction(tr("&Paul"),this);
    fileMenu->addAction(newAct4);
    connect(newAct4, &QAction::triggered,this, &OrgaNicer::Marcel);



}

void OrgaNicer::Uebersicht(){

}

void OrgaNicer::Marlon(){

}

void OrgaNicer::Paul(){

}

void OrgaNicer::Marcel(){

}



OrgaNicer::~OrgaNicer()
{
    delete ui;
}
