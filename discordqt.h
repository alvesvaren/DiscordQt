#ifndef DISCORDQT_H
#define DISCORDQT_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class DiscordQt; }
QT_END_NAMESPACE

class DiscordQt : public QMainWindow
{
    Q_OBJECT

public:
    DiscordQt(QWidget *parent = nullptr);
    ~DiscordQt();

private:
    Ui::DiscordQt *ui;
};
#endif // DISCORDQT_H
