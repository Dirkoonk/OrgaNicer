#ifndef ORGANICER_H
#define ORGANICER_H

#include <QMainWindow>
#include <QPushButton>
#include <QMenu>
#include <QAction>
#include  <QString>

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

private slots:

    void on_calendarWidget_currentPageChanged(int year, int month);
};
#endif // ORGANICER_H
