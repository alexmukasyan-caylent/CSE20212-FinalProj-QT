#ifndef SYNTAXHIGHLIGHTER_H
#define SYNTAXHIGHLIGHTER_H

#include <QSyntaxHighlighter>

class CTextSyntaxHighlighter : public QSyntaxHighlighter
{
    Q_OBJECT

public:
    CTextSyntaxHighlighter(QTextDocument *parent = 0);
private:
    void highlightBlock(const QString &text);
};

#endif // SYNTAXHIGHLIGHTER_H
