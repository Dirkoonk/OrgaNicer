#include "organicer.h"
#include "./ui_organicer.h"

OrgaNicer::OrgaNicer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::OrgaNicer)
{
    ui->setupUi(this);




}




OrgaNicer::~OrgaNicer()
{
    delete ui;
}

void OrgaNicer::on_calendarWidget_currentPageChanged(int year, int month)
{
    ui->AListe->clear();


    if(month==1||month==4||month==7||month==10){

        QListWidgetItem *Bad = new QListWidgetItem;
        QListWidgetItem *Wischen = new QListWidgetItem;
        QListWidgetItem *Garten = new QListWidgetItem;

        Bad->setText("Bad putzen Paul");
        Wischen->setText("Wischen Marlon");
        Garten->setText("Garten Marcel");

        ui->AListe->addItem(Bad);
        ui->AListe->addItem(Wischen);
        ui->AListe->addItem(Garten);

    }
    if(month==2||month==5||month==8||month==11){

        QListWidgetItem *Bad = new QListWidgetItem;
        QListWidgetItem *Wischen = new QListWidgetItem;
        QListWidgetItem *Garten = new QListWidgetItem;

        Bad->setText("Bad putzen Marcel");
        Wischen->setText("Wischen Paul");
        Garten->setText("Garten Marlon");

        ui->AListe->addItem(Bad);
        ui->AListe->addItem(Wischen);
        ui->AListe->addItem(Garten);

    }
    if(month==3||month==6||month==9||month==12){

        QListWidgetItem *Bad = new QListWidgetItem;
        QListWidgetItem *Wischen = new QListWidgetItem;
        QListWidgetItem *Garten = new QListWidgetItem;

        Bad->setText("Bad putzen Marlon");
        Wischen->setText("Wischen Marcel");
        Garten->setText("Garten Paul");

        ui->AListe->addItem(Bad);
        ui->AListe->addItem(Wischen);
        ui->AListe->addItem(Garten);

    }

}

