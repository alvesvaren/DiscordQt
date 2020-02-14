
#include "login.h"
#include "logindialog.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginDialog loginForm;
    // w.show();
    loginForm.show();
    return a.exec();
}
