#ifndef ORGANICER_H
#define ORGANICER_H

#include <QMainWindow>
#include <QPushButton>
#include <QMenu>
#include <QAction>

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
    QPushButton *neuerknopf;
    QMenu *fileMenu;
    QAction *newAct1;
    QAction *newAct2;
    QAction *newAct3;
    QAction *newAct4;

private slots:
    void Uebersicht();
    void Marcel();
    void Marlon();
    void Paul();
};
#endif // ORGANICER_H


