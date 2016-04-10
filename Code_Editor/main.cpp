#include <QtWidgets>

#include "codeeditor.h"
#include "syntaxhighlighter.h"


int main(int argv, char **args)
{
    QApplication app(argv, args);

    CodeEditor editor;
    SyntaxHighlighter highlighter(editor.document());
    editor.setWindowTitle(QObject::tr("Galeanthropy"));
    editor.show();

    return app.exec();
}
