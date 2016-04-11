#include <QtWidgets/QWidget>
#include "mainwindow.h"
#include <QPlainTextEdit>
#include <QAction>
#include <QMenu>
#include <QToolBar>
#include <QMenuBar>
#include <QString>
#include <QMessageBox>
#include <QStatusBar>
#include <QFileDialog>
#include <QCloseEvent>
#include <QTextStream>
#include <QFile>
#include <QApplication>
#include <QTextCursor>
#include <QSettings>
#include <QTextCharFormat>
#include <QDockWidget>
#include <QTreeView>
#include <QFileSystemModel>
#include <QTreeWidget>
#include <QSplitter>
#include <iostream>
#include <QAbstractItemView>
#include <QPalette>
#include <QColor>
#include <QtDebug>
#include <QDir>
#include <QIcon>
#include <QInputDialog>

using namespace std;

MainWindow::MainWindow(): QMainWindow(){
//    ui = new Ui::codeeditor;
//    ui -> setupUi(this);
//    editor = new CodeEditor(this);
//    highlighter = new SyntaxHighlighter(editor->document());
//    this -> setCentralWidget(editor);
//    //editor->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
//    this -> setWindowTitle(QObject::tr("Galeanthropy"));
//    this -> show();
}

MainWindow::~MainWindow(){

}
