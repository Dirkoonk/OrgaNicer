#include "organicer.h"
#include "./ui_organicer.h"

OrgaNicer::OrgaNicer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::OrgaNicer)
{
    ui->setupUi(this);
}


// Tes qwoefgqwefoiqgwezqw


OrgaNicer::~OrgaNicer()
{
    delete ui;
}
