#include "codeeditor.h"
#include "ui_codeeditor.h"

codeeditor::codeeditor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::codeeditor)
{
    ui->setupUi(this);
}

codeeditor::~codeeditor()
{
    delete ui;
}
