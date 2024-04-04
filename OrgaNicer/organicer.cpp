#include "organicer.h"
#include "./ui_organicer.h"



// aktuelles Datum einlesen

int Amonth = QDate::currentDate().month();

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


void OrgaNicer::ListeDurchsuchenPassendEinblenden(QString searchDate_str)
{
    for(int i = 0; i < ui->AListe->count(); i++){
        QListWidgetItem *item = ui->AListe->item(i);
        if(ui->AListe->item(i)->text().contains(searchDate_str,Qt::CaseInsensitive)){
            ui->AListe->item(i)->setHidden(false);
        }
        else{
            ui->AListe->item(i)->setHidden(true);
        }
    }
}

void OrgaNicer::DateiInhaltLoeschen(){

    QString filePath = "liste.dat";

    // QFile-Objekt erstellen
    QFile file(filePath);

    // Datei öffnen
    if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        qDebug() << "Fehler beim Öffnen der Datei zum Schreiben:" << file.errorString();
    }

    // Dateiinhalt löschen
    file.resize(0);

    // Datei schließen
    file.close();

    qDebug() << "Dateiinhalt erfolgreich gelöscht.";

}

void OrgaNicer::SpeicherListe(QListWidget *liste){

     QString dateiPfad = "liste.dat";

    QFile datei(dateiPfad);

    if (datei.open(QIODevice::WriteOnly)) {
        QDataStream out(&datei);
        out.setVersion(QDataStream::Qt_6_6);

        // Schreiben der Anzahl der Elemente
        out << liste->count();

        // Schreiben der Elemente
        for (int i = 0; i < liste->count(); ++i) {
            out << liste->item(i)->text();
        }

        datei.close();
        qDebug() << "Inhalt des QListWidget wurde erfolgreich in Datei gespeichert.";
    } else {
        qDebug() << "Fehler beim Öffnen der Datei zum Schreiben.";
    }
}
void OrgaNicer::LeseListe(QListWidget *liste){

    QString dateiPfad = "liste.dat";

    QFile datei(dateiPfad);



    if (datei.open(QIODevice::ReadOnly)) {
        QDataStream in(&datei);
        in.setVersion(QDataStream::Qt_6_6);

        // Lesen der Anzahl der Elemente
        int count;
        in >> count;

        // Lesen der Elemente und Hinzufügen zum gelesenen QListWidget
        for (int i = 0; i < count; ++i) {
            QString element;
            in >> element;
            liste->addItem(element);
        }

        datei.close();
        qDebug() << "Inhalt aus Datei gelesen.";
    } else {
        qDebug() << "Fehler beim Öffnen der Datei zum Lesen.";
    }
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


void OrgaNicer::erstelleItem(QListWidget *listWidget, QString listWidgetText) {
    // Ein neues QListWidgetItem erstellen und Text anhängen
    QListWidgetItem *item = new QListWidgetItem(listWidgetText);
    listWidget->addItem(item);
}

void OrgaNicer::on_calendarWidget_clicked(const QDate &date)
{
    // String aus Kalender Datum
    QString dateString = date.toString("yyyy.MM.dd");

    // String vom Textbox


    QString text = ui->lineEdit->text();

    dateString = dateString +"  " + text;

    erstelleItem(ui->AListe, dateString);

    ui->lineEdit->clear();
}






