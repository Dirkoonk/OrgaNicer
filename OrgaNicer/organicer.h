#ifndef ORGANICER_H
#define ORGANICER_H

#include <QMainWindow>
#include <string.h>
#include <QPushButton>
#include <QMenu>
#include <QAction>
#include <QFile>
#include <QDataStream>
#include <QString>
#include <QListWidget>
#include <QApplication>
#include <QLineEdit>

QT_BEGIN_NAMESPACE
namespace Ui {
class OrgaNicer;
}
QT_END_NAMESPACE

class OrgaNicer : public QMainWindow
{
    Q_OBJECT

public:
    OrgaNicer(QWidget *parent = nullptr);
    ~OrgaNicer();

private:
    Ui::OrgaNicer *ui;
    void SpeicherListe(QListWidget *liste);
    void LeseListe(QListWidget *liste);
    void ListeDurchsuchenPassendEinblenden(QString searchDate_str);
    void erstelleItem(QListWidget *listWidget, QString listWidgetText);
    void on_pushButton_clicked();
    void DateiInhaltLoeschen();
    void MonatsplanInit();

private slots:

    void on_calendarWidget_currentPageChanged(int year, int month);
    void on_calendarWidget_clicked(const QDate &date);

    void on_pushButton_2_clicked();
};
#endif // ORGANICER_H
