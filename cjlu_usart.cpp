#include "cjlu_usart.h"
#include "ui_cjlu_usart.h"

cjlu_usart::cjlu_usart(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::cjlu_usart)
{
    ui->setupUi(this);
    // USER
    system_init();
}

cjlu_usart::~cjlu_usart()
{
    delete ui;
}

/*------------------------------------------
*      funtion
*-------------------------------------------*/
void cjlu_usart::system_init()
{
    //串口 初始化
    //数据检验位 数据位
    global_port.setStopBits(QSerialPort::OneStop);
    global_port.setParity(QSerialPort::NoParity);
    global_port.setDataBits(QSerialPort::Data8);

    //connect
    connect(ui->Button_Open,&QPushButton::clicked,this,&cjlu_usart::Button_Open_Port);
    connect(ui->Button_Close,&QPushButton::clicked,this,&cjlu_usart::Button_Close_Port);
    connect(ui->Button_Send,&QPushButton::clicked,this,&cjlu_usart::Button_Send_Port);
    connect(&global_port,&QSerialPort::readyRead,this,&Receive_Data);

}

/* -----------------------------------------
*      slots
*-------------------------------------------*/
void cjlu_usart::Button_Open_Port(bool)
{
    /*-------------port name-------------*/
//    qDebug()<< "chenggong"; //测试槽触发运行没
    switch (ui->COM_Port_Name->currentIndex()) {
    case 0:
        global_port.setPortName("COM1");
        break;
    case 1:
        global_port.setPortName("COM2");
        break;
    case 2:
        global_port.setPortName("COM3");
        break;
    case 3:
        global_port.setPortName("COM4");
        break;
    case 4:
        global_port.setPortName("COM5");
        break;
    case 5:
        global_port.setPortName("COM6");
        break;
    case 6:
        global_port.setPortName("COM7");
        break;
    case 7:
        global_port.setPortName("COM8");
        break;
    case 8:
        global_port.setPortName("COM9");
        break;

    default:
        global_port.setPortName("COM10");
        break;
    }
   /*--------------buod rate-----------*/
    switch (ui->COM_Baud_Rate->currentIndex()) {
    case 0:
        //setBaudRate的使用
        global_port.setBaudRate(QSerialPort::Baud1200);
        break;
    case 1:
        global_port.setBaudRate(QSerialPort::Baud2400);
        break;
    case 2:
        global_port.setBaudRate(QSerialPort::Baud4800);
        break;
    case 3:
        global_port.setBaudRate(QSerialPort::Baud9600);
        break;
    case 4:
        global_port.setBaudRate(QSerialPort::Baud19200);
        break;
    case 5:
        global_port.setBaudRate(QSerialPort::Baud38400);
        break;
    case 6:
        global_port.setBaudRate(QSerialPort::Baud57600);
        break;

    default:
        global_port.setBaudRate(QSerialPort::Baud115200);
        break;
    }
    /*--------------open port----------------*/
    global_port.open(QIODevice::ReadWrite);

    /*--------------port test----------------*/
    //global_port.write("11");
    /*--------------port state---------------*/
    ui->label_state->setText("串口已打开");

}
void cjlu_usart::Button_Close_Port(bool)
{
    ui->label_state->setText("串口未开启");
    global_port.close();

}

void cjlu_usart::Button_Send_Port(bool)
{
   QString x = ui->Write_Line->text();
   QByteArray array = x.toLatin1(); //QString 转为QByteArray;
   global_port.write(array);
}


void cjlu_usart::Receive_Data()
{
   QByteArray y= global_port.readAll();
   if(ui->Check_Send->checkState() == Qt::Checked)
   {
       ui->Receive_Data->insertPlainText(QString(y.toHex(' ')).toUpper().append(' '));
   }
   else
   {
       ui->Receive_Data->insertPlainText(QString(y));
   }

}

