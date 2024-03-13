#ifndef ORGANICER_H
#define ORGANICER_H

#include <QMainWindow>

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
};
#endif // ORGANICER_H
