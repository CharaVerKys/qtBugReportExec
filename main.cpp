#include <QApplication>
#include <QMessageBox>
#include <QPushButton>
#include <QDebug>
#include <qmessagebox.h>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    QMessageBox confirmBox(QMessageBox::Warning, "onExit", "confirm");
    confirmBox.setObjectName("confirmBox");

    QPushButton *btnOk = confirmBox.addButton("exit", QMessageBox::AcceptRole);
    btnOk->setObjectName("btnMessageOK");

    QPushButton *btnNo = confirmBox.addButton("cancel", QMessageBox::RejectRole);
    btnNo->setObjectName("btnMessageNO");

qDebug() << (int)QMessageBox::ButtonRole::AcceptRole << "\n"<<
            (int)QMessageBox::ButtonRole::RejectRole << "\n"; // on 6.8 qDebug support enum output :)

    qDebug() << confirmBox.exec();
    


    return 0;
}

/*
output:
charaverk@laptop:~/Documents/build$ /home/charaverk/Documents/build/BugReport
0 
 1 

0 //qt6.4
charaverk@laptop:~/Documents/build$ /home/charaverk/Documents/build/BugReport
QMessageBox::AcceptRole 
 QMessageBox::RejectRole // before add cast to int

2 //qt6.8 (after delete build dir)
charaverk@laptop:~/Documents/build$ /home/charaverk/Documents/build/BugReport
0 
 1 

2 //qt6.8


 */