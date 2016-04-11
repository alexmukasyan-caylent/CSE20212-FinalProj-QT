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
#include "ui_codeeditor.h"
//void loadFile(const QString &filePath){
//    QFile file(filePath);

//    if (!file.open(QFile::ReadOnly)) {
//        QMessageBox::warning(this, tr("Recent Files Example"),
//                             tr("This file could not be found:\n%1.")
//                             .arg(filePath));
//        return;
//    }

//    QPixmap pMap(filePath);
//    if (pMap.isNull()) {
//        QMessageBox::information(this, tr("Recent Files Example"),
//                      tr("Cannot load:\n%1.")
//                      .arg(filePath));
//        return;
//    }

//    imageLabel->setPixmap(pMap);
//    imageLabel->setAlignment(Qt::AlignCenter);
//    adjustForCurrentFile(filePath);
//}

//void open(){
//    QString filePath = QFileDialog::getOpenFileName(
//                       this, tr("Open File"), "",
//                       tr("Images (*.png *.xpm *.jpg *.gif)"));
//        if (!filePath.isEmpty())
//            loadFile(filePath);
//}

int main(int argv, char **args){ 
    QApplication app(argv, args);
    QMainWindow *window = new QMainWindow;
    CodeEditor editor(window);
    SyntaxHighlighter highlighter(editor.document());
    Ui::codeeditor ui;
    ui.setupUi(window);
    window -> setCentralWidget(&editor);
    ui.actionQuit -> connect(ui.actionQuit, SIGNAL(triggered()), window, SLOT(close()));
    ui.actionCopy -> connect(ui.actionCopy, SIGNAL(triggered()), &editor, SLOT(copy()));
    ui.actionCut -> connect(ui.actionCut, SIGNAL(triggered()), &editor, SLOT(cut()));
    ui.actionPaste -> connect(ui.actionPaste, SIGNAL(triggered()), &editor, SLOT(paste()));
    //ui.actionQuit -> connect(ui.actionQuit, SIGNAL(triggered()), &editor, SLOT(selectAll()));
    ui.actionUndo -> connect(ui.actionUndo, SIGNAL(triggered()), &editor, SLOT(undo()));
    ui.actionRedo -> QObject::connect(ui.actionRedo, SIGNAL(triggered()), &editor, SLOT(redo()));
    ui.actionOpen -> connect(ui.actionOpen, SIGNAL(triggered()), window, SLOT(open()));

    editor.setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    window -> setWindowTitle(QObject::tr("Galeanthropy"));
    window -> show();

    return app.exec();
}
