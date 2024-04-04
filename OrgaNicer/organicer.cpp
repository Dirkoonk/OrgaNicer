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
        if( item->text().contains(searchDate_str,Qt::CaseInsensitive)){
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

void OrgaNicer::MonatsplanInit(){
    QString jahr,monat,datum,bad,wischen,garten;
    date="2024.01.00  Paul: Bad";

    for(int j = 2024;j < 2100; j++ ){
        for(int m = 1;m<=12;m++){
            if(m==1||m==4||m==7||m==10){
                jahr = QString("%1").arg(j);
                monat = QString("%1").arg(m);

                text= "Bad putzen Marlon";
                text="Wischen Marcel";
                text="Garten Paul";

                datum = jahr+"."+monat+".00  "+bad;
            }
        }
    }
}


void OrgaNicer::on_calendarWidget_currentPageChanged(int year, int month)
{
    QString month_str = QString("%1").arg(month);
    QString year_str= QString("%1").arg(year);


    QString fullDate_str = year_str + "." + "0" + month_str;
    qDebug() << fullDate_str;

    ListeDurchsuchenPassendEinblenden(fullDate_str);


}


void OrgaNicer::erstelleItem(QListWidget *listWidget, QString listWidgetText) {
    // Ein neues QListWidgetItem erstellen und Text anhängen
    QListWidgetItem *item = new QListWidgetItem(listWidgetText);
    listWidget->addItem(item);
}

void OrgaNicer::on_calendarWidget_clicked(const QDate &date)
{
    if(ui->lineEdit->text().length() >= 2){
        // String aus Kalender Datum
        QString dateString = date.toString("yyyy.MM.dd");

        // String vom Textbox


        QString text = ui->lineEdit->text();

        dateString = dateString +"  " + text;

        erstelleItem(ui->AListe, dateString);
    }


    ui->lineEdit->clear();
}






