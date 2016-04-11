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
    ui = new Ui::codeeditor;
    ui -> setupUi(this);
    editor = new CodeEditor(this);
    highlighter = new SyntaxHighlighter(editor->document());

    ui->actionQuit  -> connect(ui->actionQuit,  SIGNAL(triggered()), this,   SLOT(close()));
    ui->actionCopy  -> connect(ui->actionCopy,  SIGNAL(triggered()), editor, SLOT(copy()));
    ui->actionCut   -> connect(ui->actionCut,   SIGNAL(triggered()), editor, SLOT(cut()));
    ui->actionPaste -> connect(ui->actionPaste, SIGNAL(triggered()), editor, SLOT(paste()));
    ui->actionQuit  -> connect(ui->actionQuit,  SIGNAL(triggered()), editor, SLOT(selectAll()));
    ui->actionUndo  -> connect(ui->actionUndo,  SIGNAL(triggered()), editor, SLOT(undo()));
    ui->actionRedo  -> connect(ui->actionRedo,  SIGNAL(triggered()), editor, SLOT(redo()));
    ui->actionOpen  -> connect(ui->actionOpen,  SIGNAL(triggered()), this,   SLOT(openDialog()));

    this -> setCentralWidget(editor);
    this -> setWindowTitle(QObject::tr("Galeanthropy"));
    this -> show();
}

MainWindow::~MainWindow(){
    delete highlighter;
    delete editor;
    delete ui;
}

void MainWindow::openDialog() {
    QString filePath = QFileDialog::getOpenFileName(this, tr("Open File"));
    if (!filePath.isEmpty()) editor->openFile(filePath);
}
