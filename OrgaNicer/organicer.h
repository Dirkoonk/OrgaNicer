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
    void SpeicherListe(QListWidget liste);
    void LeseListe(QListWidget liste);
    void ListeDurchsuchenPassendEinblenden(QString searchDate_str);

private slots:

    void on_calendarWidget_currentPageChanged(int year, int month);
};
#endif // ORGANICER_H
