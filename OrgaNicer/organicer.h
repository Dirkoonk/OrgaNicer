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
 //   QMenu *fileMenu;
   // QAction *newAct;

//private slots:
 //   void newFile();
};
#endif // ORGANICER_H


