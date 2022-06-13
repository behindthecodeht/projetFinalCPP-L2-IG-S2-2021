#ifndef CARD_H
#define CARD_H

#include <QWidget>
#include <QPushButton>
#include <QObject>
#include <QVBoxLayout>
#include <QLabel>
#include <QPixmap>

class Card : public QWidget
{
    Q_OBJECT

private:
    QVBoxLayout *cardLayout;

    int w, h;

    QLabel *thumbnail;
    QLabel *title;
    QLabel *status;

    QPixmap *image;

    QPushButton *readMore;

public:
    explicit Card(QWidget * parent = nullptr);
    ~Card();
};

#endif // CARD_H
