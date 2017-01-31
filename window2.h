#ifndef WINDOW2_H
#define WINDOW2_H

#include <QWidget>
#include <QSlider>
#include <QPushButton>
#include <QImage>
#include <QLabel>
#include <QMainWindow>

/*class MainWindow: public QWidget
{
    Q_OBJECT
public:
    explicit Window();
private slots:
    void create_image();
private:
    QImage *plot;
};
*/

class Window2 : public QWidget
{
Q_OBJECT

public:
Window2(QWidget *parent=0);

private slots:
//    void create_image();
//    void changewin();
//    void
private:
//QLabel *textEdit;
QPushButton *Button1;
};

#endif // WINDOW2_H
