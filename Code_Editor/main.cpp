#include <QtWidgets>
#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QSettings>
#include <QFileDialog>
#include <QMessageBox>
#include <QApplication>
#include <QLabel>
#include "codeeditor.h"
#include "syntaxhighlighter.h"
#include "mainwindow.h"
#include "ui_codeeditor.h"

int main(int argv, char **args){ 
    QApplication app(argv, args);
    MainWindow m;
    return app.exec();
}
