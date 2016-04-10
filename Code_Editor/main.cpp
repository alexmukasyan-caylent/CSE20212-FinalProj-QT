#include <QtWidgets>

#include "codeeditor.h"
#include "syntaxhighlighter.h"
#include "ui_codeeditor.h"

int main(int argv, char **args){ 
    QApplication app(argv, args);
    QMainWindow *window = new QMainWindow;
    CodeEditor editor(window);
    SyntaxHighlighter highlighter(editor.document());
    Ui::codeeditor ui;
    ui.setupUi(window);
    window -> setCentralWidget(&editor);

    editor.setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    //editor.setFixedSize(window -> width(),window -> height() );
    window -> setWindowTitle(QObject::tr("Galeanthropy"));
    window -> show();

    return app.exec();
}
