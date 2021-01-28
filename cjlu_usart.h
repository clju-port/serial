#ifndef CJLU_USART_H
#define CJLU_USART_H

#include <QMainWindow>

/*------------user------------*/
//port
#include <QSerialPort>
//debug
#include <QDebug>
//Time
#include <QTimer>
#include <QTime>
/*------------------------*/
namespace Ui {
class cjlu_usart;
}

class cjlu_usart : public QMainWindow
{
    Q_OBJECT

public:
    explicit cjlu_usart(QWidget *parent = 0);
    ~cjlu_usart();

private slots:
    void Button_Close_Port(bool);
    void Button_Open_Port(bool);
    void Button_Send_Port(bool);
    void Receive_Data();
    void Time_Show();
private:
    Ui::cjlu_usart *ui;
    /*-------------Funtion--------------------------*/
    void system_init();
    /*-------------Voriable-------------------------*/
    QSerialPort global_port;

};

#endif // CJLU_USART_H
