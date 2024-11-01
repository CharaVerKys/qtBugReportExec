#include <QApplication>
#include <QMessageBox>
#include <QPushButton>
#include <QDebug>
#include <qmessagebox.h>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    QMessageBox confirmBox(QMessageBox::Warning, "onExit", "confirm");

    confirmBox.addButton("exit", QMessageBox::AcceptRole);
    confirmBox.addButton("cancel", QMessageBox::RejectRole);

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
//////////////////////////////////////
charaverk@laptop:~/Documents/build$ /home/charaverk/Documents/build/BugReport
QMessageBox::AcceptRole 
 QMessageBox::RejectRole // before add cast to int

2 //qt6.8 (after delete build dir)
//////////////////////////////////////
charaverk@laptop:~/Documents/build$ /home/charaverk/Documents/build/BugReport
0 
 1 

2 //qt6.8


 */
/*
qt6.4 x11 ubuntu


16:50:06: Starting /home/charaverk/Documents/build-qtBugReportExec-qt6_4-Debug/BugReport...
0
 1

0
16:50:09: /home/charaverk/Documents/build-qtBugReportExec-qt6_4-Debug/BugReport exited with code 0

16:52:25: Starting /home/charaverk/Documents/build-qtBugReportExec-qt6_4-Debug/BugReport...
0
 1

1
16:52:26: /home/charaverk/Documents/build-qtBugReportExec-qt6_4-Debug/BugReport exited with code 0

will test with 6.8 if resolve other dependency error
*/
